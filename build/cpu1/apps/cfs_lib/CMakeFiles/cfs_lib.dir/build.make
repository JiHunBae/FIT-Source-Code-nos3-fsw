# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /media/sf_nos3/fsw/cfe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_nos3/fsw/build/cpu1

# Include any dependencies generated for this target.
include apps/cfs_lib/CMakeFiles/cfs_lib.dir/depend.make

# Include the progress variables for this target.
include apps/cfs_lib/CMakeFiles/cfs_lib.dir/progress.make

# Include the compile flags for this target's objects.
include apps/cfs_lib/CMakeFiles/cfs_lib.dir/flags.make

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o: apps/cfs_lib/CMakeFiles/cfs_lib.dir/flags.make
apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o: /media/sf_nos3/fsw/apps/cfs_lib/fsw/src/cfs_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o   -c /media/sf_nos3/fsw/apps/cfs_lib/fsw/src/cfs_utils.c

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/cfs_lib/fsw/src/cfs_utils.c > CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.i

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/cfs_lib/fsw/src/cfs_utils.c -o CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.s

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.requires:

.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.requires

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.provides: apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.requires
	$(MAKE) -f apps/cfs_lib/CMakeFiles/cfs_lib.dir/build.make apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.provides.build
.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.provides

apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.provides.build: apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o


# Object files for target cfs_lib
cfs_lib_OBJECTS = \
"CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o"

# External object files for target cfs_lib
cfs_lib_EXTERNAL_OBJECTS =

apps/cfs_lib/cfs_lib.so: apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o
apps/cfs_lib/cfs_lib.so: apps/cfs_lib/CMakeFiles/cfs_lib.dir/build.make
apps/cfs_lib/cfs_lib.so: apps/cfs_lib/CMakeFiles/cfs_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared module cfs_lib.so"
	cd /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cfs_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/cfs_lib/CMakeFiles/cfs_lib.dir/build: apps/cfs_lib/cfs_lib.so

.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/build

apps/cfs_lib/CMakeFiles/cfs_lib.dir/requires: apps/cfs_lib/CMakeFiles/cfs_lib.dir/fsw/src/cfs_utils.c.o.requires

.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/requires

apps/cfs_lib/CMakeFiles/cfs_lib.dir/clean:
	cd /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib && $(CMAKE_COMMAND) -P CMakeFiles/cfs_lib.dir/cmake_clean.cmake
.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/clean

apps/cfs_lib/CMakeFiles/cfs_lib.dir/depend:
	cd /media/sf_nos3/fsw/build/cpu1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_nos3/fsw/cfe /media/sf_nos3/fsw/apps/cfs_lib /media/sf_nos3/fsw/build/cpu1 /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib /media/sf_nos3/fsw/build/cpu1/apps/cfs_lib/CMakeFiles/cfs_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/cfs_lib/CMakeFiles/cfs_lib.dir/depend

