# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/wilhelm/Downloads/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/wilhelm/Downloads/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wilhelm/CLionProjects/Labor_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wilhelm/CLionProjects/Labor_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labor_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Labor_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labor_2.dir/flags.make

CMakeFiles/Labor_2.dir/main.c.o: CMakeFiles/Labor_2.dir/flags.make
CMakeFiles/Labor_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wilhelm/CLionProjects/Labor_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Labor_2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Labor_2.dir/main.c.o   -c /home/wilhelm/CLionProjects/Labor_2/main.c

CMakeFiles/Labor_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Labor_2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wilhelm/CLionProjects/Labor_2/main.c > CMakeFiles/Labor_2.dir/main.c.i

CMakeFiles/Labor_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Labor_2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wilhelm/CLionProjects/Labor_2/main.c -o CMakeFiles/Labor_2.dir/main.c.s

CMakeFiles/Labor_2.dir/main.c.o.requires:

.PHONY : CMakeFiles/Labor_2.dir/main.c.o.requires

CMakeFiles/Labor_2.dir/main.c.o.provides: CMakeFiles/Labor_2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Labor_2.dir/build.make CMakeFiles/Labor_2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Labor_2.dir/main.c.o.provides

CMakeFiles/Labor_2.dir/main.c.o.provides.build: CMakeFiles/Labor_2.dir/main.c.o


# Object files for target Labor_2
Labor_2_OBJECTS = \
"CMakeFiles/Labor_2.dir/main.c.o"

# External object files for target Labor_2
Labor_2_EXTERNAL_OBJECTS =

Labor_2: CMakeFiles/Labor_2.dir/main.c.o
Labor_2: CMakeFiles/Labor_2.dir/build.make
Labor_2: CMakeFiles/Labor_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wilhelm/CLionProjects/Labor_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Labor_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Labor_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labor_2.dir/build: Labor_2

.PHONY : CMakeFiles/Labor_2.dir/build

CMakeFiles/Labor_2.dir/requires: CMakeFiles/Labor_2.dir/main.c.o.requires

.PHONY : CMakeFiles/Labor_2.dir/requires

CMakeFiles/Labor_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Labor_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Labor_2.dir/clean

CMakeFiles/Labor_2.dir/depend:
	cd /home/wilhelm/CLionProjects/Labor_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wilhelm/CLionProjects/Labor_2 /home/wilhelm/CLionProjects/Labor_2 /home/wilhelm/CLionProjects/Labor_2/cmake-build-debug /home/wilhelm/CLionProjects/Labor_2/cmake-build-debug /home/wilhelm/CLionProjects/Labor_2/cmake-build-debug/CMakeFiles/Labor_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labor_2.dir/depend

