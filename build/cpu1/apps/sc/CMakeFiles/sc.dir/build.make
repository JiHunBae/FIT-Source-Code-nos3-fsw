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
include apps/sc/CMakeFiles/sc.dir/depend.make

# Include the progress variables for this target.
include apps/sc/CMakeFiles/sc.dir/progress.make

# Include the compile flags for this target's objects.
include apps/sc/CMakeFiles/sc.dir/flags.make

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_app.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_app.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_app.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_app.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_app.c > CMakeFiles/sc.dir/fsw/src/sc_app.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_app.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_app.c -o CMakeFiles/sc.dir/fsw/src/sc_app.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_atsrq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_atsrq.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_atsrq.c > CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_atsrq.c -o CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_cmds.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_cmds.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_cmds.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_cmds.c > CMakeFiles/sc.dir/fsw/src/sc_cmds.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_cmds.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_cmds.c -o CMakeFiles/sc.dir/fsw/src/sc_cmds.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_loads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_loads.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_loads.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_loads.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_loads.c > CMakeFiles/sc.dir/fsw/src/sc_loads.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_loads.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_loads.c -o CMakeFiles/sc.dir/fsw/src/sc_loads.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_rtsrq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_rtsrq.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_rtsrq.c > CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_rtsrq.c -o CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_state.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_state.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_state.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_state.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_state.c > CMakeFiles/sc.dir/fsw/src/sc_state.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_state.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_state.c -o CMakeFiles/sc.dir/fsw/src/sc_state.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o


apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o: apps/sc/CMakeFiles/sc.dir/flags.make
apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o: /media/sf_nos3/fsw/apps/sc/fsw/src/sc_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sc.dir/fsw/src/sc_utils.c.o   -c /media/sf_nos3/fsw/apps/sc/fsw/src/sc_utils.c

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sc.dir/fsw/src/sc_utils.c.i"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sf_nos3/fsw/apps/sc/fsw/src/sc_utils.c > CMakeFiles/sc.dir/fsw/src/sc_utils.c.i

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sc.dir/fsw/src/sc_utils.c.s"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sf_nos3/fsw/apps/sc/fsw/src/sc_utils.c -o CMakeFiles/sc.dir/fsw/src/sc_utils.c.s

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.requires:

.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.requires

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.provides: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.requires
	$(MAKE) -f apps/sc/CMakeFiles/sc.dir/build.make apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.provides.build
.PHONY : apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.provides

apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.provides.build: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o


# Object files for target sc
sc_OBJECTS = \
"CMakeFiles/sc.dir/fsw/src/sc_app.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_loads.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_state.c.o" \
"CMakeFiles/sc.dir/fsw/src/sc_utils.c.o"

# External object files for target sc
sc_EXTERNAL_OBJECTS =

apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/build.make
apps/sc/sc.so: apps/sc/CMakeFiles/sc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C shared module sc.so"
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/sc/CMakeFiles/sc.dir/build: apps/sc/sc.so

.PHONY : apps/sc/CMakeFiles/sc.dir/build

apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_app.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_atsrq.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_cmds.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_loads.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_rtsrq.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_state.c.o.requires
apps/sc/CMakeFiles/sc.dir/requires: apps/sc/CMakeFiles/sc.dir/fsw/src/sc_utils.c.o.requires

.PHONY : apps/sc/CMakeFiles/sc.dir/requires

apps/sc/CMakeFiles/sc.dir/clean:
	cd /media/sf_nos3/fsw/build/cpu1/apps/sc && $(CMAKE_COMMAND) -P CMakeFiles/sc.dir/cmake_clean.cmake
.PHONY : apps/sc/CMakeFiles/sc.dir/clean

apps/sc/CMakeFiles/sc.dir/depend:
	cd /media/sf_nos3/fsw/build/cpu1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_nos3/fsw/cfe /media/sf_nos3/fsw/apps/sc /media/sf_nos3/fsw/build/cpu1 /media/sf_nos3/fsw/build/cpu1/apps/sc /media/sf_nos3/fsw/build/cpu1/apps/sc/CMakeFiles/sc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/sc/CMakeFiles/sc.dir/depend

