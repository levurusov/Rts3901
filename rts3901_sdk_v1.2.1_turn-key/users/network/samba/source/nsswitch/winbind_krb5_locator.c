/*
   Unix SMB/CIFS implementation.
   kerberos locator plugin
   Copyright (C) Guenther Deschner 2007

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "nsswitch/winbind_client.h"

#ifndef DEBUG_KRB5
#undef DEBUG_KRB5
#endif

#if defined(HAVE_KRB5) && defined(HAVE_KRB5_LOCATE_PLUGIN_H)

#include <krb5/locate_plugin.h>

#ifndef KRB5_PLUGIN_NO_HANDLE
#define KRB5_PLUGIN_NO_HANDLE KRB5_KDC_UNREACH /* Heimdal */
#endif

static const char *get_service_from_locate_service_type(enum locate_service_type svc)
{
	switch (svc) {
		case locate_service_kdc:
		case locate_service_master_kdc:
			return "88";
		case locate_service_kadmin:
		case locate_service_krb524:
			/* not supported */
			return NULL;
		case locate_service_kpasswd:
			return "464";
		default:
			break;
	}
	return NULL;

}

#ifdef DEBUG_KRB5
static const char *locate_service_type_name(enum locate_service_type svc)
{
	switch (svc) {
		case locate_service_kdc:
			return "locate_service_kdc";
		case locate_service_master_kdc:
			return "locate_service_master_kdc";
		case locate_service_kadmin:
			return "locate_service_kadmin";
		case locate_service_krb524:
			return "locate_service_krb524";
		case locate_service_kpasswd:
			return "locate_service_kpasswd";
		default:
			break;
	}
	return NULL;
}

static const char *socktype_name(int socktype)
{
	switch (socktype) {
		case SOCK_STREAM:
			return "SOCK_STREAM";
		case SOCK_DGRAM:
			return "SOCK_DGRAM";
		default:
			break;
	}
	return "unknown";
}

static const char *family_name(int family)
{
	switch (family) {
		case AF_UNSPEC:
			return "AF_UNSPEC";
		case AF_INET:
			return "AF_INET";
#if defined(HAVE_IPV6)
		case AF_INET6:
			return "AF_INET6";
#endif
		default:
			break;
	}
	return "unknown";
}
#endif

/**
 * Check input parameters, return KRB5_PLUGIN_NO_HANDLE for unsupported ones
 *
 * @param svc
 * @param realm string
 * @param socktype integer
 * @param family integer
 *
 * @return integer.
 */

static int smb_krb5_locator_lookup_sanity_check(enum locate_service_type svc,
						const char *realm,
						int socktype,
						int family)
{
	if (!realm || strlen(realm) == 0) {
		return EINVAL;
	}

	switch (svc) {
		case locate_service_kdc:
		case locate_service_master_kdc:
		case locate_service_kpasswd:
			break;
		case locate_service_kadmin:
		case locate_service_krb524:
			return KRB5_PLUGIN_NO_HANDLE;
		default:
			return EINVAL;
	}

	switch (family) {
		case AF_UNSPEC:
		case AF_INET:
			break;
#if defined(HAVE_IPV6)
		case AF_INET6:
			break;
#endif
		default:
			return EINVAL;
	}

	switch (socktype) {
		case SOCK_STREAM:
		case SOCK_DGRAM:
		case 0: /* Heimdal uses that */
			break;
		default:
			return EINVAL;
	}

	return 0;
}

/**
 * Try to get addrinfo for a given host and call the krb5 callback
 *
 * @param name string
 * @param service string
 * @param in struct addrinfo hint
 * @param cbfunc krb5 callback function
 * @param cbdata void pointer cbdata
 *
 * @return krb5_error_code.
 */

static krb5_error_code smb_krb5_locator_call_cbfunc(const char *name,
						    const char *service,
						    struct addrinfo *in,
						    int (*cbfunc)(void *, int, struct sockaddr *),
						    void *cbdata)
{
	struct addrinfo *out = NULL;
	int ret;
	int count = 3;

	while (count) {

		ret = getaddrinfo(name, service, in, &out);
		if (ret == 0) {
			break;
		}

		if (ret == EAI_AGAIN) {
			count--;
			continue;
		}

#ifdef DEBUG_KRB5
		fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
			"getaddrinfo failed: %s (%d)\n",
			(unsigned int)getpid(), gai_strerror(ret), ret);
#endif

		return KRB5_PLUGIN_NO_HANDLE;
	}

	ret = cbfunc(cbdata, out->ai_socktype, out->ai_addr);
#ifdef DEBUG_KRB5
	if (ret) {
		fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
			"failed to call callback: %s (%d)\n",
			(unsigned int)getpid(), error_message(ret), ret);
	}
#endif

	freeaddrinfo(out);
	return ret;
}

