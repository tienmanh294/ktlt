# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/tienmanh/232/ktlt/ktlt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tienmanh/232/ktlt/ktlt

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"gmock\" \"gtest\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tienmanh/232/ktlt/ktlt/CMakeFiles /home/tienmanh/232/ktlt/ktlt//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tienmanh/232/ktlt/ktlt/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ktlt

# Build rule for target.
ktlt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ktlt
.PHONY : ktlt

# fast build rule for target.
ktlt/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/build
.PHONY : ktlt/fast

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googlemock/CMakeFiles/gmock_main.dir/build.make googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googletest/CMakeFiles/gtest.dir/build.make googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googletest/CMakeFiles/gtest_main.dir/build.make googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named UnitTest

# Build rule for target.
UnitTest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 UnitTest
.PHONY : UnitTest

# fast build rule for target.
UnitTest/fast:
	$(MAKE) $(MAKESILENT) -f unittest/CMakeFiles/UnitTest.dir/build.make unittest/CMakeFiles/UnitTest.dir/build
.PHONY : UnitTest/fast

src/Issue.o: src/Issue.cpp.o
.PHONY : src/Issue.o

# target to build an object file
src/Issue.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Issue.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Issue.cpp.o
.PHONY : src/Issue.cpp.o

src/Issue.i: src/Issue.cpp.i
.PHONY : src/Issue.i

# target to preprocess a source file
src/Issue.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Issue.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Issue.cpp.i
.PHONY : src/Issue.cpp.i

src/Issue.s: src/Issue.cpp.s
.PHONY : src/Issue.s

# target to generate assembly for a file
src/Issue.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Issue.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Issue.cpp.s
.PHONY : src/Issue.cpp.s

src/Project.o: src/Project.cpp.o
.PHONY : src/Project.o

# target to build an object file
src/Project.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Project.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Project.cpp.o
.PHONY : src/Project.cpp.o

src/Project.i: src/Project.cpp.i
.PHONY : src/Project.i

# target to preprocess a source file
src/Project.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Project.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Project.cpp.i
.PHONY : src/Project.cpp.i

src/Project.s: src/Project.cpp.s
.PHONY : src/Project.s

# target to generate assembly for a file
src/Project.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Project.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Project.cpp.s
.PHONY : src/Project.cpp.s

src/System.o: src/System.cpp.o
.PHONY : src/System.o

# target to build an object file
src/System.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/System.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/System.cpp.o
.PHONY : src/System.cpp.o

src/System.i: src/System.cpp.i
.PHONY : src/System.i

# target to preprocess a source file
src/System.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/System.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/System.cpp.i
.PHONY : src/System.cpp.i

src/System.s: src/System.cpp.s
.PHONY : src/System.s

# target to generate assembly for a file
src/System.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/System.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/System.cpp.s
.PHONY : src/System.cpp.s

src/Task.o: src/Task.cpp.o
.PHONY : src/Task.o

# target to build an object file
src/Task.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Task.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Task.cpp.o
.PHONY : src/Task.cpp.o

src/Task.i: src/Task.cpp.i
.PHONY : src/Task.i

# target to preprocess a source file
src/Task.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Task.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Task.cpp.i
.PHONY : src/Task.cpp.i

src/Task.s: src/Task.cpp.s
.PHONY : src/Task.s

# target to generate assembly for a file
src/Task.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Task.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Task.cpp.s
.PHONY : src/Task.cpp.s

src/User.o: src/User.cpp.o
.PHONY : src/User.o

# target to build an object file
src/User.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/User.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/User.cpp.o
.PHONY : src/User.cpp.o

src/User.i: src/User.cpp.i
.PHONY : src/User.i

# target to preprocess a source file
src/User.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/User.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/User.cpp.i
.PHONY : src/User.cpp.i

src/User.s: src/User.cpp.s
.PHONY : src/User.s

# target to generate assembly for a file
src/User.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/User.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/User.cpp.s
.PHONY : src/User.cpp.s

src/Utils.o: src/Utils.cpp.o
.PHONY : src/Utils.o

# target to build an object file
src/Utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Utils.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Utils.cpp.o
.PHONY : src/Utils.cpp.o

src/Utils.i: src/Utils.cpp.i
.PHONY : src/Utils.i

# target to preprocess a source file
src/Utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Utils.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Utils.cpp.i
.PHONY : src/Utils.cpp.i

src/Utils.s: src/Utils.cpp.s
.PHONY : src/Utils.s

# target to generate assembly for a file
src/Utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/Utils.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Utils.cpp.s
.PHONY : src/Utils.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/main.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/main.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ktlt.dir/build.make CMakeFiles/ktlt.dir/src/main.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... UnitTest"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... ktlt"
	@echo "... main"
	@echo "... src/Issue.o"
	@echo "... src/Issue.i"
	@echo "... src/Issue.s"
	@echo "... src/Project.o"
	@echo "... src/Project.i"
	@echo "... src/Project.s"
	@echo "... src/System.o"
	@echo "... src/System.i"
	@echo "... src/System.s"
	@echo "... src/Task.o"
	@echo "... src/Task.i"
	@echo "... src/Task.s"
	@echo "... src/User.o"
	@echo "... src/User.i"
	@echo "... src/User.s"
	@echo "... src/Utils.o"
	@echo "... src/Utils.i"
	@echo "... src/Utils.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

