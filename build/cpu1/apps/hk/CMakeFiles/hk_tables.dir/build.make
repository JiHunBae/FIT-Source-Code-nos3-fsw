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

# Utility rule file for hk_tables.

# Include the progress variables for this target.
include apps/hk/CMakeFiles/hk_tables.dir/progress.make

apps/hk/CMakeFiles/hk_tables: apps/hk/tables_cpu1/hk_cpy_tbl.tbl


apps/hk/tables_cpu1/hk_cpy_tbl.tbl: /media/sf_nos3/fsw/build/tools/elf2cfetbl/elf2cfetbl
apps/hk/tables_cpu1/hk_cpy_tbl.tbl: /media/sf_nos3/fsw/nos3_defs/tables/hk_cpy_tbl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/media/sf_nos3/fsw/build/cpu1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating tables_cpu1/hk_cpy_tbl.tbl"
	cd /media/sf_nos3/fsw/build/cpu1/apps/hk/tables_cpu1 && /usr/bin/gcc -Wall -m32 -D_XOPEN_SOURCE=600 -DBYTE_ORDER_LE -D_LINUX_OS_ -D_LINUX_OS_ -I/media/sf_nos3/fsw/build/inc -I/media/sf_nos3/fsw/build/cpu1/inc -I/media/sf_nos3/fsw/osal/src/os/inc -I/media/sf_nos3/fsw/psp/fsw/inc -I/media/sf_nos3/fsw/cfe/fsw/cfe-core/src/inc -I/media/sf_nos3/fsw/cfe/cmake/target/inc -I/media/sf_nos3/fsw/build/cpu1/cfe_core_default_cpu1/inc -I/media/sf_nos3/fsw/apps/hk/fsw/public_inc -I/media/sf_nos3/fsw/apps/hk/fsw/mission_inc -I/media/sf_nos3/fsw/apps/hk/fsw/platform_inc -I/media/sf_nos3/fsw/apps/hk/fsw/src -c -o hk_cpy_tbl.o /media/sf_nos3/fsw/nos3_defs/tables/hk_cpy_tbl.c
	cd /media/sf_nos3/fsw/build/cpu1/apps/hk/tables_cpu1 && /media/sf_nos3/fsw/build/tools/elf2cfetbl/elf2cfetbl hk_cpy_tbl.o

hk_tables: apps/hk/CMakeFiles/hk_tables
hk_tables: apps/hk/tables_cpu1/hk_cpy_tbl.tbl
hk_tables: apps/hk/CMakeFiles/hk_tables.dir/build.make

.PHONY : hk_tables

# Rule to build all files generated by this target.
apps/hk/CMakeFiles/hk_tables.dir/build: hk_tables

.PHONY : apps/hk/CMakeFiles/hk_tables.dir/build

apps/hk/CMakeFiles/hk_tables.dir/clean:
	cd /media/sf_nos3/fsw/build/cpu1/apps/hk && $(CMAKE_COMMAND) -P CMakeFiles/hk_tables.dir/cmake_clean.cmake
.PHONY : apps/hk/CMakeFiles/hk_tables.dir/clean

apps/hk/CMakeFiles/hk_tables.dir/depend:
	cd /media/sf_nos3/fsw/build/cpu1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_nos3/fsw/cfe /media/sf_nos3/fsw/apps/hk /media/sf_nos3/fsw/build/cpu1 /media/sf_nos3/fsw/build/cpu1/apps/hk /media/sf_nos3/fsw/build/cpu1/apps/hk/CMakeFiles/hk_tables.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/hk/CMakeFiles/hk_tables.dir/depend

