# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/liuxing1/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/liuxing1/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuxing1/CodeFiles/Unix_chatroom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.out.dir/flags.make

CMakeFiles/client.out.dir/cli/src/chatcli.c.o: CMakeFiles/client.out.dir/flags.make
CMakeFiles/client.out.dir/cli/src/chatcli.c.o: ../cli/src/chatcli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/client.out.dir/cli/src/chatcli.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.out.dir/cli/src/chatcli.c.o   -c /home/liuxing1/CodeFiles/Unix_chatroom/cli/src/chatcli.c

CMakeFiles/client.out.dir/cli/src/chatcli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.out.dir/cli/src/chatcli.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuxing1/CodeFiles/Unix_chatroom/cli/src/chatcli.c > CMakeFiles/client.out.dir/cli/src/chatcli.c.i

CMakeFiles/client.out.dir/cli/src/chatcli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.out.dir/cli/src/chatcli.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuxing1/CodeFiles/Unix_chatroom/cli/src/chatcli.c -o CMakeFiles/client.out.dir/cli/src/chatcli.c.s

CMakeFiles/client.out.dir/cli/main.c.o: CMakeFiles/client.out.dir/flags.make
CMakeFiles/client.out.dir/cli/main.c.o: ../cli/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/client.out.dir/cli/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.out.dir/cli/main.c.o   -c /home/liuxing1/CodeFiles/Unix_chatroom/cli/main.c

CMakeFiles/client.out.dir/cli/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.out.dir/cli/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuxing1/CodeFiles/Unix_chatroom/cli/main.c > CMakeFiles/client.out.dir/cli/main.c.i

CMakeFiles/client.out.dir/cli/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.out.dir/cli/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuxing1/CodeFiles/Unix_chatroom/cli/main.c -o CMakeFiles/client.out.dir/cli/main.c.s

# Object files for target client.out
client_out_OBJECTS = \
"CMakeFiles/client.out.dir/cli/src/chatcli.c.o" \
"CMakeFiles/client.out.dir/cli/main.c.o"

# External object files for target client.out
client_out_EXTERNAL_OBJECTS =

client.out: CMakeFiles/client.out.dir/cli/src/chatcli.c.o
client.out: CMakeFiles/client.out.dir/cli/main.c.o
client.out: CMakeFiles/client.out.dir/build.make
client.out: CMakeFiles/client.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable client.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.out.dir/build: client.out

.PHONY : CMakeFiles/client.out.dir/build

CMakeFiles/client.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.out.dir/clean

CMakeFiles/client.out.dir/depend:
	cd /home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuxing1/CodeFiles/Unix_chatroom /home/liuxing1/CodeFiles/Unix_chatroom /home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug /home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug /home/liuxing1/CodeFiles/Unix_chatroom/cmake-build-debug/CMakeFiles/client.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.out.dir/depend

