# Hello world

## First compiled program. Overview of the commands

### comands
**`gcc -std=c++23 -fmodules-ts -xc++-system-header iostream`**
**`gcc -std=c++23 -fmodules-ts -Wall -Wextra -Werror -pedantic -Wconversion -lstdc++ -ggdb3 -O3`**
**`export LD_LIBRARY_PATH="/usr/local/lib64/:$LD_LIBRARY_PATH"`**
**`./a.out`**

### Description

**`gcc <flags> <files>`** is the name of the compiler, it can also be called with g++.
Flag **`-std=c++23`** sets the c++ language version to 23.
Flag **`-fmodules-ts`** allows the use of modules in the project.
Flag **`-xc++-system-header`** causes the system library to be compiled.
Flags **`-Wall -Wextra -Werror -pedantic -Wconversion`** they make the compiler pickier which in turn makes you write better code
Flag **`-O3`** this is the level of optimization that is performed on the program
Flag **`-lstdc++`** add system libraries to the program.
Flag **`-ggdb3`** add debugging options

**`export LD_LIBRARY_PATH="/usr/local/lib64/:$LD_LIBRARY_PATH`** in my compiler version of gcc i have a problem that gcc don't know where that libraries are this command set their location.

**`./a.out`** run a program