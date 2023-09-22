# Standard Template Library

This is the base functionality that comes with C++. You should always use it.

# Containers

## Sequence containers

The container is sequenced when the elements are arranged in the order they were added to the container.
Examples of sequence containers:
    - array
    - vector
    - list
    - forward_list
    - deque

## Associative containers

The container is associative when the elements inside the container are ordered, and the computational complexity to find an element is O(log n).
Example of associative containers:
    - set
    - map
    - multiset
    - multimap

## Non associative containers

The container is non associative when the elements inside the container have their own hash code and are stored based on them.
    - unordered_set
    - unordered_map
    - unordered_multiset
    - unordered_multimap

## Container adaptors
That container adopts sequence containers to a specific task for example to use in the FIFO queue.
Example of adaptor containers:
    - stack
    - queue
    - priority_queue 

### Base info

O(1) - complexity constant
O(x) - complexity linear depends on x
O(log x) - complexity logarithmic depends on x
n - size of container
m - the size of the range
p - complexity of algorithm

Cache friendly - that means the container's data is arranged so that every element is near each other<br />
Dynamic size - container can change its size<br />

| Type          | Cache friendly    | Dynamic size  | Description 
| :---:         | :---:             | :---:         | :---:
| array         | yes               | no            | Stores data in a permanent location in memory. It cannot be resized.
| vector        | yes               | yes           | Stores data in a contiguous block of memory and uses pointers to manage it. Pointers to the beginning, end of the allocated block, and the end of the used area are stored on the stack. When the container scope is exceeded, the data is rewritten to a larger scope.
| list          | no                | yes           | Stores data as objects. Items are stored as nodes with pointers to the previous and next items. A pointer to the first and last element is stored on the stack, which allows for quick additions to the beginning and end of the container.
| forward_list  | no                | yes           | Stores data as objects. Items are stored as nodes with pointers to next items. A pointer to first element is stored on the stack, which allows for quick additions to the beginning. 
| deque         | partial           | yes           | Stores data as a sequence of segments, where each segment is a small array. Stack pointers track the start and end of collections and the current positions within segments, allowing you to quickly access data at both ends of the collection and within segments. Due to this structure, deque allows you to efficiently add and remove elements at the front and back of the queue.
| map           | no                | yes           | Stores data in the form of a key value object. The data is organized in the form of a binary tree. It is impossible to have two of the same keys in a container.
| multimap      | no                | yes           | Stores data in the form of a key value object. The data is organized in the form of a binary tree. It is possible to have two of the same keys in a container. 
|               |                   |               | 
|               |                   |               | 
|               |                   |               | 

### Function element access

`operator[]` - This allows you to access the data using the [] operator by typing the data key inside<br />
`front` - it gives the first element in the container<br />
`back` - it gives the last element in the container<br />
`at` - get element by its position in container<br />

