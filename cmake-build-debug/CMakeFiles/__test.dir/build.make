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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/__test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/__test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/__test.dir/flags.make

CMakeFiles/__test.dir/src/tsp_setup.cpp.obj: CMakeFiles/__test.dir/flags.make
CMakeFiles/__test.dir/src/tsp_setup.cpp.obj: CMakeFiles/__test.dir/includes_CXX.rsp
CMakeFiles/__test.dir/src/tsp_setup.cpp.obj: ../src/tsp_setup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/__test.dir/src/tsp_setup.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\__test.dir\src\tsp_setup.cpp.obj -c C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\tsp_setup.cpp

CMakeFiles/__test.dir/src/tsp_setup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/__test.dir/src/tsp_setup.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\tsp_setup.cpp > CMakeFiles\__test.dir\src\tsp_setup.cpp.i

CMakeFiles/__test.dir/src/tsp_setup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/__test.dir/src/tsp_setup.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\tsp_setup.cpp -o CMakeFiles\__test.dir\src\tsp_setup.cpp.s

CMakeFiles/__test.dir/src/TSP.cpp.obj: CMakeFiles/__test.dir/flags.make
CMakeFiles/__test.dir/src/TSP.cpp.obj: CMakeFiles/__test.dir/includes_CXX.rsp
CMakeFiles/__test.dir/src/TSP.cpp.obj: ../src/TSP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/__test.dir/src/TSP.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\__test.dir\src\TSP.cpp.obj -c C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\TSP.cpp

CMakeFiles/__test.dir/src/TSP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/__test.dir/src/TSP.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\TSP.cpp > CMakeFiles\__test.dir\src\TSP.cpp.i

CMakeFiles/__test.dir/src/TSP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/__test.dir/src/TSP.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\src\TSP.cpp -o CMakeFiles\__test.dir\src\TSP.cpp.s

CMakeFiles/__test.dir/tests/tests.cpp.obj: CMakeFiles/__test.dir/flags.make
CMakeFiles/__test.dir/tests/tests.cpp.obj: CMakeFiles/__test.dir/includes_CXX.rsp
CMakeFiles/__test.dir/tests/tests.cpp.obj: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/__test.dir/tests/tests.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\__test.dir\tests\tests.cpp.obj -c C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\tests\tests.cpp

CMakeFiles/__test.dir/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/__test.dir/tests/tests.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\tests\tests.cpp > CMakeFiles\__test.dir\tests\tests.cpp.i

CMakeFiles/__test.dir/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/__test.dir/tests/tests.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\tests\tests.cpp -o CMakeFiles\__test.dir\tests\tests.cpp.s

# Object files for target __test
__test_OBJECTS = \
"CMakeFiles/__test.dir/src/tsp_setup.cpp.obj" \
"CMakeFiles/__test.dir/src/TSP.cpp.obj" \
"CMakeFiles/__test.dir/tests/tests.cpp.obj"

# External object files for target __test
__test_EXTERNAL_OBJECTS =

__test.exe: CMakeFiles/__test.dir/src/tsp_setup.cpp.obj
__test.exe: CMakeFiles/__test.dir/src/TSP.cpp.obj
__test.exe: CMakeFiles/__test.dir/tests/tests.cpp.obj
__test.exe: CMakeFiles/__test.dir/build.make
__test.exe: lib/libgmockd.a
__test.exe: lib/libgtestd.a
__test.exe: CMakeFiles/__test.dir/linklibs.rsp
__test.exe: CMakeFiles/__test.dir/objects1.rsp
__test.exe: CMakeFiles/__test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable __test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\__test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/__test.dir/build: __test.exe

.PHONY : CMakeFiles/__test.dir/build

CMakeFiles/__test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\__test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/__test.dir/clean

CMakeFiles/__test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug C:\Users\studia\Desktop\studia\informatyka\problem_komiwojazera\cmake-build-debug\CMakeFiles\__test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/__test.dir/depend

