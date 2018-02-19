/*
 * Realtek Semiconductor Corp.
 *
 * rts_camera_soc_regs.h
 *
 * Copyright (C) 2014      Ming Qian<ming_qian@realsil.com.cn>
 */
#ifndef _RTS_CAMERA_SOC_REGS_H
#define _RTS_CAMERA_SOC_REGS_H

/* register address */
#define		RTS_REG_DATA_HOST_TO_MCU_BASE			0x00000000
#define		RTS_REG_DATA0_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*0)
#define		RTS_REG_DATA1_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*1)
#define		RTS_REG_DATA2_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*2)
#define		RTS_REG_DATA3_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*3)
#define		RTS_REG_DATA4_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*4)
#define		RTS_REG_DATA5_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*5)
#define		RTS_REG_DATA6_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*6)
#define		RTS_REG_DATA7_HOST_TO_MCU			(RTS_REG_DATA_HOST_TO_MCU_BASE+4*7)
#define		RTS_REG_DATA_MCU_TO_HOST_BASE			0x00000020
#define		RTS_REG_DATA0_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*0)
#define		RTS_REG_DATA1_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*1)
#define		RTS_REG_DATA2_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*2)
#define		RTS_REG_DATA3_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*3)
#define		RTS_REG_DATA4_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*4)
#define		RTS_REG_DATA5_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*5)
#define		RTS_REG_DATA6_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*6)
#define		RTS_REG_DATA7_MCU_TO_HOST			(RTS_REG_DATA_MCU_TO_HOST_BASE+4*7)
#define		RTS_REG_CMD_HOST_TO_MCU_BASE			0x00000040
#define		RTS_REG_CMD0_HOST_TO_MCU			(RTS_REG_CMD_HOST_TO_MCU_BASE+4*0)
#define		RTS_REG_CMD1_HOST_TO_MCU			(RTS_REG_CMD_HOST_TO_MCU_BASE+4*1)
#define		RTS_REG_MCU_CMD_STATUS				0x00000048