| Type          | `operator[]`  | `front`   | `back`    | `at`  | 
| :---:         | :---:         | :---:     | :---:     | :---: |
| array         | O(1)          | O(1)      | O(1)      | O(1)  |
| vector        | O(1)          | O(1)      | O(1)      | O(1)  |
| list          | ---           | O(1)      | O(1)      | ---   |
| forward_list  | ---           | O(1)      | ---       | ---   |
| deque         | O(1)          | O(1)      | O(1)      | O(1)  |
| map           | O(Log(n)      | ---       | ---       | ---   |
| multimap      | O(log(n)      | ---       | ---       | ---   |
|               |               |           |           |       |
|               |               |           |           |       |
|               |               |           |           |       |

### Function iterators
`end` - get the last iterator<br />
`rbegin` - get first reverse iterator<br />
`rend` - get last reverse iterator<br />
You can also use iterators with `c` before their name then the iterator is constant

| Type          | `begin`   | `end` | `rbegin`  | `rend`    |
| :---:         | :---:     | :---: | :---:     | :---:     |
| array         | O(1)      | O(1)  | O(1)      | O(1)      |
| vector        | O(1)      | O(1)  | O(1)      | O(1)      |
| list          | O(1)      | O(1)  | O(1)      | O(1)      |
| forward_list  | O(1)      | O(1)  | ---       | ---       |
| deque         | O(1)      | O(1)  | O(1)      | O(1)      |
| map           | O(1)      | O(1)  | O(1)      | O(1)      |
| multimap      | O(1)      | O(1)  | O(1)      | O(1)      |
|               |           |       |           |           |
|               |           |       |           |           |
|               |           |       |           |           |

### Function capacity

`empty` - check if the container is empty<br />
`size` - check container's size<br />
`max_size` - check container max possible size<br />
`reserve` - reserve space needed to store more elements<br />
`capacity` - show container allocated size<br />
`shrink_to_fit` - shrink the allocated size to elements size<br />

| Type          | `empty`   | `size`    | `max_size`    | `reserve` | `capacity`    | `shrink_to_fit`   |
| :---:         | :---:     | :---:     | :---:         | :---:     | :---:         | :---:             |
| array         | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
| vector        | O(1)      | O(1)      | O(1)          | O(n)      | O(1)          | O(n)              |
| list          | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
| forward_list  | O(1)      | ---       | O(1)          | ---       | ---           | ---               |
| deque         | O(1)      | O(1)      | O(1)          | ---       | ---           | O(n)              |
| map           | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
| multimap      | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
|               |           |           |               |           |               |                   |
|               |           |           |               |           |               |                   |
|               |           |           |               |           |               |                   |

### Function modifiers

`fill` - assign container's values<br />
`swap` - change container's elements<br />
`clear` - clear container's value<br />
`insert` - insert an element in a specific place in the container<br />
`insert_after` - insert an element after iterator<br /> 
`insert_range` - insert elements in a specific place in the container<br />
`insert_range_after` - insert elements after iterator<br />
`insert_or_assign` - insert element into container, If inserted key exist then update value<br />
`emplace` - insert element before specific place in container<br />
`emplace_after` - insert an element after a specific place in the container<br />
`emplace_hint` - insert an item into a container more efficiently<br />
`try_emplace` - inert element into a container if key doesn't exist<br />
`erase` - remove element from container<br />
`erase_after` - remove element from container<br />
`push_back` - add a new element on the end of the container<br />
`push_front` - insert element on the beginning of the container<br />
`emplace_back` - create a new element and insert it to the end of the container<br />
`emplace_front` - Create a new element and insert it into the beginning of the container<br />
`append_range` - add elements on the end of the container<br />
`prepend_range` - add elements at the beginning of the container<br />
`pop_back` - remove last element<br />
`pop_front` - remove first element<br />
`resize` - change container size<br />

| Type          | `fill`    | `swap`    | `clear`   | `insert`          | `insert_after` | `insert_range`    | `insert_range_after`  | `insert_or_assign` | `emplace` | `emplace_after`   | `emplace_hint`      | `try_emplace`         | `erase`     | `erase_after` | `push_back`   | `push_front`  | `emplace_back`    | `emplace_front`   | `append_range`    | `prepend_range`   | `pop_back`    | `pop_front`   | `resize`  |
| :---:         | :---:     | :---:     | :---:     | :---:             | :---:          | :---:             | :---:                 |  :---:             | :---:     | :---:             | :---:               | :---:                 | :---:       | :---:         | :---:         | :---:         | :---:             | :---:             | :---:             | :---:             | :---:         | :---:         | :---:     |
| array         | O(1)      | O(1)      | ---       | ---               | ---            | ---               | ---                   |  ---               | ---       | ---               | ---                 | ---                   | ---         | ---           | ---           | ---           | ---               | ---               | ---               | ---               | ---           | ---           | ---       |
| vector        | ---       | O(1)      | O(n)      | O(m) O(n)+O(m)    | ---            | O(m) O(n)+O(m)    | ---                   |  ---               | O(n)      | ---               | ---                 | ---                   | O(n)        | ---           | O(1) O(n)     | ---           | O(1) O(n)         | ---               | O(m) O(n)+O(m)    | ---               | O(1)          | ---           | O(1) O(m) |
| list          | ---       | O(1)      | O(n)      | O(m)              | ---            | O(m)              | ---                   |  ---               | O(1)      | ---               | ---                 | ---                   | O(m)        | ---           | O(1)          | O(1)          | O(1)              | O(1)              | O(m)              | O(m)              | O(1)          | O(1)          | O(m)      |
| forward_list  | ---       | O(1)      | O(n)      | ---               | O(m)           | ---               | O(m)                  |  ---               | ---       | O(1)              | ---                 | ---                   | ---         | O(m)          | ---           | ---           | ---               | O(1)              | ---               | O(m)              | ---           | O(1)          | O(m)      |
| deque         | ---       | O(1)      | O(n)      | O(m) O(n)+O(m)    | ---            | O(m) O(n)+O(m)    | ---                   |  ---               | O(1)      | ---               | ---                 | ---                   | O(m)        | ---           | O(1)          | O(1)          | O(1)              | O(1)              | O(m)              | O(m)              | O(1)          | O(1)          | O(m)      |
| map           | ---       | O(1)      | O(n)      | O(log(n))         | ---            | O(m*log(n))       | ---                   |  O(log(n))         | O(log(n)) | ---               | O(1)<br />O(log(n)) | O(1)<br />O(log(n))   | O(log(m+n)) | ---           | ---           | ---           | ---               | ---               | ---               | ---               | ---           | ---           | ---       |
| multimap      | ---       | O(1)      | O(n)      | O(log(n))         | ---            | O(m*log(n))       | ---                   |  O(log(n))         | O(log(n)) | ---               | O(1)<br />O(log(n)) | O(1)<br />O(log(n))   | O(log(m+n)) | ---           | ---           | ---           | ---               | ---               | ---               | ---               | ---           | ---           | ---       |
|               |           |           |           |                   |                |                   |                       |                    |           |                   |                     |                       |             |               |               |               |                   |                   |                   |                   |               |               |           |
|               |           |           |           |                   |                |                   |                       |                    |           |                   |                     |                       |             |               |               |               |                   |                   |                   |                   |               |               |           |
|               |           |           |           |                   |                |                   |                       |                    |           |                   |                     |                       |             |               |               |               |                   |                   |                   |                   |               |               |           |

### Function operation

`merge` - merge two sorted containers<br />
`splice` - get data from the first container and transfer it to another<br />
`splice_after` - get data from the first container and transfer it to another<br />
`remove` - remove elements that are equal to the parameter<br />
`remove_if` - remove elements that meet the condition<br />
`reverse` - reverse the order of the elements<br />
`unique` - remove duplicated elements<br />
`sort` - sort container

| Type          | `merge`   | `splice`  | `splice_after`    | `remove`  | `remove_if`   | `reverse` | `unique`  | `sort`        |
| :---:         | :---:     | :---:     | :---:             | :---:     | :---:         | :---:     | :---:     | :---:         |
| array         | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| vector        | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| list          | O(n)+O(m) | O(1)      | ---               | O(n)      | O(n)*p        | O(n)      | O(n)      | O(n*log n)    |
| forward_list  | O(n)+O(m) | ---       | O(1)              | O(n)      | O(n)*p        | O(n)      | O(n)      | O(n*log n)    |
| deque         | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| map           | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| multimap      | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |

# Lambda

Lambda is a way to create a single-line function. For example:
```
auto a = 0;
auto function = [&a](int b) mutable { a += b; };

function(2);
function(4);

std::cout << a; // a = 6
```
Inside bracket `[]` you can give a variable that is available in every iteration, the keyword `mutable` makes the variable inside `[]` possible to change, 
inside `()` bracket are function parameters and in `{}` function body.

[build in lambdas](https://en.cppreference.com/w/cpp/header/functional)

# Algorithms

I will describe a few of the most commonly used algorithms. 
[Algorithm library](https://en.cppreference.com/w/cpp/algorithm)

The most common algorithm variation
If the name of the algorithm ends `*_if` then the algorithm doesn't take a value but a function for example.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::find(v.begin(), v.end(), 5); // find 5
std::find_if(v.begin(), v.end(), [](auto x){ return x > 5; }); // find bigger than 5
```

When the name ends `*_copy` then the algorithm does not edit the container but creates a new one.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
std::vector destination(12);

std::reverse(v.begin(), v.end()); // reverse vector v
std::reverse_copy(v.begin(), v.end(), destination.begin()); // reverse vector v and save changes to vector destination
```

And when the name ends `*_n` then the algorithm works only on n elements
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::fill(v.begin(), v.end(), -1); // fill vector with value -1
std::fill_n(v.begin(), 10, -2); // fill first 10 elements with value -2
```

In C++ 20 when you want to work on every element in the container you can use `std::ranges`.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::sort(v.begin(), v.end());
std::ranges::sort(v);
```

When you use c tables or you want to  do things differently you can use global functions instead of containers;
```
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::sort(begin(v), end(v));
```

### Iterators

This iterator deals with streams 
`std::ostream_iterator<T>(stream, delimer)`
You can use this to for example show container to default output.
```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};

std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "), [](int a){ return a > 2; }); // show on default output every greater element then 2
```

This iterator adds a new element to the container
`std::back_inserter(container)`;
You can use it if you use an algorithm that creates new elements and you want to add them to the container.

## Algorithms that do not edit container

### Check condition

```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

auto all = std::all_of(begin(v), end(v), [](auto a){ return a > 0; }) // check if all values in container are greater then 0
auto any = std::any_of(begin(v), end(v), [](auto a){ return a > 11; }) // check if any value if greater then 11
auto none = std::none_of(begin(v), end(v), [](auto a){ return a > 0; }) // check if none of the values in the container is greater than 0;
```

### Count elements

```
std::vector v {1, 2, 3, 4, 5, 4, 7, 8, 4, 10, 4, 12};

auto count = std::count(begin(v), end(v), 4); // count how many times '4' occurred in the container
auto countIf = std::count_if(begin(v), end(v), [](auto a){ return a > 4; }); // count how many values in the container is greater than '4'
```

### Find elements

```
std::vector v {1, 2, 3, 4, 5, 4, 7, 8, 4, 10, 4, 12};
std::vector f {5, 4, 7};

std::find(begin(v), end(v), 4); // find the first element equal to '4' and return its iterator
std::find_if(begin(v), end(v), [](auto a){ return a > 4; }); // find first element that satisfies criteria and return its iterator 
std::find_if_not(begin(v), end(v), 4); // find the first element that not satisfies criteria and return its iterator

std::find_first_of(begin(v), end(v), begin(f), end(f)); // find the first element that is equal to any element in the second container and return its iterator

std::adjacent_find(begin(v), end(v)); // find in vector the first two elements that are equal and return the first iterator.

std::search(begin(v), end(v), begin(f), end(f)); // find first pattern(vector f) occurrence in vector(v) and return iterator to first element in pattern(vector v).
std::find_end(begin(v), end(v), begin(f), end(f)); //  find last pattern(vector f) occurrence in vector(v) and return iterator to first element in pattern(vector v).
std::search_n(begin(v), end(v), 3, 4); // find first occurrence where next elements are {4, 4, 4} and return its iterator.

std::mismatch(begin(v), end(v), begin(f), end(f)); // find the first element in both containers that is not equal to another f[0]!=v[0] f[1]!=v[1] ...
```
when find or search not find element then return end iterator.
[Better show](https://hackingcpp.com/cpp/std/algorithms.html#adjacent_find)

### For each loop

The old way to loop for every element in the container:
```
for(auto i = container.begin(); i != container.end(); ++i) {
    auto element = *i;
    // do sth
}
```
New way to do the same
```
for(auto element : container) {
    // do sth
}
```
You can also use STL to do it
```
std::vector v {1, 2, 3, 4, 5, 4, 7, 8, 4, 10, 4, 12};

std::for_each(begin(v), end(v), [](auto a){ std::cout << a << " "; }); // show every element in vector.
std::for_each_n(begin(v), 5, [](auto a){ std::cout << a << " "; }); // show 5 first elements in vector.
```

## Algorithms that modify the container

### Copy elements

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::deque<int> d(20);
std::list<int> l;

std::copy(begin(v), end(v), std::back_inserter(l)); // copy elements between begin(v) and end(v) to l
std::copy_if(begin(v), end(v), std::back_inserter(l), [](auto x){ return x > 2; }); // copy elements that are bigger than 2 from vector v to list l
std::copy_n(begin(v), 3, std::back_inserter(l)); // copy first three elements from vector v to list l
std::copy_backward(begin(v), end(v), end(l)); // copy elements between begin(v) and end(v) to list l on its end.
```

### Move elements

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> l;

std::move(begin(v), end(v), std::back_inserter(l)); // do the same as a copy but instead of coping element change element owner
std::move_backward(begin(v), end(v), std::back_inserter(l)); // do the same as copy_backward but instead of coping element change element owner
```

### Create elements

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> l {10, 20, 30, 40, 50, 60, 70, 80};
std::deque<int> d(8);

std::generate( begin(d), end(d), [i=0]() mutable { return i++; }) // execute generator and save result to output.
std::generate_n(std::back_inserter(d),  8,      [](){ std::mt19937 rng; return std::ref(rng); }); // execute generator count times and save result to output

std::transform( begin(v), end(v), begin(l), std::back_inserter(d), [](auto a, auto b){ return a + b; }); // execute process with data from first and second container and save changes to output.
std::transform( begin(v), end(v), std::back_inserter(d), [](auto a){ return a*2; }); // execute the process with data from the container and save the result to the output 
```

### Remove elements

```
std::vector<int> v {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8);
std::list<int> l;

std::remove(begin(v), end(v), 2); // remove all elements that are equal to 2 and return the iterator to the last element (this command leaves garbage that needs to be cleaned with the erase function)
std::remove_if(begin(v), end(v), [](auto a){ return a>=2 && a<=4; }); // remove all elements that meet requirements (this command leaves garbage that needs to be cleaned with the erase function)

std::remove_copy(begin(v), end(v), std::back_inserter(l), 2); // do the same as `remove` but the results are saved to l.
std::remove_copy_if(begin(v), end(v), std::back_inserter(l), [](auto a){ return a>=2 && a<=4; }); // do exactly the same as `remove_if` but result are save to l

std::unique(begin(v), end(v)); // move duplicated elements to the end of the container and return the iterator to the place where start duplication !!! Warning only works when container is sorted, to remove you need to use erase. In this example {1, 2, 3, 4, 5, 6, 7, 8, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8} 
std::unique_copy(begin(v), end(v), std::back_inserter(l)); // works exactly like unique but the result will be in another container.
```

### Change elements

```
std::vector<int> v {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8);
std::list<int> l {2, 4, 6};

std::fill(begin(v), end(v), 2); // replace all elements in container v to `2`
std::fill_n(begin(v), 3, 4); // replace first 3 elements in container v to `4`

std::replace(begin(v), end(v), 2, 22); // replace all elements that are equal to '2' with '22'
std::replace_if(begin(v), end(v), [](auto a){ return a<4;}, 0); // replace all elements that meet requirements to `0`

std::replace_copy(begin(v), end(v), std::back_inserter(l), 2, 22); // do the same as `replace` but the results are saved to l
std::replace_copy_if(begin(v), end(v), std::back_inserter(l), [](auto a){ return a<4; }); // do0 exactly the same as 'replace_if' but result are save to l

std::swap(v[0], v[4]); // replacing the values in the v container at position 0 and 4
std::swap_ranges(begin(l), end(l), begin(v)); // swap elements in container l and container v (elements count are from length between begin(l) and end(l))

std::iter_swap(begin(a), end(a)-1); // works exactly like `swap` but require iterator.
```

### Change the element's order

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> l;

std::reverse(v.begin(), v.end()); // its make container values revere. In this example {8, 7, 6, 5, 4, 3, 2, 1} 

std::rotate(begin(v), begin(v)+4, end(v)) //it takes the iterator from the middle parameter and makes it first then elements on the right and on the end elements that were before the middle. In this example {5, 6, 7, 8, 1, 2, 3, 4}
std::rotate_copy(begin(v), begin(v)+4, end(v), std::back_inserter(l)); // do the same thing but copy the result to the fourth parameter

std::shift_left(begin(v), end(v), 3); // its move elements in container n position left. In this example {4, 5, 6, 7, 8, 0, 0, 0}
std::shift_right(begin(v), end(v), 3); // its move elements in container n position right. In this example {0, 0, 0, 1, 2, 3, 4, 5}

std::random_device device;
std::mt19937 rand(device());
std::shuffle(begin(v), end(v), rand); // its randomize elements order
```

### Get random elements

```
std::string str {"I LiKE_POTAto"};

std::sample(begin(str), end(str), std::ostream_iterator<char>(std::cout, " "), 6, std::mt19937 {std::random_device{}()}); // get '6' random elements from container str and show it in the default output. 
```

## Partitioning algorithms 

### Checking algorithm

```
std::vector<int> v  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::list<int> l    {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
std::array<int, 12> {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

auto is_even = [](auto a){ return a % 2 == 0; };

//Check if container v is partitioned. That means at the beginning elements that satisfy the predicate, then those that do not.
auto a = std::is_partitioned(begin(v), end(v), is_even); // false
auto b = std::is_partitioned(begin(l), end(l), is_even); // true
auto c = std::is_partitioned(begin(l), end(l), is_even); // false
```

### Partitioning algorithms

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::list<int> l1;
std::list<int> l2;

auto is_even = [](auto a){ return a % 2 == 0; };

// change order of elements that at the beginning there are elements that satisfy the predicate, then those that do not.
auto it1 = std::partition(begin(v), end(v), is_even); // return a iterator after last element that satisfy the predicate
it1 = std::partition_point(begin(v), end(v), is_even); // you can find this iterator it without partitioning
std::for_each(begin(v), end(v), [](auto a){ std::cout << a << " "; }); // 10 2 8 4 6 5 7 3 9 1

// change order keeping elements in relative order in the container
auto it2 = std::stable_partition(begin(v), end(v), is_even);
std::for_each(begin(v), end(v), [](auto a){ std::cout << a << " "; }); // 2 4 6 8 10 1 3 7 9

// copy elements that satisfy the predicate to l1 and those that do not to l2
std::partition_copy(begin(v), end(v), std::back_inserter(l1), std::back_inserter(l2), is_even); 
```

## Sorting algorithms

### Checking algorithms

```
struct Point{
    int x;
    int y;
};

std::vector<Point> v {{1, 3}, {1, 4}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}, {1, 4}};
std::list<Point>   l {{0, 0}, {0, 2}, {1, 2}, {2, 2}, {1, 3}, {1, 4}, {4, 1}, {1, 4}, {2, 4}};

auto point_length = [](const Point &a, const Point &b){ 
    auto length_a = std::sqrt((a.x * a.x) + (a.y * a.y));
    auto length_b = std::sqrt((b.x * b.x) + (b.y * b.y));
    
    return length_a < length_b;
};

//Check if the container is sorted
std::is_sorted(begin(v), end(v), point_length); // false
std::is_sorted(begin(l), end(l), point_length); // true

// Find the first element that isn't in order
std::is_sorted_until(begin(v), end(v), point_length); // iterator on {0, 0} because {1, 3} < {1, 4}
std::is_sorted_until(begin(l), end(l), point_length); // iterator on end(l) because list is sorted
```

### Sorting algorithms

```
struct Point{
    int x;
    int y;
};

std::vector<Point> v {{1, 3}, {1, 4}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}, {1, 4}};
std::list<Point> l;

auto point_length = [](const Point &a, const Point &b){ 
    auto length_a = std::sqrt((a.x * a.x) + (a.y * a.y));
    auto length_b = std::sqrt((b.x * b.x) + (b.y * b.y));
    
    return length_a < length_b;
};

// Sort container
std::sort(begin(v), end(v), point_length);          // {{0, 0}, {0, 2}, {1, 2}, {2, 2}, {1, 3}, {1, 4}, {4, 1}, {1, 4}, {2, 4}}

// sort container with keeping relative elements order
std::stable_sort(begin(v), end(v), point_length);   // {{0, 0}, {0, 2}, {1, 2}, {2, 2}, {1, 3}, {1, 4}, {4, 1}, {1, 4}, {2, 4}}

// Sort first n elements
std::partial_sort(begin(v), begin(v) + 4, end(v), point_length); // {0, 0}, {0, 2}, {1, 2}, {2, 2}, {2, 4}, {4, 1}, {1, 4}, {1, 3}, {1, 4}

// find ordered n_nt element and set elements greater than n_nt element on its right, smaller on left but left and right isn't sorted
std::nth_element(begin(v), begin(v) + 4, end(v), point_length); // {1, 2}, {0, 2}, {0, 0}, {2, 2}, {1, 3}, {1, 4}, {1, 4}, {4, 1}, {2, 4}
```

## Binary find algorithms

```
std::vector<int> v {1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 8, 8, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17, 17, 18, 19, 20};

// Check if the element exists in the container
auto exist = std::binary_search(begin(v), end(v), 60); // false
auto exist = std::binary_search(begin(v), end(v), 1); // true

// Find the first element that is not smaller than 3
auto first = std::lower_bound(begin(v), end(v), 3); // return third iterator

// Find the first element that is bigger than 8
auto last = std::upper_bound(begin(v), end(v), 8); // return 15_th iterator

// return lower_bound and upper_bound in one function
auto [first, last] = std::equal_range(begin(v), end(v), 17); // return 23_th and 28_th iterator
```

## Merge Algorithms

```
std::vector<int> odd  {1, 3, 5, 7, 9};
std::vector<int> all  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> merge_sort {-42, 36, 102, 0, 5, 10, 20};
std::list<int> l;

// union elements but keep repeats
std::merge(begin(odd), end(odd), begin(all), end(all), std::back_inserter(l)); // l = {1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9}

// sort element in vector knowing that [first, mid] and [mid, last] are sorted
std::inplace_merge(begin(merge_sort), begin(merge_sort) + 3, end(merge_sort)); // -42, 0, 5, 10, 20, 36, 102
```

## Algorithms operating on sets

```
std::vector<int> even {2, 4, 6, 8, 10};
std::vector<int> odd  {1, 3, 5, 7, 9};
std::vector<int> all  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> some {3, 4, 5, 6};
std::list<int> range;

// Check if all elements in the second container are in the first container
std::includes(begin(all), end(all), begin(even), end(even)); // true
std::includes(begin(even), end(even), begin(some), end(some)); // false

// union elements 
std::set_union(begin(even), end(even), begin(odd), end(odd), std::back_inserter(range)); // range will be 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
std::set_union(begin(even), end(even), begin(all), end(all), std::back_inserter(range)); // range will be 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
std::set_union(begin(even), end(even), begin(some), end(some), std::back_inserter(range)); // range will be 2, 3, 4, 5, 6, 8, 10

// intersection
std::set_intersection(begin(even), end(even), begin(odd), end(odd), std::back_inserter(range)); // range will be empty
std::set_intersection(begin(even), end(even), begin(some), end(some), std::back_inserter(range)); // range will be 4, 6

// symmetric difference
std::set_symmetric_difference(begin(even), end(even), begin(odd), end(odd), std::back_inserter(range)); // range will be 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
std::set_symmetric_difference(begin(even), end(even), begin(some), end(some), std::back_inserter(range)); // range will be 2, 3, 5, 8, 10

// difference
std::set_difference(begin(even), end(even), begin(odd), end(odd), std::back_inserter(range)); // range will be 2, 4, 6, 8, 10
std::set_difference(begin(even), end(even), begin(some), end(some), std::back_inserter(range)); // range will be 2, 8, 10
```

## Min-max algorithms 

### Working on elements

```
std::max(4, 2); // 4
std::min(4, 2); // 2
std::minmax(4, 2); // first = 2; second = 4;

// If the first value is between the second and third then return first if is smaller return the second else return third 
std::clamp(25, 0, 100); // 25
std::clamp(-50, 0, 100); // 0
std::clamp(420, 0, 100); // 100
```

### Working on containers

```
std::vector<int> v {2, 8, 12, 0, -4, 256, 5, 1};

std::max_element(begin(v), end(v)); // 256
std::min_element(begin(v), end(v)); // -4
std::minmax_element(begin(v), end(v)); // first = -4; second = 256
```
## Numeric algorithms

### Generate container 

```
std::vector<char> v(52);
    
auto mid = begin(v) + v.size()/2;

// Fill the range with consecutive values (++)
std::iota(begin(v), mid, 'a'); // a b c d e f g h i j k l m n o p q r s t u v w x y z
std::iota(mid, end(v), 'A'); // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
```

### Reduce algorithm

```
std::vector<long> v{8, 25, 50, 32, 10, 1};

// Subtract all elements in the vector
long subtract = std::reduce(std::execution::unseq, begin(v), end(v), 0, std::minus<long>()); // -126
// product all elements in vector
long product = std::reduce(begin(v), end(v), 1, std::multiplies<long>()); // 3200000
// sum all elements in vector concurrently (multithreaded)
long sum = std::reduce(std::execution::par, begin(v), end(v), 0); // 126
// Divide all elements
auto sum_even = std::reduce(begin(v), end(v), 0,[](long a, long b) {
if (b % 2 == 0) 
    return a + b; 
return a;
}); // 100
```

### Scan algorithms

```     
std::vector<long> v {8, 25, 50, 32, 10, 1};
std::list<long> l;

// sum all elements
std::inclusive_scan(begin(v), end(v), std::back_inserter(l), std::plus<long>()); // 8, 33, 83, 115, 125, 126
// Multiply all elements
std::inclusive_scan(begin(v), end(v), std::back_inserter(l), std::multiplies<long>()); // 8, 200, 10000, 320000, 3200000, 3200000
// Subtract all elements without the last
std::exclusive_scan(begin(v), end(v), std::back_inserter(l), 0, std::minus<long>()); // 0, -8, -33, -83, -115, -125
```

### Adjacent

```
std::vector<long> v {8, 25, 50, 32, 10, 1};
std::list<long> l;

// Adjacent difference
std::adjacent_difference(begin(v), end(v), std::back_inserter(l)); // 8, 17, 25, -18, -22, 0
// Adjacent sum
std::adjacent_difference(begin(v), end(v), std::back_inserter(l), std::plus<long>()); // 8, 33, 75, 82, 42, 11
```

### Transform reduce
$\sum_{i=1}^{n} (a_n * b_n)$

``` 
std::vector<long> a {2, 4, 8, 16, 32};
std::vector<long> b {1, 3, 5, 7, 9};

// 0 + (2 * 1) + (4 * 3) + (8 * 5) + (16 * 7) + (32 * 9)
std::transform_reduce(begin(a), end(a), begin(b), 0); // 454
// 0 - (2 + 1) - (4 + 3) - (8 + 5) - (16 + 7) - (32 + 9)
std::transform_reduce(std::execution::unseq, begin(a), end(a), begin(b), 0, minus, plus); // -37
``` 


## Algorithms complexity 

`m` - range

`n` - given count

`O` - procedure complexity

| Algorithm                 | Worst_possible_complexity                 | Description 
| ---                       | :---:                                     | ---         
| all_of                    | $O*m$                                     | Checks whether all elements in the range satisfy the predicate. 
| any_f                     | $O*m$                                     | Checks if any of the elements in the range satisfies the predicate
| none_of                   | $O*m$                                     | Checks that all elements in the range do not satisfy the predicate
| count                     | $m$                                       | Counts how many elements in the range are equal to the given value
| count_if                  | $O*m$                                     | Counts how many elements in the range satisfy the predicate
| find                      | $m$                                       | Finds the first element in the range that is equal to the given value and returns an iterator to it. If not found return end iterator.
| find_if                   | $O*m$                                     | Finds the first element in the range that satisfies the predicate and returns an iterator to it. If not found return end iterator.
| find_if_not               | $O*m$                                     | Finds the first element in the range that not satisfies the predicate and return an iterator to it. If not found return end iterator.
| find_first_of             | $m$ <br /> $O*m$                          | Finds the first element in the first range that is also in the second range and return iterator to it. You can use the predicate to compare elements. If not found return end iterator.
| adjacent_find             | $m$ <br /> $O*m$                          | Finds the first occurrence of two same elements in the range next to each other and return iterator to first of it. You can use the predicate to compare elements. If not found return end iterator.
| search                    | $m_1*m_2$ <br /> $O*m_1*m_2$              | Finds the first occurrence of all the elements contained in the second range in the correct order in the first range and return the iterator to where it started. You can use the predicate to compare elements. If not found return end iterator.
| search_n                  | $m$ <br /> $O*m$                          | Finds the given number of the given value each next to each other in the range. You can use the predicate to compare elements. If not found return end iterator.
| find_end                  | $m_1-m_2+1$ <br /> $O*(m_1-m_2+1)$        | Finds the last occurrence of all the elements contained in the second range in the correct order in the first range and return the iterator to where it started. You can use the predicate to compare elements. If not found return end iterator.
| mismatch                  | $m$                                       | Compare both ranges and find the first item in both ranges where the values are not equal and return iterators to elements in both ranges. You can use the predicate to compare elements. If not found return end iterator.
| for_each                  | $m$                                       | Executes the given procedure using the elements in the range.
| copy                      | $m$                                       | Copy elements from first range to second range.
| copy_if                   | $O*m$                                     | Copy elements from first that satisfy the predicate to second range.
| copy_n                    | $n$                                       | Copy given number of elements started from first range to second range.
| copy_backward             | $m$                                       | Copy the elements from the first range to the second range at the end of it.
| move                      | $m$                                       | Move elements from first range to second range.
| move_backward             | $m$                                       | Move the elements from the first range to the second range at the end of it.
| generate                  | $m$                                       | Complete the given range with elements using the given procedure.
| generate_n                | $n$                                       | Fill in the given number of places in the range using the given procedure.
| transform                 | $m$                                       | Change the value of the elements in the range using the procedure and previous values
| remove                    | $m$                                       | Remove all elements that equals to given value in range and return iterator to last element. There may be unused data after the last item and you should erase them.
| remove_if                 | $O*m$                                     | Remove all elements that satisfy the predicate in range and return iterator to last element. There may be unused data after the last item and you should erase them.
| remove_copy               | $m$                                       | Remove all elements that equals to given value in first range and save result to second range. 
| remove_copy_if            | $O*m$                                     | Remove all elements that satisfy the predicate in first range and save result to second range. 
| unique                    | $m$ <br /> $O*m$                          | Remove duplicated elements from range and return iterator to last element. You can use the predicate to compare elements. There may be unused data after the last item and you should erase them
| unique_copy               | $m$ <br /> $O*m$                          | Remove duplicated elements from first range and save result to second range. You can use the predicate to compare elements.
| fill                      | $m$                                       | Change the value of all elements to the given value in range.
| fill_n                    | $n$                                       | Change the value of given number of elements to the given value in range.
| replace                   | $m$                                       | Replace all elements that are equal to the given element with the given value in the range.
| replace_if                | $O*m$                                     | Replace all elements that satisfy the predicate with the given value in the range.
| replace_copy              | $m$                                       | Replace all elements that are equal to the given element with the given value in the range and save result to second range.
| replace_copy_if           | $O*m$                                     | Replace all elements that satisfy the predicate with the given value in the range and save result to second range.
| swap                      | $1$                                       | Swap value between two variables.
| swap_ranges               | $m$                                       | Swap elements between two ranges.
| iter_swap                 | $1$                                       | Swap value between two iterators.
| reverse                   | $m/2$                                     | Reverse elements order in range.
| rotate                    | $m$                                       | Divide the range into two parts, the first part from the first iterator to the specified one, the second part from the indicated iterator inclusive to the end. Then arrange the order of the elements so that the second part is placed first, then the first part.
| rotate_copy               | $m$                                       | Divide the first range into two parts, the first part from the first iterator to the specified one, the second part from the indicated iterator inclusive to the end. Then arrange the order of the elements so that the second part is placed first, then the first part and save result to second range.
| shift_left                | $m-n$                                     | Shift all items in the range to the left by the specified number of places. Newly created blanks in the scope will be filled with default constructors. 
| shift_right               | $m-n$                                     | Shift all items in the range to the right by the specified number of places. Newly created blanks in the scope will be filled with default constructors
| shuffle                   | $m$                                       | Randomize the order of items in a range using a random number generator of your choice. Recommended random number generator: <br />`std::random_device rd;` <br /> `std::mt19937 rng(rd());`
| sample                    | $m$                                       | Get a given number of random elements from a range.
| is_partitioned            | $m$                                       | Check if the given range is partitioned. That is, can the range be divided into two parts, the first where the elements satisfy the given predicate and the second where the elements do not satisfy the given predicate.
| partition                 | $m+O*(m/2)$                               | Partitions the given range. Arranges the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return iterator to first element in second part.
| partition_point           | $O*\log m$                                | Gets an iterator over the first element that does not satisfy the predicate. It only works on a partitioned range
| stable_partition          | $m+O*(m*\log m)$                          | Partitions the given range. Arranges the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return iterator to first element in second part. Ensures that the relative order of the elements does not change
| partition_copy            | $m$                                       | Partitions the given first range. Arranges the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return iterator to first element in second part and save results to second range. 
| is_sorted                 | $m$                                       | Check if elements in range are ordered in specific way. You can provide your own comparator.
| is_sorted_until           | $m$                                       | Find the larges range in given range that is sorted. You can provide your own comparator.
| sort                      | $O*(m*\log(m))$                           | Sort elements in range. You can provide your own comparator. 
| stable_sort               | $O*(m*\log(m)^2)$                         | Sort elements in range and ensures that the relative order of the elements does not change. You can provide your own comparator.  
| partial_sort              | $m_1*\log(m_2)$                           | Using the entire range, sort the given number of elements, ignore the rest of the range. You can provide your own comparator. 
| nth_element               | $O*(m*\log(m))$                           | Select the iterator in a range set the remaining elements in such order that elements smaller than it are to its right and larger ones to its left. You can provide your own comparator.
| binary_search             | $\log_2(m)$                               | Check if value exist in range. Work only on sorted range. You can provide your own comparator.
| lower_bound               | $\log_2(m)$                               | Find and return first element not smaller than given element in range. Work only on sorted range. You can provide your own comparator.
| upper_bound               | $\log_2(m)$                               | Find and return first element bigger then given element in range. Work only on sorted range. You can provide your own comparator.
| equal_range               | $2*\log_2(m)$                             | Find and return both upper and lower bonds
| merge                     | $m$                                       | Get elements from first and second range and put them in the third.
| inplace_merge             | $m-1$                                     | Sorts a range that is divided into two sorted sub ranges.
| includes                  | $2*(m_1+m_2-1)$                           | Check whether all elements in the second range are in the first one.
| set_union                 | $2*(m_1+m_2)-1$                           | Get elements from first and second range and put them in the third range without repetitions.
| set_intersection          | $2*(m_1+m_2)-1$                           | Get elements that exist in both the first and second range and put them into the third range.
| set_symmetric_difference  | $2*(m_1+m_2)-1$                           | Get elements from the first range that do not appear in the second as well as elements from the second range that do not appear in the first and put them into the third range. 
| set_difference            | $2*(m_1+m_2)-1$                           | Get elements from the first range that do not appear in the second and put the into the third range.
| max                       | $1$ <br /> $m-1$                          | Compare values and return the biggest value. 
| min                       | $1$ <br /> $m-1$                          | Compare values and return the smallest value.
| minmax                    | $1$                                       | Compare values and return both the biggest and the smallest element.
| clamp                     | $1$                                       | Check whether the given number is within the given range, if so, return this number, if not, return the max or min value of the range depending on which way it exceeded the range.
| max_element               | $m$                                       | Compare elements in the range and return the biggest element.
| min_element               | $m$                                       | Compare elements in the range and return the smallest element.
| minmax_element            | $m$                                       | Compare elements in the range and return the smallest and the biggest element.
| iota                      | $m$                                       | Insert elements into the range starting from the given one and the next ones one larger.
| reduce                    | $m*O$                                     | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on all elements in the range and return the result. 
| inclusive_scan            | $m*O$                                     | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on subsequent elements in the first range and save the results to the second range.
| exclusive_scan            | $m*O-1$                                   | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on subsequent elements in the first range and save the results to the second range starting with given element and ending before last element.
| adjacent_difference       | $m*O-1$                                   | Execute the given function (default subtraction) on each pair of adjacent elements in the first range and write the results to the second range.
| transform_reduce          | $m*O_1*O_2$                               | Execute $\sum^n_{i=1}(a_n*b_n)$ using given ranges (first and second) and result save to third range. You can change algorithm sum and product to another at your discretion. 
