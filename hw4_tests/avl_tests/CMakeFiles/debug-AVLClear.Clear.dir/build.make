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

# Utility rule file for debug-AVLClear.Clear.

# Include the progress variables for this target.
include avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/progress.make

avl_tests/CMakeFiles/debug-AVLClear.Clear:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/homework/hw4/hw4_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging AVLClear.Clear with GDB..."
	cd /work/homework/hw4 && gdb --args /work/homework/hw4/hw4_tests/avl_tests/avl_tests --gtest_filter=AVLClear.Clear

debug-AVLClear.Clear: avl_tests/CMakeFiles/debug-AVLClear.Clear
debug-AVLClear.Clear: avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/build.make

.PHONY : debug-AVLClear.Clear

# Rule to build all files generated by this target.
avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/build: debug-AVLClear.Clear

.PHONY : avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/build

avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/clean:
	cd /work/homework/hw4/hw4_tests/avl_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-AVLClear.Clear.dir/cmake_clean.cmake
.PHONY : avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/clean

avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/depend:
	cd /work/homework/hw4/hw4_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/homework/hw4/hw4_tests /work/homework/hw4/hw4_tests/avl_tests /work/homework/hw4/hw4_tests /work/homework/hw4/hw4_tests/avl_tests /work/homework/hw4/hw4_tests/avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : avl_tests/CMakeFiles/debug-AVLClear.Clear.dir/depend

