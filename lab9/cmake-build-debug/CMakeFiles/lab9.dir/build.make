# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/study/politech/2kurs/cm/lab9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab9.dir/flags.make

CMakeFiles/lab9.dir/main.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab9.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/main.cpp.o -c /Users/mac/study/politech/2kurs/cm/lab9/main.cpp

CMakeFiles/lab9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/study/politech/2kurs/cm/lab9/main.cpp > CMakeFiles/lab9.dir/main.cpp.i

CMakeFiles/lab9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/study/politech/2kurs/cm/lab9/main.cpp -o CMakeFiles/lab9.dir/main.cpp.s

CMakeFiles/lab9.dir/functions.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab9.dir/functions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/functions.cpp.o -c /Users/mac/study/politech/2kurs/cm/lab9/functions.cpp

CMakeFiles/lab9.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/functions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/study/politech/2kurs/cm/lab9/functions.cpp > CMakeFiles/lab9.dir/functions.cpp.i

CMakeFiles/lab9.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/functions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/study/politech/2kurs/cm/lab9/functions.cpp -o CMakeFiles/lab9.dir/functions.cpp.s

# Object files for target lab9
lab9_OBJECTS = \
"CMakeFiles/lab9.dir/main.cpp.o" \
"CMakeFiles/lab9.dir/functions.cpp.o"

# External object files for target lab9
lab9_EXTERNAL_OBJECTS =

lab9: CMakeFiles/lab9.dir/main.cpp.o
lab9: CMakeFiles/lab9.dir/functions.cpp.o
lab9: CMakeFiles/lab9.dir/build.make
lab9: CMakeFiles/lab9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab9.dir/build: lab9

.PHONY : CMakeFiles/lab9.dir/build

CMakeFiles/lab9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab9.dir/clean

CMakeFiles/lab9.dir/depend:
	cd /Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/study/politech/2kurs/cm/lab9 /Users/mac/study/politech/2kurs/cm/lab9 /Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug /Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug /Users/mac/study/politech/2kurs/cm/lab9/cmake-build-debug/CMakeFiles/lab9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab9.dir/depend

