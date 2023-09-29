# Standard Template Library (STL)

The Standard Template Library is an essential part of C++. It's highly recommended to make use of its functionality.

# Containers

## Sequence containers

Sequence containers maintain elements in the order they were added.

Examples of sequence containers:
- `array`
- `vector`
- `list`
- `forward_list`
- `deque`

## Associative containers

Associative containers maintain elements in order and have a complexity of $O(log(n))$ for element retrieval.

Examples of associative containers:
- `set`
- `map`
- `multiset`
- `multimap`

## Non-associative containers

Non-associative containers use hashing to storage elements.

Examples of non-associative containers:
- `unordered_set`
- `unordered_map`
- `unordered_multiset`
- `unordered_multimap`

## Container adaptors

Container adaptors modify containers to serve specific tasks, such as a FIFO queue.

Examples of adaptor containers:
- `stack`
- `queue`
- `priority_queue` 

### Key terminology

- $O(1)$ - Constant time complexity.
- $O(n)$ - Linear time complexity.
- $O(log n)$ - Logarithmic time complexity.
- $n$ - Size of the container.
- $m$ - Size of the range.
- $p$ - Complexity of the algorithm.

#### Additional Definitions:

- Cache friendly - This means the container's data is arranged such that each element is located close to others in memory.
- Dynamic size - This means that containers can change in size

| Type               | Cache friendly    | Dynamic size  | Description 
| :---:              | :---:             | :---:         | :---:
| array              | yes               | no            | Stores data in a fixed memory location.<br /> cannot be resized.
| vector             | yes               | yes           | It organizes data efficiently by storing it within a continuous block of memory, managing access through pointers. These pointers, denoting the start, end of the allocated block, and the end of the utilized section, are stored on the stack. If the container's capacity is surpassed, the data is intelligently relocated to a larger memory allocation.
| list               | no                | yes           | Within this container, elements are stored as nodes, each equipped with pointers referencing the preceding and succeeding items. On the stack, pointers to both the first and last elements are retained, enabling swift insertions at both the front and rear of the container.
| forward_list       | no                | yes           | In this container, elements are represented as nodes, with pointers directed to the next items in the sequence. A pointer to the first element is maintained on the stack, facilitating rapid insertions at the container's outset.
| deque              | partial           | yes           | The data is organized in this structure as a series of segments, with each segment functioning as a compact array. Stack pointers are employed to keep tabs on the commencement and conclusion of these collections, as well as the current positions within individual segments. This configuration empowers swift data access at both extremities of the collection and within the segments themselves. Thanks to this design, the deque efficiently accommodates the addition and removal of elements at both the front and back of the queue.
| map                | no                | yes           | Data is structured within this container using a key-value paradigm, organized into a binary tree format. Crucially, it ensures that identical keys cannot coexist within the container.
| multimap           | no                | yes           | Data is structured within this container using a key-value paradigm, organized into a binary tree format.
| set                | no                | yes           | Elements are organized in the form of a binary tree, and no two identical records can coexist within the container
| multiset           | no                | yes           | Elements are organized in the form of a binary tree.
| unordered_map      | no                | yes           | Data is organized within this container using a key-value structure, which is implemented as a hash table. Each element placed into the container is hashed, determining its designated storage location. Crucially, it enforces the constraint that no two identical keys can exist simultaneously within the container.
| unordered_multimap | no                | yes           | Data is organized within this container using a key-value structure, which is implemented as a hash table. Each element placed into the container is hashed, determining its designated storage location.
| unordered_set      | no                | yes           | Within this container, elements are structured using a hash table format. Each element undergoes hashing, determining its designated storage location. Importantly, this container ensures that no two identical records can coexist within it.
| unordered_multiset | no                | yes           | Within this container, elements are structured using a hash table format. Each element undergoes hashing, determining its designated storage location.
| stack              | depends           | yes           | This container employs a Last-In-First-Out (LIFO) structure for data storage. It typically uses a deque as its default implementation, but it allows for customization and substitution with other data structures as needed.
| queue              | depends           | yes           | This container employs a First-In-First-Out (FIFO) structure for data storage. It typically uses a deque as its default implementation, but it allows for customization and substitution with other data structures as needed.
| priority_queue     | depends           | yes           | This container organizes data within an ordered structure, and the order can be customized to your specific preferences. By default, it employs a vector as its underlying implementation, but you have the flexibility to alter or replace it with other data structures as needed.
|                    |                   |               | 

### Function element access

