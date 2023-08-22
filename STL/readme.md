# Standard template library

This is the base functionality that comes with c++.
You should always use it.

## Containers

### Vector

Vector is a dynamic array that allows you to change its length at runtime.
Vector is catch friendly.

Most popular actions that can be do on the vector.
```
#include <vector>

std::vector<double> emptyVector; // initialize vector without data
std::vector<int> numbers {1, 2, 3, 4}; // initialize vector with data
std::vector<char> chars = {'a', 'b', 'c'}; // another way to initialize vector with data

int main() {
    numbers.push_back(6); // add new item to the vector
    numbers = {1, 2, 3}; // replace old vector with new.
    int n = numbers[1]; // get element from vector
    int first = numbers.front(); // get first element in vector
    int last = numbers.back(); // get last element in vector
}
```

[more info](https://en.cppreference.com/w/cpp/container/vector)

### List

List is a dynamic double connected list. (you can literate from front and from back)
You can add elements with every space in list in the same time.
To get n element you need to enumerate from first to n.

Simple code wit list
```
#include <list>

std::listdouble> emptyVector; // initialize list without data
std::list<int> numbers {1, 2, 3, 4}; // initialize list with data
std::list<char> chars = {'a', 'b', 'c'}; // another way to initialize list with data

int main() {
    numbers.push_back(6); // add new item to the list
    numbers.push_front(3); // add new item to the list at the beginning
    numbers = {1, 2, 3}; // replace old list with new.
    int first = numbers.front(); // get first element in vector
    int last = numbers.back(); // get last element in vector

    int n = 3;
    // get n element from list
    auto element = list.begin(); // get literator to first element
    for(size_t i = 0; i < n; i++) { // n times loop
        ++element; // go to next element.
    }
    auto result = *element; // get value of n element in list
}
```

[more info](https://en.cppreference.com/w/cpp/container/list)

### Map

Map is a structure that contains keys and values and you can get access to value by passing a key.

Simple code with map
```
#include <list>
#include <string>

std::map<unsigned short, std::string> day_of_week = {
    {1, "Monday"},
    {2, "Tuesday"},
    {3, "Wednesday"},
    {4, "Thursday"},
    {5, "Friday"},
    {6, "Saturday"},
    {7, "Sunday"}
};

int main() {
    auto day_name = day_of_week[2]; // get element from map
    day_of_week.insert({8, "new day name"}); // insert new element to map.
    bool empty = day_of_week.empty(); // check if map is empty
    size_t size = day_of_week.size(); // get size of map
}
```

[more info](https://en.cppreference.com/w/cpp/container/map)

### Summary

|Lp|Type|Catch friendly|Dynamic size|Mode of action|Time to access random element|time to add|
|-|-|-|-|-|
|0|array|yes|no|array|Pss|N/O|
|1|vector|yes|yes|array|Pss|Pss| 
|2|list|no|yes|double linked list|Pss|Pss|

## Functions

### Foreach loop

Old way to loop for every element in container:
```
for(auto i = container.begin(); i != container.end(); ++i) {
    auto element = *i;
    // do sth.
}
`
New way to do the same
`
for(auto element : container) {
    // do sth
}
```

