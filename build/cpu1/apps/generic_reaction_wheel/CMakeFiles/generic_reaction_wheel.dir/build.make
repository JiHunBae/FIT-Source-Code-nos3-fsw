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
include apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/depend.make

# Include the progress variables for this target.
include apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/progress.make

# Include the compile flags for this target's objects.
include apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/flags.make

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/flags.make
apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o: /media/sf_nos3/fsw/components/generic_reaction_wheel/fsw/src/generic_reaction_wheel_app.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o   -c /media/sf_nos3/fsw/components/generic_reaction_wheel/fsw/src/generic_reaction_wheel_app.c

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/components/generic_reaction_wheel/fsw/src/generic_reaction_wheel_app.c > CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.i

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/components/generic_reaction_wheel/fsw/src/generic_reaction_wheel_app.c -o CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.s

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.requires:

.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.requires

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.provides: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.requires
	$(MAKE) -f apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/build.make apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.provides.build
.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.provides

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.provides.build: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o


# Object files for target generic_reaction_wheel
generic_reaction_wheel_OBJECTS = \
"CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o"

# External object files for target generic_reaction_wheel
generic_reaction_wheel_EXTERNAL_OBJECTS =

apps/generic_reaction_wheel/generic_reaction_wheel.so: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o
apps/generic_reaction_wheel/generic_reaction_wheel.so: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/build.make
apps/generic_reaction_wheel/generic_reaction_wheel.so: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared module generic_reaction_wheel.so"
	cd /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generic_reaction_wheel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/build: apps/generic_reaction_wheel/generic_reaction_wheel.so

.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/build

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/requires: apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/fsw/src/generic_reaction_wheel_app.c.o.requires

.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/requires

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/clean:
	cd /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel && $(CMAKE_COMMAND) -P CMakeFiles/generic_reaction_wheel.dir/cmake_clean.cmake
.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/clean

apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/depend:
	cd /media/sf_nos3/fsw/build/cpu1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_nos3/fsw/cfe /media/sf_nos3/fsw/components/generic_reaction_wheel /media/sf_nos3/fsw/build/cpu1 /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel /media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/generic_reaction_wheel/CMakeFiles/generic_reaction_wheel.dir/depend

