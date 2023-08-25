# Standard template library

This is the base functionality that comes with c++.
You should always use it.

# Containers

## Sequence containers

Container is sequence when the elements arranged in the order they were added to the container.
Examples of sequence containers:
    - array
    - vector
    - list
    - forward_list
    - deque

## Associative containers

Container is associative when elements inside container are sorted and computation complexity to find a element is O(log n)
Example of associative containers:
    - set
    - map
    - multiset
    - multimap

## Container adaptors
That's containers adopts sequence containers to a specifics task for example to use in FIFO queue.
Example of adaptors containers:
    - stack
    - queue
    - priority_queue 

### Base info

O(1) - complexity constant
O(x) - complexity linear depends of x
O(log x) - complexity logarithmic depends of x
n - size of container
m - size of range
p - complexity of algorithm

Cache friendly - that mean container's data is arranged that every element is near each other<br />
Dynamic size - container can change its size<br />
Stack - is container storage its element on stack<br />

| Type          | Cache friendly    | Dynamic size  | Stack |
| :---:         | :---:             | :---:         | :---: |
| array         | yes               | no            | yes   |
| vector        | yes               | yes           | no    |
| list          | no                | yes           | no    |
| forward_list  | no                | yes           | no    |
| deque         | partial           | yes           | no    |
|               |                   |               |       |
|               |                   |               |       |

### Function element access

`operator[]` - this allows you to access the data using the [] operator by typing the data key inside<br />
`front` - its give first element in container<br />
`back` - its give last element in container<br />
`at` - get element by its position in container<br />

| Type          | `operator[]`  | `front`   | `back`    | `at`  | 
| :---:         | :---:         | :---:     | :---:     | :---: |
| array         | O(1)          | O(1)      | O(1)      | O(1)  |
| vector        | O(1)          | O(1)      | O(1)      | O(1)  |
| list          | ---           | O(1)      | O(1)      | ---   |
| forward_list  | ---           | O(1)      | ---       | ---   |
| deque         | O(1)          | O(1)      | O(1)      | O(1)  |
|               |               |           |           |       |
|               |               |           |           |       |

### Function iterators

`begin` - get first iterator<br />
`end` - get last iterator<br />
`rbegin` - get first reverse iterator<br />
`rend` - get last reverse iterator<br />
you can also use iterators with `c` before its name then iterator is constant

| Type          | `begin`   | `end` | `rbegin`  | `rend`    |
| :---:         | :---:     | :---: | :---:     | :---:     |
| array         | O(1)      | O(1)  | O(1)      | O(1)      |
| vector        | O(1)      | O(1)  | O(1)      | O(1)      |
| list          | O(1)      | O(1)  | O(1)      | O(1)      |
| forward_list  | O(1)      | O(1)  | ---       | ---       |
| deque         | O(1)      | o(1)  | O(1)      | O(1)      |
|               |           |       |           |           |
|               |           |       |           |           |

### Function capacity

`empty` - check if container is empty<br />
`size` - check container's size<br />
`max_size` - check container max possible size<br />
`reserve` - reserve space needed to storage more elements<br />
`capacity` - show container allocated size<br />
`shrink_to_fit` - shrink allocated size to elements size<br />

| Type          | `empty`   | `size`    | `max_size`    | `reserve` | `capacity`    | `shrink_to_fit`   |
| :---:         | :---:     | :---:     | :---:         | :---:     | :---:         | :---:             |
| array         | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
| vector        | O(1)      | O(1)      | O(1)          | O(n)      | O(1)          | O(n)              |
| list          | O(1)      | O(1)      | O(1)          | ---       | ---           | ---               |
| forward_list  | O(1)      | ---       | O(1)          | ---       | ---           | ---               |
| deque         | O(1)      | O(1)      | O(1)          | ---       | ---           | O(n)              |
|               |           |           |               |           |               |                   |
|               |           |           |               |           |               |                   |

### Function modifiers

`fill` - assign container's values<br />
`swap` - change container's elements<br />
`clear` - clear container's value<br />
`insert` - insert element in specific place in container<br />
`insert_after` - insert element after iterator<br /> 
`insert_range` - insert elements in specific place in container<br />
`insert_range_after` - insert elements after iterator<br />
`emplace` - insert element before specific place in container<br />
`emplace_after` - insert element after specific place in container<br />
`erase` - remove element from container<br />
`erase_after` - remove element from container<br />
`push_back` - add new element on the end of the container<br />
`push_front` - insert element on the beginning of the container<br />
`emplace_back` - create new element and insert it to the end of container<br />
`emplace_front` - create new element and insert it to the beginning of container<br />
`append_range` - add elements on the end of the container<br />
`prepend_range` - add elements on the beginning of the container<br />
`pop_back` - remove last element<br />
`pop_front` - remove first element<br />
`resize` - change container size<br />

