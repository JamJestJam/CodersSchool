gcc -std=c++23 -fmodules-ts -xc++-system-header iostream
gcc -std=c++23 -fmodules-ts -Wall -Wextra -Werror -pedantic -Wconversion -lstdc++ -ggdb3 -O3 main.cpp
export LD_LIBRARY_PATH="/usr/local/lib64/:$LD_LIBRARY_PATH"
./a.out