# Standard template library

This is the base functionality that comes with c++.
You should always use it.

## Containers

### Base info

Cache friendly - thats mean container's data is arranged that every element is near each other<br />
Dynamic size - cointainer can change its size<br />
CC access random element - computation complexity to access a random element<br />
CC add element - computation complexity to add element<br />

| Type      | Cache friendly    | Dynamic size  | CC access random element  | CC add element    |
| ---       | ---               | ---           | ---                       | ---               |
| array     | yes               | no            | N/O                       | N/O               |
| vector    | yes               | yes           | N/O                       | N/O               |
| list      | no                | yes           | N/O                       | N/O               |
| map       | no                | yes           | N/O                       | N/O               |

### Function element access

operator[] - this allows you to access the data using the [] operator by typing the data key inside<br />
front - its give first element in container<br />
back - its give last element in container<br />
at - get element by its position in container<br />

| Type      | operator[]    | front     | back  | at    | 
| ---       | ---           | ---       | ---   | ---   |
| array     | true          | true      | true  | true  |
| vector    | true          | true      | true  | true  |

### Function literators

begin - get first literator<br />
end - get last literator<br />
rbegin - get first reverse literator<br />
rend - get last reverse literator<br />

| Type      | begin | end   | rbegin    | rend  |
| ---       | ---   | ---   | ---       | ---   |
| array     | true  | true  | true      | true  |
| vector    | true  | true  | true      | true  |

### Function capasity

empty - check if container is empty<br />
size - check container's size<br />
max_size - check container max posible size<br />
reverse - reverse storage elements<br />
capacity - show container allocated size<br />
shrink_to_fit - shrink allocated size to elements size<br />

| Type      | empty | size  | max_size  | reverse   | capacity  | shrink_to_fit |
| ---       | ---   | ---   | ---       | ---       | ---       | ---           |
| array     | true  | true  | true      | false     | false     | false         |
| vector    | true  | true  | true      | true      | true      | true          |

### Function modiflers

fill - assign container's values<br />
swap - change container's value<br />
clear - clear container's value<br />


| Type  | fill  | swap  |
| ---   | ---   | ---   |
| true  | true  | true  |

## Funtions

### Foreach loop

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