- `operator[]` - This allows you to access data using the `[]` operator by specifying the data key inside.
- `front` -  It retrieves the first element in the container
- `back` - It retrieves the last element in the container.
- `at` - You can obtain an element by specifying its position within the container.

| Type               | `operator[]`         | `front`   | `back`    | `at`       
| :---:              | :---:                | :---:     | :---:     | :---:     
| array              | $O(1)$               | $O(1)$    | $O(1)$    | $O(1)$    
| vector             | $O(1)$               | $O(1)$    | $O(1)$    | $O(1)$    
| list               | ---                  | $O(1)$    | $O(1)$    | ---       
| forward_list       | ---                  | $O(1)$    | ---       | ---       
| deque              | $O(1)$               | $O(1)$    | $O(1)$    | $O(1)$    
| map                | $O(log(n))$          | ---       | ---       | $O(log(n))$
| multimap           | ---                  | ---       | ---       | ---
| set                | ---                  | ---       | ---       | ---
| multiset           | ---                  | ---       | ---       | ---
| unordered_map      | $O(1)$ <br /> $O(n)$ | ---       | ---       | $O(1)$ <br /> $O(n)$     
| unordered_multimap | ---                  | ---       | ---       | ---       
| unordered_set      | ---                  | ---       | ---       | ---       
| unordered_multiset | ---                  | ---       | ---       | ---       
| stack              | ---                  | ---       | ---       | ---       
| queue              | ---                  | ---       | ---       | ---       
| priority_queue     | ---                  | ---       | ---       | ---       
|                    |                      |           |           |

### Function iterators

- `begin`- It retrieves the first iterator.
- `end` -  It retrieves the last iterator.
- `rbegin` - This function provides the first reverse iterator
- `rend` - This function provides the last reverse iterator

Moreover, if you prefix these iterator functions with 'c', you can create constant iterators, which prevent modification of the container's data through those iterators.

| Type               | `begin`   | `end`     | `rbegin`  | `rend`    |
| :---:              | :---:     | :---:     | :---:     | :---:     |
| array              | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| vector             | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| list               | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| forward_list       | $O(1)$    | $O(1)$    | ---       | ---       |
| deque              | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| map                | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| multimap           | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| set                | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| multiset           | $O(1)$    | $O(1)$    | $O(1)$    | $O(1)$    |
| unordered_map      | $O(1)$    | $O(1)$    | ---       | ---       |
| unordered_multimap | $O(1)$    | $O(1)$    | ---       | ---       |
| unordered_set      | $O(1)$    | $O(1)$    | ---       | ---       |
| unordered_multiset | $O(1)$    | $O(1)$    | ---       | ---       |
| stack              | ---       | ---       | ---       | ---       |
| queue              | ---       | ---       | ---       | ---       |
| priority_queue     | ---       | ---       | ---       | ---       |
|                    |           |           |           |           |

### Function capacity

- `empty` - Checks whether the container is empty.
- `size` - Returns the current size (number of elements) in the container.
- `max_size` - Provides the maximum possible size the container can reach.
- `reserve` - Reserves memory space to accommodate more elements, helping to reduce reallocations.
- `capacity` - Shows the currently allocated size of the container.
- `shrink_to_fit` - Shrinks the allocated memory size to match the actual size of the elements in the container, optimizing memory usage.

| Type               | `empty`   | `size`    | `max_size`    | `reserve` | `capacity`    | `shrink_to_fit`   |
| :---:              | :---:     | :---:     | :---:         | :---:     | :---:         | :---:             |
| array              | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| vector             | $O(1)$    | $O(1)$    | $O(1)$        | $O(n)$    | $O(1)$        | $O(n)$            |
| list               | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| forward_list       | $O(1)$    | ---       | $O(1)$        | ---       | ---           | ---               |
| deque              | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | $O(n)$            |
| map                | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| multimap           | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| set                | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| multiset           | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| unordered_map      | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| unordered_multimap | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| unordered_set      | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| unordered_multiset | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| stack              | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| queue              | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
| priority_queue     | $O(1)$    | $O(1)$    | $O(1)$        | ---       | ---           | ---               |
|                    |           |           |               |           |               |                   |

### Function modifiers

