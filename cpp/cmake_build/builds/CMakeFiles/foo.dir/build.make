# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pigwanhun/Workspace/TIL/c++/cmake_build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds

# Include any dependencies generated for this target.
include CMakeFiles/foo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/foo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/foo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/foo.dir/flags.make

CMakeFiles/foo.dir/foo.cc.o: CMakeFiles/foo.dir/flags.make
CMakeFiles/foo.dir/foo.cc.o: ../foo.cc
CMakeFiles/foo.dir/foo.cc.o: CMakeFiles/foo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/foo.dir/foo.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/foo.dir/foo.cc.o -MF CMakeFiles/foo.dir/foo.cc.o.d -o CMakeFiles/foo.dir/foo.cc.o -c /Users/pigwanhun/Workspace/TIL/c++/cmake_build/foo.cc

CMakeFiles/foo.dir/foo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foo.dir/foo.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pigwanhun/Workspace/TIL/c++/cmake_build/foo.cc > CMakeFiles/foo.dir/foo.cc.i

CMakeFiles/foo.dir/foo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foo.dir/foo.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pigwanhun/Workspace/TIL/c++/cmake_build/foo.cc -o CMakeFiles/foo.dir/foo.cc.s

# Object files for target foo
foo_OBJECTS = \
"CMakeFiles/foo.dir/foo.cc.o"

# External object files for target foo
foo_EXTERNAL_OBJECTS =

foo: CMakeFiles/foo.dir/foo.cc.o
foo: CMakeFiles/foo.dir/build.make
foo: CMakeFiles/foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable foo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/foo.dir/build: foo
.PHONY : CMakeFiles/foo.dir/build

CMakeFiles/foo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/foo.dir/clean

CMakeFiles/foo.dir/depend:
	cd /Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pigwanhun/Workspace/TIL/c++/cmake_build /Users/pigwanhun/Workspace/TIL/c++/cmake_build /Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds /Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds /Users/pigwanhun/Workspace/TIL/c++/cmake_build/builds/CMakeFiles/foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/foo.dir/depend

