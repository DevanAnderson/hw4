# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /work/homework/hw4/hw4_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/homework/hw4/hw4_tests

# Include any dependencies generated for this target.
include equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/depend.make

# Include the progress variables for this target.
include equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/progress.make

# Include the compile flags for this target's objects.
include equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/flags.make

equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o: equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/flags.make
equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o: /work/homework/hw4/equal-paths.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/homework/hw4/hw4_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o"
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o -c /work/homework/hw4/equal-paths.cpp

equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.i"
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/homework/hw4/equal-paths.cpp > CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.i

equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.s"
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/homework/hw4/equal-paths.cpp -o CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.s

# Object files for target hw4_equalpaths
hw4_equalpaths_OBJECTS = \
"CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o"

# External object files for target hw4_equalpaths
hw4_equalpaths_EXTERNAL_OBJECTS =

equalpaths_tests/libhw4_equalpaths.a: equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/work/homework/hw4/equal-paths.cpp.o
equalpaths_tests/libhw4_equalpaths.a: equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/build.make
equalpaths_tests/libhw4_equalpaths.a: equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/homework/hw4/hw4_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhw4_equalpaths.a"
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw4_equalpaths.dir/cmake_clean_target.cmake
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4_equalpaths.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/build: equalpaths_tests/libhw4_equalpaths.a

.PHONY : equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/build

equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/clean:
	cd /work/homework/hw4/hw4_tests/equalpaths_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw4_equalpaths.dir/cmake_clean.cmake
.PHONY : equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/clean

equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/depend:
	cd /work/homework/hw4/hw4_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/homework/hw4/hw4_tests /work/homework/hw4/hw4_tests/equalpaths_tests /work/homework/hw4/hw4_tests /work/homework/hw4/hw4_tests/equalpaths_tests /work/homework/hw4/hw4_tests/equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : equalpaths_tests/CMakeFiles/hw4_equalpaths.dir/depend