- `fill` - Assign values to the container's elements.
- `swap` - Exchange the elements of two containers.
- `clear` - clear container's value
- `insert` - Insert an element at a specific position in the container.
- `insert_after` - Insert an element after a specified iterator.
- `insert_range` - Insert a range of elements at a specific position in the container.
- `insert_range_after` - Insert a range of elements after a specified iterator.
- `insert_or_assign` - Insert an element into the container or update its value if the key already exists.
- `emplace` - Create an element and insert it before a specific position in the container.
- `emplace_after` - Create an element and insert it after a specific position in the container.
- `emplace_hint` - Efficiently create and insert an item into the container with a hint.
- `try_emplace` - Create and insert an element into the container only if the key doesn't already exist.
- `erase` - Remove an element from the container.
- `erase_after` - Remove an elements following a specified range.
- `push_back` - Insert an element at the end of the container.
- `push_front` - Insert an element at the beginning of the container.
- `emplace_back` - Create a new element and insert it at the end of the container.
- `emplace_front` - Create a new element and insert it at the beginning of the container.
- `append_range` - Insert elements copy to the end of the container from a range.
- `prepend_range` - Insert elements copy to the begining of the container from a range.
- `pop_back` -  Remove the last element from the container.
- `pop_front` - Remove the first element from the container.
- `resize` - Change the size of the container.

| Type               | `fill`    | `swap`    | `clear`   | `insert`             | `insert_after` | `___insert_range___`         | `insert_range_after`  | `insert_or_assign` | `emplace`            | `emplace_after`   | `emplace_hint`            | `try_emplace`             | `____erase____` | `erase_after` | `push_back`   | `push_front`  | `emplace_back`    | `emplace_front`   | `append_range`            | `prepend_range`   | `pop_back`    | `pop_front`   | `resize`  
| :---:              | :---:     | :---:     | :---:     | :---:                | :---:          | :---:                        | :---:                 | :---:              | :---:                | :---:             | :---:                     | :---:                     | :---:           | :---:         | :---:         | :---:         | :---:             | :---:             | :---:                     | :---:             | :---:         | :---:         | :---:     
| array              | $O(1)$    | $O(1)$    | ---       | ---                  | ---            | ---                          | ---                   | ---                | ---                  | ---               | ---                       | ---                       | ---             | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| vector             | ---       | $O(1)$    | $O(n)$    | $O(m) O(n)+O(m)$     | ---            | $O(m)$ <br /> $O(n)+O(m)$    | ---                   | ---                | $O(n)$               | ---               | ---                       | ---                       | $O(n)$          | ---           | $O(1)$ $O(n)$ | ---           | $O(1) O(n)$       | ---               | $O(m)$ <br> $O(n)+O(m)$   | ---               | $O(1)$        | ---           | $O(1)$ <br /> $O(m)$
| list               | ---       | $O(1)$    | $O(n)$    | $O(m)$               | ---            | $O(m)                        | ---                   | ---                | $O(1)$               | ---               | ---                       | ---                       | $O(m)$          | ---           | $O(1)$        | $O(1)$        | $O(1)$            | $O(1)$            | $O(m)$                    | $O(m)$            | $O(1)$        | $O(1)$        | $O(m)$      
| forward_list       | ---       | $O(1)$    | $O(n)$    | ---                  | $O(m)$         | ---                          | $O(m)$                | ---                | ---                  | $O(1)$            | ---                       | ---                       | ---             | $O(m)$        | ---           | ---           | ---               | $O(1)$            | ---                       | $O(m)$            | ---           | $O(1)$        | $O(m)$      
| deque              | ---       | $O(1)$    | $O(n)$    | $O(m) O(n)+O(m)$     | ---            | $O(m) O(n)+O(m)$             | ---                   | ---                | $O(1)$               | ---               | ---                       | ---                       | $O(m)$          | ---           | $O(1)$        | $O(1)$        | $O(1)$            | $O(1)$            | $O(m)$                    | $O(m)$            | $O(1)$        | $O(1)$        | $O(m)$      
| map                | ---       | $O(1)$    | $O(n)$    | $O(log(n))$          | ---            | $O(m*log(n))$                | ---                   | $O(log(n))$        | $O(log(n))$          | ---               | $O(1)$ <br /> $O(log(n))$ | $O(1)$ <br /> O(log(n))$  | $O(log(m+n))$   | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| multimap           | ---       | $O(1)$    | $O(n)$    | $O(log(n))$          | ---            | $O(m*log(n))$                | ---                   | $O(log(n))$        | $O(log(n))$          | ---               | $O(1)$ <br /> $O(log(n))$ | ---                       | $O(log(m+n))$   | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| set                | ---       | $O(1)$    | $O(n)$    | $O(lob(n))$          | ---            | $O(m*log(n))$                | ---                   | $O(log(n))$        | $O(log(n))$          | ---               | $O(1)$ <br /> $O(log(n))$ | $O(1)$ <br /> O(log(n))$  | $O(log(m+n))$   | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| multiset           | ---       | $O(1)$    | $O(n)$    | $O(log(n))$          | ---            | $O(m*log(n))$                | ---                   | $O(log(n))$        | $O(log(n))$          | ---               | $O(1)$ <br /> $O(log(n))$ | ---                       | $O(log(m+n))$   | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| unordered_map      | ---       | $O(1)$    | $O(n)$    | $O(1)$ <br /> $O(n)$ | ---            | $O(m)$ <br /> $O(n+m+1)$     | ---                   | ---                | $O(1)$ <br /> $O(n)$ | ---               | $O(1)$ <br /> $O(n)$      | $O(1)$ <br /> $O(n)$      | $O(n)$          | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| unordered_multimap | ---       | $O(1)$    | $O(n)$    | $O(1)$ <br /> $o(n)$ | ---            | $O(m)$ <br /> $O(n+m+1)$     | ---                   | ---                | $O(1)$ <br /> $O(n)$ | ---               | $O(1)$ <br /> $O(n)$      | ---                       | $O(n)$          | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| unordered_set      | ---       | $O(1)$    | $O(n)$    | $O(1)$ <br /> $O(n)$ | ---            | $O(m)$ <br /> $O(n+m+1)$     | ---                   | ---                | $O(1)$ <br /> $O(n)$ | ---               | $O(1)$ <br /> $O(n)$      | ---                       | $O(n)$          | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
| unordered_multiset | ---       | $O(1)$    | $O(n)$    | $O(1)$ <br /> $O(n)$ | ---            | $O(m)$ <br /> $O(n+m+1)$     | ---                   | ---                | $O(1)$ <br /> $O(n)$ | ---               | $O(1)$ <br /> $O(n)$      | ---                       | $O(n)$          | ---           | ---           | ---           | ---               | ---               | ---                       | ---               | ---           | ---           | ---       
|                    |           |           |           |                      |                |                              |                       |                    |                      |                   |                           |                           |                 |               |               |               |                   |                   |                           |                   |               |               |           

