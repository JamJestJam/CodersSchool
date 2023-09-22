cmake_minimum_required(VERSION 3.22)
project(HelloWorld)

set(NAME ${PROJECT_NAME})

set(FLAGS -std=c++20 -Wall -Wextra -Werror -pedantic -Wconversion -fmodules-ts -lstdc++ -ggdb3 -O3)
set(FLAGS_SYSTEM -std=c++23 -fmodules-ts -xc++-system-header)

#add_library(IOSTREAM INTERFACE)
#target_compile_options(IOSTREAM INTERFACE
#  -std=c++23 -fmodules-ts -xc++-system-header iostream -o iostream.o)

#add_custom_command(
#  OUTPUT doNotReadMe.txt
#  DEPENDS ${NAME}
#  COMMAND g++ -std=c++23 -fmodules-ts -xc++-system-header iostream
#  WORKING_DIRECTORY ${CMAKE_CURENT_BINARY_DIR}
#  )

#execute_process(COMMAND /usr/bin/g++ -std=c++20 -fmodules-ts -xc++-system-header iostream)

add_executable(${NAME} main.cpp)
target_compile_options(${NAME} PRIVATE ${FLAGS})
#target_link_libraries(${NAME} IOSTREAM)



















