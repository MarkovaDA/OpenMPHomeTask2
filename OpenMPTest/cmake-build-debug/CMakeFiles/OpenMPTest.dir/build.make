# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/darya/Загрузки/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/darya/Загрузки/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darya/CLionProjects/OpenMPTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darya/CLionProjects/OpenMPTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenMPTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenMPTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenMPTest.dir/flags.make

CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o: CMakeFiles/OpenMPTest.dir/flags.make
CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o: ../parallel_v2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darya/CLionProjects/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o -c /home/darya/CLionProjects/OpenMPTest/parallel_v2.cpp

CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darya/CLionProjects/OpenMPTest/parallel_v2.cpp > CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.i

CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darya/CLionProjects/OpenMPTest/parallel_v2.cpp -o CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.s

CMakeFiles/OpenMPTest.dir/helpers.cpp.o: CMakeFiles/OpenMPTest.dir/flags.make
CMakeFiles/OpenMPTest.dir/helpers.cpp.o: ../helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/darya/CLionProjects/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenMPTest.dir/helpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenMPTest.dir/helpers.cpp.o -c /home/darya/CLionProjects/OpenMPTest/helpers.cpp

CMakeFiles/OpenMPTest.dir/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenMPTest.dir/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darya/CLionProjects/OpenMPTest/helpers.cpp > CMakeFiles/OpenMPTest.dir/helpers.cpp.i

CMakeFiles/OpenMPTest.dir/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenMPTest.dir/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darya/CLionProjects/OpenMPTest/helpers.cpp -o CMakeFiles/OpenMPTest.dir/helpers.cpp.s

# Object files for target OpenMPTest
OpenMPTest_OBJECTS = \
"CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o" \
"CMakeFiles/OpenMPTest.dir/helpers.cpp.o"

# External object files for target OpenMPTest
OpenMPTest_EXTERNAL_OBJECTS =

OpenMPTest: CMakeFiles/OpenMPTest.dir/parallel_v2.cpp.o
OpenMPTest: CMakeFiles/OpenMPTest.dir/helpers.cpp.o
OpenMPTest: CMakeFiles/OpenMPTest.dir/build.make
OpenMPTest: CMakeFiles/OpenMPTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/darya/CLionProjects/OpenMPTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenMPTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenMPTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenMPTest.dir/build: OpenMPTest

.PHONY : CMakeFiles/OpenMPTest.dir/build

CMakeFiles/OpenMPTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenMPTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenMPTest.dir/clean

CMakeFiles/OpenMPTest.dir/depend:
	cd /home/darya/CLionProjects/OpenMPTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darya/CLionProjects/OpenMPTest /home/darya/CLionProjects/OpenMPTest /home/darya/CLionProjects/OpenMPTest/cmake-build-debug /home/darya/CLionProjects/OpenMPTest/cmake-build-debug /home/darya/CLionProjects/OpenMPTest/cmake-build-debug/CMakeFiles/OpenMPTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenMPTest.dir/depend

