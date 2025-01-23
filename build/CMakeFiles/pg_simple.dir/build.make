# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build

# Include any dependencies generated for this target.
include CMakeFiles/pg_simple.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pg_simple.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pg_simple.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pg_simple.dir/flags.make

CMakeFiles/pg_simple.dir/src/main.cpp.o: CMakeFiles/pg_simple.dir/flags.make
CMakeFiles/pg_simple.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/pg_simple.dir/src/main.cpp.o: CMakeFiles/pg_simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pg_simple.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pg_simple.dir/src/main.cpp.o -MF CMakeFiles/pg_simple.dir/src/main.cpp.o.d -o CMakeFiles/pg_simple.dir/src/main.cpp.o -c /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/main.cpp

CMakeFiles/pg_simple.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pg_simple.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/main.cpp > CMakeFiles/pg_simple.dir/src/main.cpp.i

CMakeFiles/pg_simple.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pg_simple.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/main.cpp -o CMakeFiles/pg_simple.dir/src/main.cpp.s

CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o: CMakeFiles/pg_simple.dir/flags.make
CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o: ../src/ElementsMath.cpp
CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o: CMakeFiles/pg_simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o -MF CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o.d -o CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o -c /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/ElementsMath.cpp

CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/ElementsMath.cpp > CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.i

CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/ElementsMath.cpp -o CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.s

CMakeFiles/pg_simple.dir/src/Shaders.cpp.o: CMakeFiles/pg_simple.dir/flags.make
CMakeFiles/pg_simple.dir/src/Shaders.cpp.o: ../src/Shaders.cpp
CMakeFiles/pg_simple.dir/src/Shaders.cpp.o: CMakeFiles/pg_simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pg_simple.dir/src/Shaders.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pg_simple.dir/src/Shaders.cpp.o -MF CMakeFiles/pg_simple.dir/src/Shaders.cpp.o.d -o CMakeFiles/pg_simple.dir/src/Shaders.cpp.o -c /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/Shaders.cpp

CMakeFiles/pg_simple.dir/src/Shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pg_simple.dir/src/Shaders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/Shaders.cpp > CMakeFiles/pg_simple.dir/src/Shaders.cpp.i

CMakeFiles/pg_simple.dir/src/Shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pg_simple.dir/src/Shaders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/src/Shaders.cpp -o CMakeFiles/pg_simple.dir/src/Shaders.cpp.s

# Object files for target pg_simple
pg_simple_OBJECTS = \
"CMakeFiles/pg_simple.dir/src/main.cpp.o" \
"CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o" \
"CMakeFiles/pg_simple.dir/src/Shaders.cpp.o"

# External object files for target pg_simple
pg_simple_EXTERNAL_OBJECTS =

pg_simple: CMakeFiles/pg_simple.dir/src/main.cpp.o
pg_simple: CMakeFiles/pg_simple.dir/src/ElementsMath.cpp.o
pg_simple: CMakeFiles/pg_simple.dir/src/Shaders.cpp.o
pg_simple: CMakeFiles/pg_simple.dir/build.make
pg_simple: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
pg_simple: CMakeFiles/pg_simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable pg_simple"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pg_simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pg_simple.dir/build: pg_simple
.PHONY : CMakeFiles/pg_simple.dir/build

CMakeFiles/pg_simple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pg_simple.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pg_simple.dir/clean

CMakeFiles/pg_simple.dir/depend:
	cd /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build /home/arguableplains/Documents/Workspace/Programacoes/C++/Graphics/ProceduralGeneration-Simple/build/CMakeFiles/pg_simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pg_simple.dir/depend