### Function operation

- `merge` - Merge two sorted containers.
- `splice` - Transfer data from the first container to another.
- `splice_after` - Transfer data from the first container to another.
- `remove` - Remove elements equal to a specified parameter.
- `remove_if` - Remove elements that meet a specified condition.
- `reverse` - Reverse the order of elements in the container.
- `unique` - Remove duplicated elements in the container.
- `sort` - Sort the container.

| Type          | `_____merge_____` | `splice`  | `splice_after`    | `remove`  | `remove_if`   | `reverse` | `unique`  | `____sort____`
| :---:         | :---:             | :---:     | :---:             | :---:     | :---:         | :---:     | :---:     | :---:         
| list          | $O(n)+O(m)$       | $O(1)$    | ---               | $O(n)$    | $O(n*p)$      | $O(n)$    | $O(n)$    | $O(n*log(n))$ 
| forward_list  | $O(n)+O(m)$       | ---       | $O(1)$            | $O(n)$    | $O(n*p)$      | $O(n)$    | $O(n)$    | $O(n*log(n))$ 
|               |                   |           |                   |           |               |           |           |               

### Lookup functions

- `count` - Returns the number of elements in a container that satisfy the predicate.
- `find` - Finds elements with keys equal to the given value.
- `contains` - Checks if elements with a specific key exist in the container.
- `equal_range` - Finds and returns both the upper and lower bounds.
    - `lower_bound` -  Finds and returns the first element not smaller than the given element in the range. This works only on sorted ranges, and you can provide your own comparator.
    - `upper_bound` - Finds and returns the first element bigger than the given element in the range. This also works only on sorted ranges, and you can provide your own comparator.

