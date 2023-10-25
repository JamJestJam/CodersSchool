cmake_minimum_required(VERSION 3.22)
project(CmakeCatch2Project)

# Old way
# find_package(Catch2 REQUIRED)

# New way
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(Catch2)

set(NAME ${PROJECT_NAME})
set(TEST-NAME ${NAME}-TEST)
set(FLAGS -std=c++20 -Wall -Wextra -Werror -pedantic -Wconversion -fmodules-ts -lstdc++ -ggdb3 -O3)

set(NAME-FILES Factorial.cpp)
set(TEST-FILES Test.cpp)

add_executable(${TEST-NAME} ${TEST-FILES} ${NAME-FILES})
target_compile_options(${TEST-NAME} PRIVATE ${FLAGS})
target_link_libraries(${TEST-NAME} Catch2::Catch2WithMain)

enable_testing()
add_test(${TEST-NAME} ${TEST-NAME})
