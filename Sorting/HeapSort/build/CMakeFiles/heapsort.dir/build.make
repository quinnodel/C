# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/quinnodel/Documents/Code/C/Sorting/HeapSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quinnodel/Documents/Code/C/Sorting/HeapSort/build

# Include any dependencies generated for this target.
include CMakeFiles/heapsort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/heapsort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/heapsort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/heapsort.dir/flags.make

CMakeFiles/heapsort.dir/src/heapsort.c.o: CMakeFiles/heapsort.dir/flags.make
CMakeFiles/heapsort.dir/src/heapsort.c.o: ../src/heapsort.c
CMakeFiles/heapsort.dir/src/heapsort.c.o: CMakeFiles/heapsort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quinnodel/Documents/Code/C/Sorting/HeapSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/heapsort.dir/src/heapsort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/heapsort.dir/src/heapsort.c.o -MF CMakeFiles/heapsort.dir/src/heapsort.c.o.d -o CMakeFiles/heapsort.dir/src/heapsort.c.o -c /home/quinnodel/Documents/Code/C/Sorting/HeapSort/src/heapsort.c

CMakeFiles/heapsort.dir/src/heapsort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heapsort.dir/src/heapsort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/quinnodel/Documents/Code/C/Sorting/HeapSort/src/heapsort.c > CMakeFiles/heapsort.dir/src/heapsort.c.i

CMakeFiles/heapsort.dir/src/heapsort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heapsort.dir/src/heapsort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/quinnodel/Documents/Code/C/Sorting/HeapSort/src/heapsort.c -o CMakeFiles/heapsort.dir/src/heapsort.c.s

# Object files for target heapsort
heapsort_OBJECTS = \
"CMakeFiles/heapsort.dir/src/heapsort.c.o"

# External object files for target heapsort
heapsort_EXTERNAL_OBJECTS =

heapsort: CMakeFiles/heapsort.dir/src/heapsort.c.o
heapsort: CMakeFiles/heapsort.dir/build.make
heapsort: CMakeFiles/heapsort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quinnodel/Documents/Code/C/Sorting/HeapSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable heapsort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heapsort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/heapsort.dir/build: heapsort
.PHONY : CMakeFiles/heapsort.dir/build

CMakeFiles/heapsort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/heapsort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/heapsort.dir/clean

CMakeFiles/heapsort.dir/depend:
	cd /home/quinnodel/Documents/Code/C/Sorting/HeapSort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quinnodel/Documents/Code/C/Sorting/HeapSort /home/quinnodel/Documents/Code/C/Sorting/HeapSort /home/quinnodel/Documents/Code/C/Sorting/HeapSort/build /home/quinnodel/Documents/Code/C/Sorting/HeapSort/build /home/quinnodel/Documents/Code/C/Sorting/HeapSort/build/CMakeFiles/heapsort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/heapsort.dir/depend

