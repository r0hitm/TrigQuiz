# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\rohit mehta\source\repos\TrigQuiz"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\rohit mehta\source\repos\TrigQuiz\build"

# Include any dependencies generated for this target.
include CMakeFiles/TrigQuiz.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrigQuiz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrigQuiz.dir/flags.make

CMakeFiles/TrigQuiz.dir/main.cpp.obj: CMakeFiles/TrigQuiz.dir/flags.make
CMakeFiles/TrigQuiz.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\rohit mehta\source\repos\TrigQuiz\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrigQuiz.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TrigQuiz.dir\main.cpp.obj -c "C:\Users\rohit mehta\source\repos\TrigQuiz\main.cpp"

CMakeFiles/TrigQuiz.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrigQuiz.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\rohit mehta\source\repos\TrigQuiz\main.cpp" > CMakeFiles\TrigQuiz.dir\main.cpp.i

CMakeFiles/TrigQuiz.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrigQuiz.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\rohit mehta\source\repos\TrigQuiz\main.cpp" -o CMakeFiles\TrigQuiz.dir\main.cpp.s

# Object files for target TrigQuiz
TrigQuiz_OBJECTS = \
"CMakeFiles/TrigQuiz.dir/main.cpp.obj"

# External object files for target TrigQuiz
TrigQuiz_EXTERNAL_OBJECTS =

TrigQuiz.exe: CMakeFiles/TrigQuiz.dir/main.cpp.obj
TrigQuiz.exe: CMakeFiles/TrigQuiz.dir/build.make
TrigQuiz.exe: CMakeFiles/TrigQuiz.dir/linklibs.rsp
TrigQuiz.exe: CMakeFiles/TrigQuiz.dir/objects1.rsp
TrigQuiz.exe: CMakeFiles/TrigQuiz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\rohit mehta\source\repos\TrigQuiz\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TrigQuiz.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TrigQuiz.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrigQuiz.dir/build: TrigQuiz.exe

.PHONY : CMakeFiles/TrigQuiz.dir/build

CMakeFiles/TrigQuiz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TrigQuiz.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TrigQuiz.dir/clean

CMakeFiles/TrigQuiz.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\rohit mehta\source\repos\TrigQuiz" "C:\Users\rohit mehta\source\repos\TrigQuiz" "C:\Users\rohit mehta\source\repos\TrigQuiz\build" "C:\Users\rohit mehta\source\repos\TrigQuiz\build" "C:\Users\rohit mehta\source\repos\TrigQuiz\build\CMakeFiles\TrigQuiz.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TrigQuiz.dir/depend