| Type          | `fill`    | `swap`    | `clear`   | `insert`          | `inser_after` | `insert_range`    | `insert_range_after`  | `emplace` | `emplace_after`   | `erase`   | `erase_after` | `push_back`   | `push_front`  | `emplace_back`    | `emplace_front`   | `append_range`    | `prepend_range`   | `pop_back`    | `pop_front`   | `resize`  |
| :---:         | :---:     | :---:     | :---:     | :---:             | :---:         | :---:             | :---:                 | :---:     | :---:             | :---:     | :---:         | :---:         | :---:         | :---:             | :---:             | :---:             | :---:             | :---:         | :---:         | :---:     |
| array         | O(1)      | O(1)      | ---       | ---               | ---           | ---               | ---                   | ---       | ---               | ---       | ---           | ---           | ---           | ---               | ---               | ---               | ---               | ---           | ---           | ---       |
| vector        | ---       | O(1)      | O(n)      | O(m) O(n)+O(m)    | ---           | O(m) O(n)+O(m)    | ---                   | O(n)      | ---               | O(n)      | ---           | O(1) O(n)     | ---           | O(1) O(n)         | ---               | O(m) O(n)+O(m)    | ---               | O(1)          | ---           | O(1) O(m) |
| list          | ---       | O(1)      | O(n)      | O(m)              | ---           | O(m)              | ---                   | O(1)      | ---               | O(m)      | ---           | O(1)          | O(1)          | O(1)              | O(1)              | O(m)              | O(m)              | O(1)          | O(1)          | O(m)      |
| forward_list  | ---       | O(1)      | O(n)      | ---               | O(m)          | ---               | O(m)                  | ---       | O(1)              | ---       | O(m)          | ---           | ---           | ---               | O(1)              | ---               | O(m)              | ---           | O(1)          | O(m)      |
| deque         | ---       | O(1)      | O(n)      | O(m) O(n)+O(m)    | ---           | O(m) O(n)+O(m)    | ---                   | O(1)      | ---               | O(m)      | ---           | O(1)          | O(1)          | O(1)              | O(1)              | O(m)              | O(m)              | O(1)          | O(1)          | O(m)      |
|               |           |           |           |                   |               |                   |                       |           |                   |           |               |               |               |                   |                   |                   |                   |               |               |           |
|               |           |           |           |                   |               |                   |                       |           |                   |           |               |               |               |                   |                   |                   |                   |               |               |           |
|               |           |           |           |                   |               |                   |                       |           |                   |           |               |               |               |                   |                   |                   |                   |               |               |           |

### Function operation

`merge` - merge two sorted containers<br />
`splice` - get data from first container and transfer it to another<br />
`splice_after` - get data from first container and transfer it to another<br />
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
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |

# Lambda

Lambda is a way to create single line function. For example 
```
auto a = 0;
auta function = [&a](int b) mutable { a+=b }

function(2);
function(4);

std::cout << a; // a = 6
```
Inside bracket `[]` you can give a variable that are available in every literation, keyword `mutable` makes variable inside `[]` possible to change, 
inside `()` bracket are function parameters and in `{}` function body.

# Algorithms

I will describe a few of most common used algorithms. 
[Algorithm library]("https://en.cppreference.com/w/cpp/algorithm")

Most common algorithm variation
If name of algorithm end `*_if` then algorithm don't take a value but function for example.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::find(v.begin(), v.end(), 5); // find 5
std::find_if(v.begin(), v.end(), [](auto x){ return x > 5; }); // find bigger than 5
```

When name end `*_copy` then algorithm do not edit container but create new one.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
std::vector destination(12);

std::reverse(v.begin(), v.end()); // reverse vector v
std::reverse_copy(v.begin(), v.end(), destination.begin()); // reverse vector v and save changes to vector destination
```

And when name end `*_n` then algorithm works only on n elements
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::fill(v.begin(), v.end(), -1); // fill vector with value -1
std::fill_n(v.begin(), 10, -2); // fill first 10 elements with value -2
```

In c++ 20 when you want to work on every element in container you can use `std::ranges`.
```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::sort(v.begin(), v.end());
std::ranges::sort(v);
```

When you use c tables or you want to  do thinks different you can use global functions instead of container's;
```
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

std::sort(begin(v), end(v));
```

### Iterators

This iterator deals with streams 
`std::ostream_iterator<T>(stream, delimer)`
you can use this to for example show container to default output.
```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};

std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "), [](int a){ return a > 2; }); // show on default output every element that is greater then 2
```

This iterator add new element to container
`std::back_inserter(container)`;
You can use if you use algorithm that create new elements and you want to add them to container.

## Algorithms that not edit container

### Check condition

```
std::vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