#define		RTS_REG_ISP_IMAGE_BASE				0x00000100
#define		RTS_REG_YUV_FRAME_Y_START_ADDRESS_BASE		RTS_REG_ISP_IMAGE_BASE
#define		RTS_REG_YUV_FRAME_UV_START_ADDRESS_BASE		(RTS_REG_ISP_IMAGE_BASE+0x00000080)
#define		RTS_REG_MJPEG_FRAME_BUFFER_START_ADDRESS_BASE	(RTS_REG_ISP_IMAGE_BASE+0x00000110)
#define		RTS_REG_MJPEG_FRAME_BUFFER_LENGTH		(RTS_REG_ISP_IMAGE_BASE+0x00000130)
#define		RTS_REG_YUV_FRAME_OVERFLOW_COUNT		(RTS_REG_ISP_IMAGE_BASE+0x00000158)
#define		RTS_REG_MJPEG_FRAME_OVERFLOW_COUNT		(RTS_REG_ISP_IMAGE_BASE+0x0000015C)
#define		RTS_REG_FRAME_BUFFER_COUNT			(RTS_REG_ISP_IMAGE_BASE+0x00000160)
#define		RTS_REG_ISP_CONTROL				(RTS_REG_ISP_IMAGE_BASE+0x00000164)
#define		RTS_REG_YUV_ISP_BUF_CONFIG_BASE			(RTS_REG_ISP_IMAGE_BASE+0x0000016C)
#define		RTS_REG_YUV_ISP_Y_BUF_CONFIG_S0			(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*0)
#define		RTS_REG_YUV_ISP_UV_BUF_CONFIG_S0		(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*1)
#define		RTS_REG_YUV_ISP_Y_BUF_CONFIG_S1			(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*2)
#define		RTS_REG_YUV_ISP_UV_BUF_CONFIG_S1		(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*3)
#define		RTS_REG_YUV_ISP_Y_BUF_CONFIG_S2			(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*4)
#define		RTS_REG_YUV_ISP_UV_BUF_CONFIG_S2		(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*5)
#define		RTS_REG_YUV_ISP_Y_BUF_CONFIG_S3			(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*6)
#define		RTS_REG_YUV_ISP_UV_BUF_CONFIG_S3		(RTS_REG_YUV_ISP_BUF_CONFIG_BASE+4*7)
#define		RTS_REG_MJPEG_ISP_BUF_CONFIG			(RTS_REG_ISP_IMAGE_BASE+0x0000018C)
#define		RTS_REG_TD_ISP_BUF_CONFIG			(RTS_REG_ISP_IMAGE_BASE+0x00000190)
#define		RTS_REG_STREAM_FRAME_INTERVAL_CONFIG		(RTS_REG_ISP_IMAGE_BASE+0x00000198)
#define		RTS_REG_PTS_VALUE_CONFIG			(RTS_REG_ISP_IMAGE_BASE+0x000001A0)
#define		RTS_REG_YUV_FRAME_BUFFER_STATUS_BASE		(RTS_REG_ISP_IMAGE_BASE+0x000001A4)
#define		RTS_REG_MJPEG_STREAM_FRAME_BUFFER_STATUS	(RTS_REG_ISP_IMAGE_BASE+0x000001B4)
#define		RTS_REG_TD_BUFFER_START_ADDRESS			(RTS_REG_ISP_IMAGE_BASE+0x000001B8)
#define		RTS_REG_TD_BUFFER_LENGTH			(RTS_REG_ISP_IMAGE_BASE+0x000001BC)
#define		RTS_REG_YUV_Cur_Frame_Index_Offset		(RTS_REG_ISP_IMAGE_BASE+0x000001C0)
#define		RTS_REG_MJPEG_Cur_Frame_Index			(RTS_REG_ISP_IMAGE_BASE+0x000001D0)
#define		RTS_REG_YUV_ISP_Y_BUFFER_OVERFLOW_COUNT		(RTS_REG_ISP_IMAGE_BASE+0x000001D4)
#define		RTS_REG_YUV_ISP_UV_BUFFER_OVERFLOW_COUNT	(RTS_REG_ISP_IMAGE_BASE+0x000001D8)
#define		RTS_REG_MJPEG_TD_ISP_BUFFER_OVERFLOW_COUNT	(RTS_REG_ISP_IMAGE_BASE+0x000001DC)
#define		RTS_REG_MJPEG_FRAME_RECVED_LENGTH		(RTS_REG_ISP_IMAGE_BASE+0x000001E0)
#define 	RTS_REG_LDC_MAP_TABLE_START			(RTS_REG_ISP_IMAGE_BASE+0x000001E0)
#define 	RTS_REG_LDC_MAP_TABLE_SIZE			(RTS_REG_ISP_IMAGE_BASE+0x000001E4)
#define		RTS_REG_ISP_HEADER_ADDR				(RTS_REG_ISP_IMAGE_BASE+0x000001F0)
#define		RTS_REG_ISP_OCP_IF_DUMMY			(RTS_REG_ISP_IMAGE_BASE+0x00000200)

#define		RTS_REG_SPI_BASE				0x00000400
#define		RTS_REG_MCU_SPI_BASE_ADDR			RTS_REG_SPI_BASE
#define		RTS_REG_CPU_LOCK_MCU				(RTS_REG_SPI_BASE+0x00000004)

#define		RTS_REG_ISP_INT_BASE				0x00000500
#define		RTS_REG_INT_EN_MCU_TO_HOST			RTS_REG_ISP_INT_BASE
#define		RTS_REG_INT_EN_ISP_TO_HOST			(RTS_REG_ISP_INT_BASE+0x00000004)
#define		RTS_REG_INT_FLAG_MCU_TO_HOST			(RTS_REG_ISP_INT_BASE+0x00000008)
#define		RTS_REG_INT_FLAG_ISP_HOST			(RTS_REG_ISP_INT_BASE+0x0000000C)

#endif