# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ElectronicVote

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ElectronicVote\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ElectronicVote.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ElectronicVote.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ElectronicVote.dir/flags.make

CMakeFiles/ElectronicVote.dir/main.cpp.obj: CMakeFiles/ElectronicVote.dir/flags.make
CMakeFiles/ElectronicVote.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ElectronicVote\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ElectronicVote.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ElectronicVote.dir\main.cpp.obj -c D:\ElectronicVote\main.cpp

CMakeFiles/ElectronicVote.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElectronicVote.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ElectronicVote\main.cpp > CMakeFiles\ElectronicVote.dir\main.cpp.i

CMakeFiles/ElectronicVote.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElectronicVote.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ElectronicVote\main.cpp -o CMakeFiles\ElectronicVote.dir\main.cpp.s

# Object files for target ElectronicVote
ElectronicVote_OBJECTS = \
"CMakeFiles/ElectronicVote.dir/main.cpp.obj"

# External object files for target ElectronicVote
ElectronicVote_EXTERNAL_OBJECTS =

ElectronicVote.exe: CMakeFiles/ElectronicVote.dir/main.cpp.obj
ElectronicVote.exe: CMakeFiles/ElectronicVote.dir/build.make
ElectronicVote.exe: CMakeFiles/ElectronicVote.dir/linklibs.rsp
ElectronicVote.exe: CMakeFiles/ElectronicVote.dir/objects1.rsp
ElectronicVote.exe: CMakeFiles/ElectronicVote.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ElectronicVote\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ElectronicVote.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ElectronicVote.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ElectronicVote.dir/build: ElectronicVote.exe
.PHONY : CMakeFiles/ElectronicVote.dir/build

CMakeFiles/ElectronicVote.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ElectronicVote.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ElectronicVote.dir/clean

CMakeFiles/ElectronicVote.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ElectronicVote D:\ElectronicVote D:\ElectronicVote\cmake-build-debug D:\ElectronicVote\cmake-build-debug D:\ElectronicVote\cmake-build-debug\CMakeFiles\ElectronicVote.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ElectronicVote.dir/depend

