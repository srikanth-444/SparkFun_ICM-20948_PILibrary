# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/raspi/Documents/SparkFun_ICM-20948_PILibrary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build

# Include any dependencies generated for this target.
include CMakeFiles/icm20948.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/icm20948.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/icm20948.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icm20948.dir/flags.make

CMakeFiles/icm20948.dir/src/bindings.cpp.o: CMakeFiles/icm20948.dir/flags.make
CMakeFiles/icm20948.dir/src/bindings.cpp.o: /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/bindings.cpp
CMakeFiles/icm20948.dir/src/bindings.cpp.o: CMakeFiles/icm20948.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icm20948.dir/src/bindings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icm20948.dir/src/bindings.cpp.o -MF CMakeFiles/icm20948.dir/src/bindings.cpp.o.d -o CMakeFiles/icm20948.dir/src/bindings.cpp.o -c /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/bindings.cpp

CMakeFiles/icm20948.dir/src/bindings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icm20948.dir/src/bindings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/bindings.cpp > CMakeFiles/icm20948.dir/src/bindings.cpp.i

CMakeFiles/icm20948.dir/src/bindings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icm20948.dir/src/bindings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/bindings.cpp -o CMakeFiles/icm20948.dir/src/bindings.cpp.s

CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o: CMakeFiles/icm20948.dir/flags.make
CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o: /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/ICM_20948.cpp
CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o: CMakeFiles/icm20948.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o -MF CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o.d -o CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o -c /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/ICM_20948.cpp

CMakeFiles/icm20948.dir/src/ICM_20948.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icm20948.dir/src/ICM_20948.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/ICM_20948.cpp > CMakeFiles/icm20948.dir/src/ICM_20948.cpp.i

CMakeFiles/icm20948.dir/src/ICM_20948.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icm20948.dir/src/ICM_20948.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/ICM_20948.cpp -o CMakeFiles/icm20948.dir/src/ICM_20948.cpp.s

CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o: CMakeFiles/icm20948.dir/flags.make
CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o: /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/util/ICM_20948_C.c
CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o: CMakeFiles/icm20948.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o -MF CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o.d -o CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o -c /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/util/ICM_20948_C.c

CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/util/ICM_20948_C.c > CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.i

CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/src/util/ICM_20948_C.c -o CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.s

# Object files for target icm20948
icm20948_OBJECTS = \
"CMakeFiles/icm20948.dir/src/bindings.cpp.o" \
"CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o" \
"CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o"

# External object files for target icm20948
icm20948_EXTERNAL_OBJECTS =

icm20948.cpython-311-aarch64-linux-gnu.so: CMakeFiles/icm20948.dir/src/bindings.cpp.o
icm20948.cpython-311-aarch64-linux-gnu.so: CMakeFiles/icm20948.dir/src/ICM_20948.cpp.o
icm20948.cpython-311-aarch64-linux-gnu.so: CMakeFiles/icm20948.dir/src/util/ICM_20948_C.c.o
icm20948.cpython-311-aarch64-linux-gnu.so: CMakeFiles/icm20948.dir/build.make
icm20948.cpython-311-aarch64-linux-gnu.so: CMakeFiles/icm20948.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared module icm20948.cpython-311-aarch64-linux-gnu.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icm20948.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/strip /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/icm20948.cpython-311-aarch64-linux-gnu.so

# Rule to build all files generated by this target.
CMakeFiles/icm20948.dir/build: icm20948.cpython-311-aarch64-linux-gnu.so
.PHONY : CMakeFiles/icm20948.dir/build

CMakeFiles/icm20948.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icm20948.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icm20948.dir/clean

CMakeFiles/icm20948.dir/depend:
	cd /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raspi/Documents/SparkFun_ICM-20948_PILibrary /home/raspi/Documents/SparkFun_ICM-20948_PILibrary /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build /home/raspi/Documents/SparkFun_ICM-20948_PILibrary/build/CMakeFiles/icm20948.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icm20948.dir/depend