| Type                  | `____count____`       | `___find___`          | `contains`            | `equal_range`         | `lower_bound` | `upper_bound`
| :---:                 | :---:                 | :---:                 | :---:                 | :---:                 | :---:         | :---:
| map                   | $O(log(n)+m)$         | $O(log(n))$           | $O(log(n))$           | $O(log(n))$           | $O(log(n))$   | $O(log(n))$   
| multimap              | $O(log(n)+m)$         | $O(log(n))$           | $O(log(n))$           | $O(log(n))$           | $O(log(n))$   | $O(log(n))$   
| set                   | $O(log(n)+m)$         | $O(log(n))$           | $O(log(n))$           | $O(log(n))$           | $O(log(n))$   | $O(log(n))$  
| multiset              | $O(log(n)+m)$         | $O(log(n))$           | $O(log(n))$           | $O(log(n))$           | $O(log(n))$   | $O(log(n))$  
| unordered_map         | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(m)$ <br /> $O(n)$  | ---           | ---
| unordered_multimap    | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(m)$ <br /> $O(n)$  | ---           | ---
| unordered_set         | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(m)$ <br /> $O(n)$  | ---           | ---
| unordered_multiset    | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(1)$ <br /> $O(n)$  | $O(m)$ <br /> $O(n)$  | ---           | ---
|                       |                       |                       |                       |                       |               |   

### Hash function

- `bucket_count` - Returns the number of buckets in the container.
- `max_bucket_count` -  Returns the maximum number of buckets that can be allocated.
- `bucket_size` - Returns the number of elements in a specific bucket.
- `bucket` - Retrieves a value and returns the ID of the bucket where it should be stored.
- `load_factor` - Returns the average number of elements inside buckets in a given container.
- `max_load_factor` -  Returns or sets the maximum load factor (if the factor is exceeded, it increases the number of buckets).
- `rehash` - Sets the number of buckets in the container (the count can be larger).
- `reserve` - Sets the number of buckets to optimize for a given load factor.

| Type                  | `bucket_count`        | `max_bucket_count`    | `bucket_size`             | `bucket`              | `load_factor`         | `max_load_factor`     | `rehash`                  | `reserve`
| :---:                 | :---:                 | :---:                 | :---:                     | :---:                 | :---:                 | :---:                 | :---:                     | :---:
| unordered_map         | $O(1)$                | $O(1)$                | $O(m)$-number of buckets  | $O(1)$                | $O(1)$                | $O(1)$                | $O(n)$ <br /> $O(n^2)$    | $O(n)$ <br /> $O(n^2)$
| unordered_multimap    | $O(1)$                | $O(1)$                | $O(m)$-number of buckets  | $O(1)$                | $O(1)$                | $O(1)$                | $O(n)$ <br /> $O(n^2)$    | $O(n)$ <br /> $O(n^2)$
| unordered_set         | $O(1)$                | $O(1)$                | $O(m)$-number of buckets  | $O(1)$                | $O(1)$                | $O(1)$                | $O(n)$ <br /> $O(n^2)$    | $O(n)$ <br /> $O(n^2)$
| unordered_multiset    | $O(1)$                | $O(1)$                | $O(m)$-number of buckets  | $O(1)$                | $O(1)$                | $O(1)$                | $O(n)$ <br /> $O(n^2)$    | $O(n)$ <br /> $O(n^2)$
|                       |                       |                       |                           |                       |                       |                       |                           |

### Queue functions

- `top` - Retrieve access to the last element in the queue.
- `push` - Add an element to the queue.
- `push_range` - Add multiple elements to the queue.
- `emplace` - Construct an element and add it to the queue.
- `pop` - Remove the last element in the queue.
- `swap` -  Exchange elements of the container.

| Type              | `top`     | `push`    | `push_range`  | `emplace` | `pop`     | `swap`    
| :---:             | :---:     | :---:     | :---:         | :---:     | :---:     | :---:
| stack             | $?$       | $?$       | $?$           | $?$       | $?$       | $?$
| queue             | $?$       | $?$       | $?$           | $?$       | $?$       | $?$
| priority_queue    | $?$       | $?$       | $?$           | $?$       | $?$       | $?$
|                   |           |           |               |           |           |

# Streams

Streams serve as a straightforward means for moving data between a program and external entities or other software components.

We interact with streams by employing the << operator for reading and the >> operator for writing data.

Streams can be categorized into different types, including input streams, output streams, input-output streams, and buffer streams:
- Input streams are employed for retrieving data from external sources.
- Output streams are utilized to transmit data to external destinations.
- Input-output streams facilitate both sending and receiving data.
- Buffer streams are responsible for managing buffers, enhancing the efficiency of data transfer and processing.

### input stream (istream)           
- `cin` - Retrieves data from the default input.
- `ifstream` - Reads data from a file.
- `istringstream` - Reads data from a string.

### output stream (ostream)
- `cout`, `ceer`, `clog` - Sends data to the default output.
- `ofstream` - Writes data to a file.
- `ostringstream` - Sends data to a string.

