# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiffy/CLionProjects/reversePolish

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiffy/CLionProjects/reversePolish/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/reversePolish.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/reversePolish.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reversePolish.dir/flags.make

CMakeFiles/reversePolish.dir/main.cpp.o: CMakeFiles/reversePolish.dir/flags.make
CMakeFiles/reversePolish.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiffy/CLionProjects/reversePolish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reversePolish.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reversePolish.dir/main.cpp.o -c /Users/jiffy/CLionProjects/reversePolish/main.cpp

CMakeFiles/reversePolish.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reversePolish.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiffy/CLionProjects/reversePolish/main.cpp > CMakeFiles/reversePolish.dir/main.cpp.i

CMakeFiles/reversePolish.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reversePolish.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiffy/CLionProjects/reversePolish/main.cpp -o CMakeFiles/reversePolish.dir/main.cpp.s

# Object files for target reversePolish
reversePolish_OBJECTS = \
"CMakeFiles/reversePolish.dir/main.cpp.o"

# External object files for target reversePolish
reversePolish_EXTERNAL_OBJECTS =

reversePolish: CMakeFiles/reversePolish.dir/main.cpp.o
reversePolish: CMakeFiles/reversePolish.dir/build.make
reversePolish: CMakeFiles/reversePolish.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiffy/CLionProjects/reversePolish/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reversePolish"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reversePolish.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reversePolish.dir/build: reversePolish
.PHONY : CMakeFiles/reversePolish.dir/build

CMakeFiles/reversePolish.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reversePolish.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reversePolish.dir/clean

CMakeFiles/reversePolish.dir/depend:
	cd /Users/jiffy/CLionProjects/reversePolish/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiffy/CLionProjects/reversePolish /Users/jiffy/CLionProjects/reversePolish /Users/jiffy/CLionProjects/reversePolish/cmake-build-debug /Users/jiffy/CLionProjects/reversePolish/cmake-build-debug /Users/jiffy/CLionProjects/reversePolish/cmake-build-debug/CMakeFiles/reversePolish.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reversePolish.dir/depend

