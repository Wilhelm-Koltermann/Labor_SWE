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
CMAKE_SOURCE_DIR = /home/wilhelm/CLionProjects/Labor_Nachhol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labor_Nachhol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Labor_Nachhol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labor_Nachhol.dir/flags.make

CMakeFiles/Labor_Nachhol.dir/main.c.o: CMakeFiles/Labor_Nachhol.dir/flags.make
CMakeFiles/Labor_Nachhol.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Labor_Nachhol.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Labor_Nachhol.dir/main.c.o   -c /home/wilhelm/CLionProjects/Labor_Nachhol/main.c

CMakeFiles/Labor_Nachhol.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Labor_Nachhol.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wilhelm/CLionProjects/Labor_Nachhol/main.c > CMakeFiles/Labor_Nachhol.dir/main.c.i

CMakeFiles/Labor_Nachhol.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Labor_Nachhol.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wilhelm/CLionProjects/Labor_Nachhol/main.c -o CMakeFiles/Labor_Nachhol.dir/main.c.s

CMakeFiles/Labor_Nachhol.dir/main.c.o.requires:

.PHONY : CMakeFiles/Labor_Nachhol.dir/main.c.o.requires

CMakeFiles/Labor_Nachhol.dir/main.c.o.provides: CMakeFiles/Labor_Nachhol.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Labor_Nachhol.dir/build.make CMakeFiles/Labor_Nachhol.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Labor_Nachhol.dir/main.c.o.provides

CMakeFiles/Labor_Nachhol.dir/main.c.o.provides.build: CMakeFiles/Labor_Nachhol.dir/main.c.o


# Object files for target Labor_Nachhol
Labor_Nachhol_OBJECTS = \
"CMakeFiles/Labor_Nachhol.dir/main.c.o"

# External object files for target Labor_Nachhol
Labor_Nachhol_EXTERNAL_OBJECTS =

Labor_Nachhol: CMakeFiles/Labor_Nachhol.dir/main.c.o
Labor_Nachhol: CMakeFiles/Labor_Nachhol.dir/build.make
Labor_Nachhol: CMakeFiles/Labor_Nachhol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Labor_Nachhol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Labor_Nachhol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labor_Nachhol.dir/build: Labor_Nachhol

.PHONY : CMakeFiles/Labor_Nachhol.dir/build

CMakeFiles/Labor_Nachhol.dir/requires: CMakeFiles/Labor_Nachhol.dir/main.c.o.requires

.PHONY : CMakeFiles/Labor_Nachhol.dir/requires

CMakeFiles/Labor_Nachhol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Labor_Nachhol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Labor_Nachhol.dir/clean

CMakeFiles/Labor_Nachhol.dir/depend:
	cd /home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wilhelm/CLionProjects/Labor_Nachhol /home/wilhelm/CLionProjects/Labor_Nachhol /home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug /home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug /home/wilhelm/CLionProjects/Labor_Nachhol/cmake-build-debug/CMakeFiles/Labor_Nachhol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labor_Nachhol.dir/depend
