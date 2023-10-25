cmake_minimum_required(VERSION 3.22)
project(CMakeGTestProject)

Include(FetchContent)
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main 
)
FetchContent_MakeAvailable(gtest)

set(NAME ${PROJECT_NAME})
set(TEST-NAME ${NAME}-TEST)
set(FLAGS -std=c++20 -Wall -Wextra -Werror -pedantic -Wconversion -fmodules-ts -lstdc++ -ggdb3 -O3)

set(NAME-FILES Factorial.cpp)
set(TEST-FILES Test.cpp)

add_executable(${TEST-NAME} ${TEST-FILES} ${NAME-FILES})
target_compile_options(${TEST-NAME} PRIVATE ${FLAGS})
target_link_libraries(${TEST-NAME} gtest_main)

enable_testing()
add_test(${TEST-NAME} ${TEST-NAME})
