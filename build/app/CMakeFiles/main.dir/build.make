# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build

# Include any dependencies generated for this target.
include app/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/main.dir/flags.make

app/CMakeFiles/main.dir/src/main.cpp.obj: app/CMakeFiles/main.dir/flags.make
app/CMakeFiles/main.dir/src/main.cpp.obj: app/CMakeFiles/main.dir/includes_CXX.rsp
app/CMakeFiles/main.dir/src/main.cpp.obj: ../app/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/main.dir/src/main.cpp.obj"
	cd /d C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\main.cpp.obj -c C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\app\src\main.cpp

app/CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	cd /d C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\app\src\main.cpp > CMakeFiles\main.dir\src\main.cpp.i

app/CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	cd /d C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\app\src\main.cpp -o CMakeFiles\main.dir\src\main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

app/main.exe: app/CMakeFiles/main.dir/src/main.cpp.obj
app/main.exe: app/CMakeFiles/main.dir/build.make
app/main.exe: HuffmanCompression/libhuffmancompression.a
app/main.exe: app/CMakeFiles/main.dir/linklibs.rsp
app/main.exe: app/CMakeFiles/main.dir/objects1.rsp
app/main.exe: app/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main.exe"
	cd /d C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/main.dir/build: app/main.exe

.PHONY : app/CMakeFiles/main.dir/build

app/CMakeFiles/main.dir/clean:
	cd /d C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app && $(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : app/CMakeFiles/main.dir/clean

app/CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\app C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app C:\Users\curro.LAPTOP-DUBBS74R\OneDrive\Documentos\Programming\C++\FileCompressor\build\app\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/main.dir/depend

