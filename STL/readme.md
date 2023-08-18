# Standard template library

This is the base functionality that comes with c++.
You should always use it.

## Containers

### Vector

Vector is a dynamic array that allows you to change its length at runtime.
Vector is catch friendly.

Create vector
`
#include <vector>

std::vector<Type> name; // initialize Type vector witout data 
std::vector<int> numbers {1, 2, 3, 4}; // initialize vector with data
std::vector<char> chars = {'a', 'b', 'c'}; // another way to initialize with data
`

Most popular actions that can be do on the vector.
`
#include <vector>

std::vector<int> numbers {1, 2, 3, 4};

int main() {
    numbers.push_back(6); // add new item to the vector
    numbers = {1, 2, 3}; // replace old vector with new.
    int n = numbers[1]; // get element from vector
    int first = numbers.front(); // get first element in vector
    int last = numbers.back(); // get last element in vector
}
`

[more info](https://en.cppreference.com/w/cpp/container/vector)

### Summary

|Lp|Type|Catch friendly|Mode of action|
|-|-|-|-|
|1|Vector|Yes|Array|

