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

### vector

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
| array         | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| vector        | ---       | ---       | ---               | ---       | ---           | ---       | ---       | ---           |
| list          | O(n)+O(m) | O(1)      | ---               | O(n)      | O(n)*p        | O(n)      | O(n)      | O(n*log n)    |
| forward_list  | O(n)+O(m) | ---       | O(1)              | O(n)      | O(n)*p        | O(n)      | O(n)      | O(n*log n)    |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |
|               |           |           |                   |           |               |           |           |               |

## Functions

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

