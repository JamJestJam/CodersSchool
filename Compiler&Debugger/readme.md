# Compilers and debuggers.

## The most commonly used compilers.

There are **`g++`**, **`clang`**, **`MSVC`**.

They differ mainly in how they display problems.

They also have varying degrees of implementation of the latest language standards. You can check the current implementation status [**here**](https://en.cppreference.com/w/cpp/compiler_support).

### How to execute commands in g++

Diagram:
**`g++ <flags> <files>`**

This command will compile a system library module. In this case, the iostream library.
**`g++` -std=c++23 -fmodules-ts -xc++-system-header iostream`**

This command will compile a file main.cpp.
**`g++ -std=c++23 -fmodules-ts -Wall -Wextra -Werror -pedantic -Wconversion -lstdc++ -ggdb3 -O3 main.cpp`**

I have a problem that the system libraries don't know where are theirs file so I need to tell them where.
**`export LD_LIBRARY_PATH="/usr/local/lib64/:$LD_LIBRARY_PATH"`**

Execute file.
**`./a.out`**

### Description

Flag 
**`-std=<version>`** 
sets the C++ language version.

Flag 
**`-fmodules-ts`** 
allows the use of modules in the project.

Flag 
**`-xc++-system-header`** 
causes the system library to be compiled.

Flags 
**`-Wall -Wextra -Werror -pedantic -Wconversion`** 
They make the compiler pickier which in turn makes you write better code.

Flag 
**`-O<Level>`** 
This is the level of optimization that is performed on the program. The level is from 0 to 3.
 
Flag 
**`-lstdc++`** 
add system libraries to the program.

Flag 
**`-ggdb3`** 
add debugging options.

Flag
**`-o`** 
specifies the name of the output file.

Flag
**`-c`** 
tells the compiler that it should finish building the application before the linking step.

## CMAKE

Cmake's role is to automatize the process of building **c++/c** projects. 
more info [here](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html#id4)

### Commands

**`cmake <target>`** generate files to build project

**`cmake <target> -DCMAKE_BUILD_TYPE=Debug`** generate files to build project in debug mode

**`cmake -build`** or **`make`** build project

**`ctest`** runs test in cmake

### File commands

**`cmake_minimum_required(VERSION <version>)`** - set cmake version to <version>

**`project(<name>)`** - set project name to <name>

**`set(<name> <value>)`** - create or update variable of name <name> and set its value to <value>. Convection is to create all variables using uppercase's. It's not a good practice to change a cmake variables.

**`add_executable(<source_name> <main_file> <rest_files>)'** - create executable file.

**`add_library(<name> [STATIC, SHARED, MODULE] <files>)`** - create library. 
Static library is used only in this project and pre-compiled.
Shared libraries can be used in many different projects and are linked in running time.
Module library is a library that isn't linked with any other project but can be linked in running time.

**`target_link_libraries(<target> <items>)`** - link libraries <items> to <target> using theirs names.

**`target_compile_options(<target> <INTERFACE, PUBLIC, PRIVATE> <flags>)`** - sets compiler flags to <target>
INTERFACE - flags will be used only in projects that include this.
PUBLIC - flags will be used in this project and in all projects that include this.
PRIVATE - Flags will be used only in this project.

**`set_target_properties(<targets> PROPERTIES <properties>)`** - set <properties> to <targets> for example
you can set **CXX_STANDARD 17** that c++ version is 17
and you can set **CXX_STANDARD_REQUIRED ON** to forced c++ version.

**'target_compile_features(<target> <PRIVATE, PUBLIC, INTERFACE> <feature>)'** - set compiler features PRIVATE PUBLIC INTERFACE works the same as in **target_compile_options**. For example, target_compile_features(proj, PUBLIC cxx_std_20) - set the C++ version to 20 in this project and in all projects that include this.

**`enable_testing()`** - turn on testing using CMAKE.

**`add_test(NAME <name> COMMAND <command>)`** - create new tests of name <name> and to run this test execute command <command>.

### CMAKE variables

**`${PROJECT_NAME}`** - name of project

**`CMAKE_CXX_COMPILER`** - storage name of the compiler. RECOMMENDED TO NOT USE.

**`CMAKE_CXX_STANDARD`** - storage base C++ version (if not specified this version will be used).

**`CMAKE_CXX_STANDARDKE_CXX_STANDARD_REQUIRED`** - storage variable **ON** or **OFF**. It's forced usage of **CMAKE_CXX_STANDARD**.

## DEBUGGERS

### Commands GDB

**`gdb <file>`** - open a GDB debugger for a file

**`run`** - run program

**`list / l`** - show code around current position

**`break / b <file>:<line number>`** - create breakpoint in file and line

**`print / p <value>`** - show value of <value>

**`tui enable`** - show GUI version compiler

**`next / n`** - go to the next line

**`step / s`** - go into function

**`finish / f`** - finish function 

**`continue / c`** - go to next break point

**`set variable <name> <value>`** - set value of variable <name> to <value>

**`catch throw`** - show where are unhandled thrown exceptions

**`up`** - go up in stock

**`down`** - go down in stock

**`watch <name>`** - break every time variable <name> change 

### Valgrind ASan

**`valgrind <name>`** - run valgrind of program

To use ASan you need to add a flag **`-fsanitize=<option>`** to your compiler options
