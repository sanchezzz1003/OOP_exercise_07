# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/alexander/Рабочий стол/OOP/ex_07"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alexander/Рабочий стол/OOP/ex_07/build"

# Include any dependencies generated for this target.
include CMakeFiles/oop_exercise_07.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oop_exercise_07.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oop_exercise_07.dir/flags.make

CMakeFiles/oop_exercise_07.dir/main.cpp.o: CMakeFiles/oop_exercise_07.dir/flags.make
CMakeFiles/oop_exercise_07.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexander/Рабочий стол/OOP/ex_07/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oop_exercise_07.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oop_exercise_07.dir/main.cpp.o -c "/home/alexander/Рабочий стол/OOP/ex_07/main.cpp"

CMakeFiles/oop_exercise_07.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oop_exercise_07.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexander/Рабочий стол/OOP/ex_07/main.cpp" > CMakeFiles/oop_exercise_07.dir/main.cpp.i

CMakeFiles/oop_exercise_07.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oop_exercise_07.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexander/Рабочий стол/OOP/ex_07/main.cpp" -o CMakeFiles/oop_exercise_07.dir/main.cpp.s

CMakeFiles/oop_exercise_07.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/oop_exercise_07.dir/main.cpp.o.requires

CMakeFiles/oop_exercise_07.dir/main.cpp.o.provides: CMakeFiles/oop_exercise_07.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/oop_exercise_07.dir/build.make CMakeFiles/oop_exercise_07.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/oop_exercise_07.dir/main.cpp.o.provides

CMakeFiles/oop_exercise_07.dir/main.cpp.o.provides.build: CMakeFiles/oop_exercise_07.dir/main.cpp.o


# Object files for target oop_exercise_07
oop_exercise_07_OBJECTS = \
"CMakeFiles/oop_exercise_07.dir/main.cpp.o"

# External object files for target oop_exercise_07
oop_exercise_07_EXTERNAL_OBJECTS =

oop_exercise_07: CMakeFiles/oop_exercise_07.dir/main.cpp.o
oop_exercise_07: CMakeFiles/oop_exercise_07.dir/build.make
oop_exercise_07: CMakeFiles/oop_exercise_07.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alexander/Рабочий стол/OOP/ex_07/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oop_exercise_07"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oop_exercise_07.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oop_exercise_07.dir/build: oop_exercise_07

.PHONY : CMakeFiles/oop_exercise_07.dir/build

CMakeFiles/oop_exercise_07.dir/requires: CMakeFiles/oop_exercise_07.dir/main.cpp.o.requires

.PHONY : CMakeFiles/oop_exercise_07.dir/requires

CMakeFiles/oop_exercise_07.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oop_exercise_07.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oop_exercise_07.dir/clean

CMakeFiles/oop_exercise_07.dir/depend:
	cd "/home/alexander/Рабочий стол/OOP/ex_07/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alexander/Рабочий стол/OOP/ex_07" "/home/alexander/Рабочий стол/OOP/ex_07" "/home/alexander/Рабочий стол/OOP/ex_07/build" "/home/alexander/Рабочий стол/OOP/ex_07/build" "/home/alexander/Рабочий стол/OOP/ex_07/build/CMakeFiles/oop_exercise_07.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/oop_exercise_07.dir/depend