### input-output stream (iostream)
- `fstream` - Can both save and read data to/from a file.
- `stringstream` - Can both read and send data to a string.

### buffor stream (streambuf)
- `stringbuf` - String management buffer.
- `filebuf` - File management buffer.

## File stream functions

### Most used functions:
- `is_open` - Checks if the file is open by program.
- `put` - Writes a single character to the file.
- `get` - Reads a single character from the file.
- `peek` - Reads a single character from the file without moving the pointer.
- `write` - Writes a single block of data to a file.
- `read` - Reads a single block of data from a file.om a file.
- `seekp` - Sets the pointer to a designated location.
- `tellp` - Gets the current pointer location.
- `getline()` - Retrieves data from the file, starting from the pointer and ending at the specified character (default is '\n').

### File open modes:
- `trunc` - Deletes all content from the file.
- `in` - Sets the file stream to read-only mode.
- `out` - Sets the file stream to write-only mode.
- `ate` - Sets the file pointer to the end of the file.
- `app` - Appends data at the end of the file.
- `binary` - Enables reading and writing in binary mode.

### Example

```
const std::string fileName = "file.txt"; // file name
std::fstream stream (fileName, stream.out | stream.app); // open file in write and append mode.

if(stream.is_open()){ // check if file is open
    stream << "Some data to save"; // write string
    stream.put('\n'); // write char
}

stream.close(); // close file
stream.open(fileName, stream.in); // open file in read mode

if(stream.is_open()){
    std::string line;
    while(std::getline(stream, line)) // read a line of text from file and save in to variable line.
        std::cout << line << "\n";
}
```

### Binary example

```
struct Student { // struct POD
    char firstName[30];
    char lastName[30];
    size_t index;
    double arverage;
};


Student student {"Marek", "Michura", 12380, 5.0}; // create a new POD structure
const std::string fileName = "student.bin"; // file name
std::fstream stream (fileName, stream.app | stream.binary); // open file in write and binary mode.

if(stream.is_open()){ // check if file is open
    stream.write(reinterpret_cast<char*>(&student), sizeof(Student)); // write data
}

stream.close(); // close file
stream.open(fileName, stream.in | stream.binary); // open file in read and binary mode
Student readStudent; // prepare space to save data

if(stream.is_open()){
    stream.read(reinterpret_cast<char*>(&readStudent), sizeof(Student));
}
```


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

// If the first value is between the second and third then return first if is smaller return the second else return the third 
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

