# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build

# Include any dependencies generated for this target.
include CMakeFiles/entropy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/entropy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/entropy.dir/flags.make

CMakeFiles/entropy.dir/entropy.c.o: CMakeFiles/entropy.dir/flags.make
CMakeFiles/entropy.dir/entropy.c.o: ../../entropy.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/entropy.dir/entropy.c.o"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/entropy.dir/entropy.c.o   -c /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/entropy.c

CMakeFiles/entropy.dir/entropy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/entropy.dir/entropy.c.i"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/entropy.c > CMakeFiles/entropy.dir/entropy.c.i

CMakeFiles/entropy.dir/entropy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/entropy.dir/entropy.c.s"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/entropy.c -o CMakeFiles/entropy.dir/entropy.c.s

CMakeFiles/entropy.dir/entropy.c.o.requires:
.PHONY : CMakeFiles/entropy.dir/entropy.c.o.requires

CMakeFiles/entropy.dir/entropy.c.o.provides: CMakeFiles/entropy.dir/entropy.c.o.requires
	$(MAKE) -f CMakeFiles/entropy.dir/build.make CMakeFiles/entropy.dir/entropy.c.o.provides.build
.PHONY : CMakeFiles/entropy.dir/entropy.c.o.provides

CMakeFiles/entropy.dir/entropy.c.o.provides.build: CMakeFiles/entropy.dir/entropy.c.o

CMakeFiles/entropy.dir/utils.c.o: CMakeFiles/entropy.dir/flags.make
CMakeFiles/entropy.dir/utils.c.o: ../../utils.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/entropy.dir/utils.c.o"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/entropy.dir/utils.c.o   -c /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/utils.c

CMakeFiles/entropy.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/entropy.dir/utils.c.i"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/utils.c > CMakeFiles/entropy.dir/utils.c.i

CMakeFiles/entropy.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/entropy.dir/utils.c.s"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/utils.c -o CMakeFiles/entropy.dir/utils.c.s

CMakeFiles/entropy.dir/utils.c.o.requires:
.PHONY : CMakeFiles/entropy.dir/utils.c.o.requires

CMakeFiles/entropy.dir/utils.c.o.provides: CMakeFiles/entropy.dir/utils.c.o.requires
	$(MAKE) -f CMakeFiles/entropy.dir/build.make CMakeFiles/entropy.dir/utils.c.o.provides.build
.PHONY : CMakeFiles/entropy.dir/utils.c.o.provides

CMakeFiles/entropy.dir/utils.c.o.provides.build: CMakeFiles/entropy.dir/utils.c.o

# Object files for target entropy
entropy_OBJECTS = \
"CMakeFiles/entropy.dir/entropy.c.o" \
"CMakeFiles/entropy.dir/utils.c.o"

# External object files for target entropy
entropy_EXTERNAL_OBJECTS =

entropy: CMakeFiles/entropy.dir/entropy.c.o
entropy: CMakeFiles/entropy.dir/utils.c.o
entropy: CMakeFiles/entropy.dir/build.make
entropy: CMakeFiles/entropy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable entropy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/entropy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/entropy.dir/build: entropy
.PHONY : CMakeFiles/entropy.dir/build

CMakeFiles/entropy.dir/requires: CMakeFiles/entropy.dir/entropy.c.o.requires
CMakeFiles/entropy.dir/requires: CMakeFiles/entropy.dir/utils.c.o.requires
.PHONY : CMakeFiles/entropy.dir/requires

CMakeFiles/entropy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/entropy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/entropy.dir/clean

CMakeFiles/entropy.dir/depend:
	cd /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/libsysconf/.formosa/build/CMakeFiles/entropy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/entropy.dir/depend
