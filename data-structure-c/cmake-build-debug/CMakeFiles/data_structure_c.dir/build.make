# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/tools/jetbrains/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/tools/jetbrains/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/CLionProjects/struct/data-structure-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CLionProjects/struct/data-structure-c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data_structure_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_structure_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_structure_c.dir/flags.make

CMakeFiles/data_structure_c.dir/main.c.o: CMakeFiles/data_structure_c.dir/flags.make
CMakeFiles/data_structure_c.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/struct/data-structure-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/data_structure_c.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure_c.dir/main.c.o   -c /root/CLionProjects/struct/data-structure-c/main.c

CMakeFiles/data_structure_c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure_c.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/CLionProjects/struct/data-structure-c/main.c > CMakeFiles/data_structure_c.dir/main.c.i

CMakeFiles/data_structure_c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure_c.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/CLionProjects/struct/data-structure-c/main.c -o CMakeFiles/data_structure_c.dir/main.c.s

CMakeFiles/data_structure_c.dir/main.c.o.requires:

.PHONY : CMakeFiles/data_structure_c.dir/main.c.o.requires

CMakeFiles/data_structure_c.dir/main.c.o.provides: CMakeFiles/data_structure_c.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/data_structure_c.dir/build.make CMakeFiles/data_structure_c.dir/main.c.o.provides.build
.PHONY : CMakeFiles/data_structure_c.dir/main.c.o.provides

CMakeFiles/data_structure_c.dir/main.c.o.provides.build: CMakeFiles/data_structure_c.dir/main.c.o


CMakeFiles/data_structure_c.dir/tree/Tree.c.o: CMakeFiles/data_structure_c.dir/flags.make
CMakeFiles/data_structure_c.dir/tree/Tree.c.o: ../tree/Tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/struct/data-structure-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/data_structure_c.dir/tree/Tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure_c.dir/tree/Tree.c.o   -c /root/CLionProjects/struct/data-structure-c/tree/Tree.c

CMakeFiles/data_structure_c.dir/tree/Tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure_c.dir/tree/Tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/CLionProjects/struct/data-structure-c/tree/Tree.c > CMakeFiles/data_structure_c.dir/tree/Tree.c.i

CMakeFiles/data_structure_c.dir/tree/Tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure_c.dir/tree/Tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/CLionProjects/struct/data-structure-c/tree/Tree.c -o CMakeFiles/data_structure_c.dir/tree/Tree.c.s

CMakeFiles/data_structure_c.dir/tree/Tree.c.o.requires:

.PHONY : CMakeFiles/data_structure_c.dir/tree/Tree.c.o.requires

CMakeFiles/data_structure_c.dir/tree/Tree.c.o.provides: CMakeFiles/data_structure_c.dir/tree/Tree.c.o.requires
	$(MAKE) -f CMakeFiles/data_structure_c.dir/build.make CMakeFiles/data_structure_c.dir/tree/Tree.c.o.provides.build
.PHONY : CMakeFiles/data_structure_c.dir/tree/Tree.c.o.provides

CMakeFiles/data_structure_c.dir/tree/Tree.c.o.provides.build: CMakeFiles/data_structure_c.dir/tree/Tree.c.o


# Object files for target data_structure_c
data_structure_c_OBJECTS = \
"CMakeFiles/data_structure_c.dir/main.c.o" \
"CMakeFiles/data_structure_c.dir/tree/Tree.c.o"

# External object files for target data_structure_c
data_structure_c_EXTERNAL_OBJECTS =

data_structure_c: CMakeFiles/data_structure_c.dir/main.c.o
data_structure_c: CMakeFiles/data_structure_c.dir/tree/Tree.c.o
data_structure_c: CMakeFiles/data_structure_c.dir/build.make
data_structure_c: CMakeFiles/data_structure_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/CLionProjects/struct/data-structure-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable data_structure_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structure_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_structure_c.dir/build: data_structure_c

.PHONY : CMakeFiles/data_structure_c.dir/build

CMakeFiles/data_structure_c.dir/requires: CMakeFiles/data_structure_c.dir/main.c.o.requires
CMakeFiles/data_structure_c.dir/requires: CMakeFiles/data_structure_c.dir/tree/Tree.c.o.requires

.PHONY : CMakeFiles/data_structure_c.dir/requires

CMakeFiles/data_structure_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_structure_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_structure_c.dir/clean

CMakeFiles/data_structure_c.dir/depend:
	cd /root/CLionProjects/struct/data-structure-c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CLionProjects/struct/data-structure-c /root/CLionProjects/struct/data-structure-c /root/CLionProjects/struct/data-structure-c/cmake-build-debug /root/CLionProjects/struct/data-structure-c/cmake-build-debug /root/CLionProjects/struct/data-structure-c/cmake-build-debug/CMakeFiles/data_structure_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_structure_c.dir/depend

