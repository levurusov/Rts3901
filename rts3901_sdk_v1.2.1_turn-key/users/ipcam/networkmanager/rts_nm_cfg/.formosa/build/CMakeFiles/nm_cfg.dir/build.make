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
CMAKE_SOURCE_DIR = /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build

# Include any dependencies generated for this target.
include CMakeFiles/nm_cfg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nm_cfg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nm_cfg.dir/flags.make

CMakeFiles/nm_cfg.dir/nm_cfg.c.o: CMakeFiles/nm_cfg.dir/flags.make
CMakeFiles/nm_cfg.dir/nm_cfg.c.o: ../../nm_cfg.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/nm_cfg.dir/nm_cfg.c.o"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/nm_cfg.dir/nm_cfg.c.o   -c /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/nm_cfg.c

CMakeFiles/nm_cfg.dir/nm_cfg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm_cfg.dir/nm_cfg.c.i"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/nm_cfg.c > CMakeFiles/nm_cfg.dir/nm_cfg.c.i

CMakeFiles/nm_cfg.dir/nm_cfg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm_cfg.dir/nm_cfg.c.s"
	/home/tony_nie/ipcam/4dpocket/release/.build/build/toolchain/rsdk-4.8.5-5281-EL-3.10-u0.9.33-m32ut-160408/bin/rsdk-linux-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/nm_cfg.c -o CMakeFiles/nm_cfg.dir/nm_cfg.c.s

CMakeFiles/nm_cfg.dir/nm_cfg.c.o.requires:
.PHONY : CMakeFiles/nm_cfg.dir/nm_cfg.c.o.requires

CMakeFiles/nm_cfg.dir/nm_cfg.c.o.provides: CMakeFiles/nm_cfg.dir/nm_cfg.c.o.requires
	$(MAKE) -f CMakeFiles/nm_cfg.dir/build.make CMakeFiles/nm_cfg.dir/nm_cfg.c.o.provides.build
.PHONY : CMakeFiles/nm_cfg.dir/nm_cfg.c.o.provides

CMakeFiles/nm_cfg.dir/nm_cfg.c.o.provides.build: CMakeFiles/nm_cfg.dir/nm_cfg.c.o

# Object files for target nm_cfg
nm_cfg_OBJECTS = \
"CMakeFiles/nm_cfg.dir/nm_cfg.c.o"

# External object files for target nm_cfg
nm_cfg_EXTERNAL_OBJECTS =

nm_cfg: CMakeFiles/nm_cfg.dir/nm_cfg.c.o
nm_cfg: CMakeFiles/nm_cfg.dir/build.make
nm_cfg: CMakeFiles/nm_cfg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable nm_cfg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nm_cfg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nm_cfg.dir/build: nm_cfg
.PHONY : CMakeFiles/nm_cfg.dir/build

CMakeFiles/nm_cfg.dir/requires: CMakeFiles/nm_cfg.dir/nm_cfg.c.o.requires
.PHONY : CMakeFiles/nm_cfg.dir/requires

CMakeFiles/nm_cfg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nm_cfg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nm_cfg.dir/clean

CMakeFiles/nm_cfg.dir/depend:
	cd /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build /home/tony_nie/ipcam/4dpocket/release/.build/build/users/ipcam/networkmanager/rts_nm_cfg/.formosa/build/CMakeFiles/nm_cfg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nm_cfg.dir/depend