auto all = std::all_of(begin(v), end(v), [](auto a){ return a > 0; }) // check if all values in container are greater then 0
auto any = std::any_of(begin(v), end(v), [](auto a){ return a > 11; }) // check if any value if greater then 11
auto none = std::none_of(begin(v), end(v), [](auto a){ return a > 0; }) // check if none of values in container is greater then 0;
```

### Count elements

```
std::vector v {1, 2, 3, 4, 5, 4, 7, 8, 4, 10, 4, 12};

auto count = std::count(begin(v), end(v), 4); // count how many times '4' occurred in the container
auto countIf = std::count_if(begin(v), end(v), [](auto a){ return a > 4; }); // count how many values in container is greater then '4'
```

### Find elements

```
std::vector v {1, 2, 3, 4, 5, 4, 7, 8, 4, 10, 4, 12};
std::vector f {5, 4, 7};

std::find(begin(v), end(v), 4); // find first element equals to '4' and return its iterator
std::find_if(begin(v), end(v), [](auto a){ return a > 4; }); // find first element that satisfies criteria and return its iterator 
std::find_if_not(begin(v), end(v), 4); // find first element that not satisfies criteria and return its iterator

std::find_first_of(begin(v), end(v), begin(f), end(f)); // find first element that is equals to any element in secound container and return its iterator

std::adjacent_find(begin(v), end(v)); // find in vector first two elements that are equal and return first iterator.

std::search(begin(v), end(v), begin(f), end(f)); // find first pattern(vector f) occurrence in vector(v) and return iterator to first element in pattern(vector v).
std::find_end(begin(v), end(v), begin(f), end(f)); //  find last pattern(vector f) occurrence in vector(v) and return iterator to first element in pattern(vector v).
std::search_n(begin(v), end(v), 3, 4); // find first occurrence where next elements are {4, 4, 4} and return its iterator.

std::mismatch(begin(v), end(v), begin(f), end(f)); // find first element in both containers that not equals to another f[0]!=v[0] f[1]!=v[1] ...
```
when find or search not find element then return end iterator.
[Better show](https://hackingcpp.com/cpp/std/algorithms.html#adjacent_find)

### For each loop

Old way to loop for every element in container:
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

## Algorithms that modify container

### Copy elements

```
std::copy
std::copy_if
std::copy_n
std::copy_backward
```

### Move elements

```
std::move
std::move_backward
```

### Create elements

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> l {10, 20, 30, 40, 50, 60, 70, 80};
std::deque<int> d(8);

//              output            generator
std::generate(  begin(d), end(d), [i=0]() mutable { return i++; }) // execute generator and save result to output.
//              output                  count   generator
std::generate_n(std::back_inserter(d),  8,      [](){ std::mt19937 rng; return std::ref(rng); }); // execute generator count times and save result to output

//              start container end     secound   output                   process
std::transform( begin(v),       end(v), begin(l), std::back_inserter(d),   [](auto a, auto b){ return a + b; }); // execute process with data from first and secound container and save changes to output.
//              container       end     output                  process
std::transform( begin(v),       end(v), std::back_inserter(d),  [](auto a){ return a*2; }); // execute process with data from container and save result to output 

```

### Remove elements

```
std::vector<int> v {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8);
std::list<int> l;

std::remove
std::remove_if

std::remove_copy
std::remove_copy_if

std::unique(begin(v), end(v)); // move duplicated elements to the end of container and return iterator to place where start duplication !!!warning only works when container is sorted, to remove you need to use erase. In this example {1, 2, 3, 4, 5, 6, 7, 8, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8} 
std::unique_copy(begin(v), end(v), std::back_inserter(l)); // works exacly like unique but result will be in another container.
```

### Change elements

```
std::fill
std::fill_n

std::replace
std::replace_if

std::replace_copy
std::replace_copy_if

std::swap
std::swap_ranges

std::iterswap
```

### Change elements order

```
std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> l;

std::reverse(v.begin(), v.end()); // its make container values revere. In this example {8, 7, 6, 5, 4, 3, 2, 1} 

std::rotate(begin(v), begin(v)+4, end(v)) // its take iterator from middle parameter and makes its first then elements on right and on the end elements that was before middle. In this example {5, 6, 7, 8, 1, 2, 3, 4}
std::rotate_copy(begin(v), begin(v)+4, end(v), std::back_inserter(l)); // do exactly the same think but copy result to forth parameter

std::shift_left(begin(v), end(v), 3); // its move elements in container n position left. In this example {4, 5, 6, 7, 8, 0, 0, 0}
std::shift_right(begin(v), end(v), 3); // its move elements in container n position right. In this example {0, 0, 0, 1, 2, 3, 4, 5}

std::mt19937 rand(std::random device);
std::shuffle(begin(v), end(v), rand); // its randomize elements order
```

### Get random elements

```
std::sample
```