| Algorithm                 | Worst_possible_complexity                    | Description 
| ---                       | :---:                                        | ---         
| all_of                    | $O(O*m)$                                     | Checks whether all elements in the range satisfy the predicate. 
| any_f                     | $O(O*m)$                                     | Checks if any of the elements in the range satisfies the predicate
| none_of                   | $O(O*m)$                                     | Checks that all elements in the range do not satisfy the predicate
| count                     | $O(m)$                                       | Counts how many elements in the range are equal to the given value
| count_if                  | $O(O*m)$                                     | Counts how many elements in the range satisfy the predicate
| find                      | $O(m)$                                       | Finds the first element in the range that is equal to the given value and returns an iterator to it. If not found return end iterator.
| find_if                   | $O(O*m)$                                     | Finds the first element in the range that satisfies the predicate and returns an iterator to it. If not found return end iterator.
| find_if_not               | $O(O*m)$                                     | Finds the first element in the range that does not satisfy the predicate and returns an iterator to it. If not found return end iterator.
| find_first_of             | $O(m)$ <br /> $O(O*m)$                       | Finds the first element in the first range that is also in the second range and returns an iterator to it. You can use the predicate to compare elements. If not found return end iterator.
| adjacent_find             | $O(m)$ <br /> $O(O*m)$                       | Finds the first occurrence of two same elements in the range next to each other and returns the iterator to the first of it. You can use the predicate to compare elements. If not found return end iterator.
| search                    | $O(m_1*m_2)$ <br /> $O(O*m_1*m_2)$           | Finds the first occurrence of all the elements contained in the second range in the correct order in the first range and returns the iterator to where it started. You can use the predicate to compare elements. If not found return end iterator.
| search_n                  | $O(m)$ <br /> $O(O*m)$                       | Finds the given number of the given value each next to each other in the range. You can use the predicate to compare elements. If not found return end iterator.
| find_end                  | $O(m_1-m_2+1)$ <br /> $O(O*(m_1-m_2+1))$     | Finds the last occurrence of all the elements contained in the second range in the correct order in the first range and return the iterator to where it started. You can use the predicate to compare elements. If not found return end iterator.
| mismatch                  | $O(m)$                                       | Compare both ranges and find the first item in both ranges where the values are not equal and return iterators to elements in both ranges. You can use the predicate to compare elements. If not found return end iterator.
| for_each                  | $O(m)$                                       | Executes the given procedure using the elements in the range.
| copy                      | $O(m)$                                       | Copy elements from first range to second range.
| copy_if                   | $O(O*m)$                                     | Copy elements from the first range that satisfy the predicate to the second range.
| copy_n                    | $O(n)$                                       | Copy the given number of elements starting from the first range to the second range.
| copy_backward             | $O(m)$                                       | Copy the elements from the first range to the second range at the end of it.
| move                      | $O(m)$                                       | Move elements from first range to second range.
| move_backward             | $O(m)$                                       | Move the elements from the first range to the second range at the end of it.
| generate                  | $O(m)$                                       | Complete the given range with elements using the given procedure.
| generate_n                | $O(n)$                                       | Fill in the given number of places in the range using the given procedure.
| transform                 | $O(m)$                                       | Change the value of the elements in the range using the procedure and previous values
| remove                    | $O(m)$                                       | Remove all elements that equal the given value in the range and return the iterator to the last element. There may be unused data after the last item and you should erase them.
| remove_if                 | $O(O*m)$                                     | Remove all elements that satisfy the predicate in range and return the iterator to the last element. There may be unused data after the last item and you should erase them.
| remove_copy               | $O(m)$                                       | Remove all elements that are equal to the given value in the first range and save the result to the second range. 
| remove_copy_if            | $O(O*m)$                                     | Remove all elements that satisfy the predicate in the first range and save the result to the second range. 
| unique                    | $O(m)$ <br /> $O(O*m)$                       | Remove duplicated elements from the range and return the iterator to the last element. You can use the predicate to compare elements. There may be unused data after the last item and you should erase them
| unique_copy               | $O(m)$ <br /> $O(O*m)$                       | Remove duplicated elements from the first range and save the result to the second range. You can use the predicate to compare elements.
| fill                      | $O(m)$                                       | Change the value of all elements to the given value in the range.
| fill_n                    | $O(n)$                                       | Change the value of the given number of elements to the given value in the range.
| replace                   | $O(m)$                                       | Replace all elements that are equal to the given element with the given value in the range.
| replace_if                | $O(O*m)$                                     | Replace all elements that satisfy the predicate with the given value in the range.
| replace_copy              | $O(m)$                                       | Replace all elements that are equal to the given element with the given value in the range and save the result to the second range.
| replace_copy_if           | $O(O*m)$                                     | Replace all elements that satisfy the predicate with the given value in the range and save the result to the second range.
| swap                      | $O(1)$                                       | Swap value between two variables.
| swap_ranges               | $O(m)$                                       | Swap elements between two ranges.
| iter_swap                 | $O(1)$                                       | Swap value between two iterators.
| reverse                   | $O(m/2)$                                     | Reverse elements order in range.
| rotate                    | $O(m)$                                       | Divide the range into two parts, the first part from the first iterator to the specified one, and the second part from the indicated iterator inclusive to the end. Then arrange the order of the elements so that the second part is placed first, then the first part.
| rotate_copy               | $O(m)$                                       | Divide the first range into two parts, the first part from the first iterator to the specified one, and the second part from the indicated iterator inclusive to the end. Then arrange the order of the elements so that the second part is placed first, then the first part, and save the result to the second range.
| shift_left                | $O(m-n)$                                     | Shift all items in the range to the left by the specified number of places. Newly created blanks in the scope will be filled with default constructors. 
| shift_right               | $O(m-n)$                                     | Shift all items in the range to the right by the specified number of places. Newly created blanks in the scope will be filled with default constructors
| shuffle                   | $O(m)$                                       | Randomize the order of items in a range using a random number generator of your choice. Recommended random number generator: <br />`std::random_device rd;` <br /> `std::mt19937 rng(rd());`
| sample                    | $O(m)$                                       | Get a given number of random elements from a range.
| is_partitioned            | $O(m)$                                       | Check if the given range is partitioned. That is, can the range be divided into two parts, the first where the elements satisfy the given predicate and the second where the elements do not satisfy the given predicate.
| partition                 | $O(m+O*(m/2))$                               | Partitions the given range. Arrange the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return an iterator to the first element in the second part.
| partition_point           | $O(O*\log m)$                                | Gets an iterator over the first element that does not satisfy the predicate. It only works on a partitioned range
| stable_partition          | $O(m+O*(m*\log m))$                          | Partitions the given range. Arrange the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return an iterator to the first element in the second part. Ensures that the relative order of the elements does not change
| partition_copy            | $O(m)$                                       | Partitions the given first range. Arrange the elements in such an order that first there are elements that satisfy the given predicate and then those that do not and return an iterator to the first element in the second part and save results to the second range. 
| is_sorted                 | $O(m)$                                       | Check if elements in the range are ordered in a specific way. You can provide your comparator.
| is_sorted_until           | $O(m)$                                       | Find the largest range in the given range that is sorted. You can provide your comparator.
| sort                      | $O(O*(m*\log(m)))$                           | Sort elements in range. You can provide your comparator. 
| stable_sort               | $O(O*(m*\log(m)^2))$                         | Sort elements in range and ensure that the relative order of the elements does not change. You can provide your comparator.  
| partial_sort              | $O(m_1*\log(m_2))$                           | Using the entire range, sort the given number of elements, and ignore the rest of the range. You can provide your comparator. 
| nth_element               | $O(O*(m*\log(m)))$                           | Select the iterator in a range and set the remaining elements in such order that elements smaller than it is to its right and larger ones to its left. You can provide your comparator.
| binary_search             | $O(\log_2(m))$                               | Check if value exist in range. Work only on sorted range. You can provide your comparator.
| lower_bound               | $O(\log_2(m))$                               | Find and return the first element not smaller than the given element in the range. Work only on sorted range. You can provide your comparator.
| upper_bound               | $O(\log_2(m))$                               | Find and return the first element bigger than then given element in the range. Work only on sorted range. You can provide your comparator.
| equal_range               | $O(2*\log_2(m))$                             | Find and return both upper and lower bonds
| merge                     | $O(m)$                                       | Get elements from the first and second range and put them in the third.
| inplace_merge             | $O(m-1)$                                     | Sorts a range that is divided into two sorted subranges.
| includes                  | $O(2*(m_1+m_2-1))$                           | Check whether all elements in the second range are in the first one.
| set_union                 | $O(2*(m_1+m_2)-1)$                           | Get elements from the first and second range and put them in the third range without repetitions.
| set_intersection          | $O(2*(m_1+m_2)-1)$                           | Get elements that exist in both the first and second range and put them into the third range.
| set_symmetric_difference  | $O(2*(m_1+m_2)-1)$                           | Get elements from the first range that do not appear in the second as well as elements from the second range that do not appear in the first and put them into the third range. 
| set_difference            | $O(2*(m_1+m_2)-1)$                           | Get elements from the first range that do not appear in the second and put them into the third range.
| max                       | $O(1)$ <br /> $O(m-1)$                       | Compare values and return the biggest value. 
| min                       | $O(1)$ <br /> $O(m-1)$                       | Compare values and return the smallest value.
| minmax                    | $O(1)$                                       | Compare values and return both the biggest and the smallest element.
| clamp                     | $O(1)$                                       | Check whether the given number is within the given range, if so, return this number, if not, return the max or min value of the range depending on which way it exceeded the range.
| max_element               | $O(m)$                                       | Compare elements in the range and return the biggest element.
| min_element               | $O(m)$                                       | Compare elements in the range and return the smallest element.
| minmax_element            | $O(m)$                                       | Compare elements in the range and return the smallest and the biggest element.
| iota                      | $O(m)$                                       | Insert elements into the range starting from the given one and the next ones one larger.
| reduce                    | $O(m*O)$                                     | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on all elements in the range and return the result. 
| inclusive_scan            | $O(m*O)$                                     | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on subsequent elements in the first range and save the results to the second range.
| exclusive_scan            | $O(m*O-1)$                                   | Using the given algorithm (default addition) and starting from the given element (default 0), execute the given algorithm on subsequent elements in the first range and save the results to the second range starting with given element and ending before last element.
| adjacent_difference       | $O(m*O-1)$                                   | Execute the given function (default subtraction) on each pair of adjacent elements in the first range and write the results to the second range.
| transform_reduce          | $O(m*O_1*O_2)$                               | Execute $\sum(a_n*b_n)$ using given ranges (first and second) and result save to third range. You can change the algorithm sum and product to another at your discretion. 