/**
 * PUBLIC INTERFACE: locate init
 *
 * @param context krb5_context
 * @param privata_data pointer to private data pointer
 *
 * @return krb5_error_code.
 */

krb5_error_code smb_krb5_locator_init(krb5_context context,
				      void **private_data)
{
	return 0;
}

/**
 * PUBLIC INTERFACE: close locate
 *
 * @param private_data pointer to private data
 *
 * @return void.
 */

void smb_krb5_locator_close(void *private_data)
{
	return;
}


static bool ask_winbind(const char *realm, char **dcname)
{
	NSS_STATUS status;
	struct winbindd_request request;
	struct winbindd_response response;

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	request.flags = 0x40020600;
			/* DS_KDC_REQUIRED |
			DS_IS_DNS_NAME |
			DS_RETURN_DNS_NAME |
			DS_IP_REQUIRED */

	strncpy(request.domain_name, realm,
		sizeof(request.domain_name)-1);

	status = winbindd_request_response(WINBINDD_DSGETDCNAME,
					   &request, &response);
	if (status != NSS_STATUS_SUCCESS) {
#ifdef DEBUG_KRB5
		fprintf(stderr,"[%5u]: smb_krb5_locator_lookup: failed with: %s\n",
			(unsigned int)getpid(), nss_err_str(status));
#endif
		return false;
	}

	*dcname = strdup(response.data.dc_name);
	if (!*dcname) {
		return false;
	}

	return true;
}

/**
 * PUBLIC INTERFACE: locate lookup
 *
 * @param private_data pointer to private data
 * @param svc enum locate_service_type.
 * @param realm string
 * @param socktype integer
 * @param family integer
 * @param cbfunc callback function to send back entries
 * @param cbdata void pointer to cbdata
 *
 * @return krb5_error_code.
 */

krb5_error_code smb_krb5_locator_lookup(void *private_data,
					enum locate_service_type svc,
					const char *realm,
					int socktype,
					int family,
					int (*cbfunc)(void *, int, struct sockaddr *),
					void *cbdata)
{
	krb5_error_code ret;
	struct addrinfo aihints;
	char *kdc_name = NULL;
	const char *service = get_service_from_locate_service_type(svc);

	ZERO_STRUCT(aihints);

#ifdef DEBUG_KRB5
	fprintf(stderr,"[%5u]: smb_krb5_locator_lookup: called for '%s' "
			"svc: '%s' (%d) "
			"socktype: '%s' (%d), family: '%s' (%d)\n",
			(unsigned int)getpid(), realm,
			locate_service_type_name(svc), svc,
			socktype_name(socktype), socktype,
		        family_name(family), family);
#endif
	ret = smb_krb5_locator_lookup_sanity_check(svc, realm, socktype,
						   family);
	if (ret) {
#ifdef DEBUG_KRB5
		fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
			"returning ret: %s (%d)\n",
			(unsigned int)getpid(), error_message(ret), ret);
#endif
		return ret;
	}

	if (!winbind_env_set()) {
		if (!ask_winbind(realm, &kdc_name)) {
#ifdef DEBUG_KRB5
			fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
				"failed to query winbindd\n",
				(unsigned int)getpid());
#endif
			goto failed;
		}
	} else {
		const char *env = NULL;
		char *var = NULL;
		if (asprintf(&var, "%s_%s",
			     WINBINDD_LOCATOR_KDC_ADDRESS, realm) == -1) {
			goto failed;
		}
		env = getenv(var);
		if (!env) {
#ifdef DEBUG_KRB5
			fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
				"failed to get kdc from env %s\n",
				(unsigned int)getpid(), var);
#endif
			free(var);
			goto failed;
		}
		free(var);

		kdc_name = strdup(env);
		if (!kdc_name) {
			goto failed;
		}
	}
#ifdef DEBUG_KRB5
	fprintf(stderr, "[%5u]: smb_krb5_locator_lookup: "
		"got '%s' for '%s' from winbindd\n", (unsigned int)getpid(),
		kdc_name, realm);
#endif

	aihints.ai_family = family;
	aihints.ai_socktype = socktype;

	ret = smb_krb5_locator_call_cbfunc(kdc_name,
					   service,
					   &aihints,
					   cbfunc, cbdata);
	SAFE_FREE(kdc_name);

	return ret;

 failed:
	return KRB5_PLUGIN_NO_HANDLE;
}

#ifdef HEIMDAL_KRB5_LOCATE_PLUGIN_H
#define SMB_KRB5_LOCATOR_SYMBOL_NAME resolve /* Heimdal */
#else
#define SMB_KRB5_LOCATOR_SYMBOL_NAME service_locator /* MIT */
#endif

const krb5plugin_service_locate_ftable SMB_KRB5_LOCATOR_SYMBOL_NAME = {
	0, /* version */
	smb_krb5_locator_init,
	smb_krb5_locator_close,
	smb_krb5_locator_lookup,
};

#endif
