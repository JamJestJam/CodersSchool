# Basic types in c++

|LP|Name|Min size [bajt]|Min value range|
|---|---|---|---|
|1|void|-|-|
|2|*|in 32bit 4bajt, in 64 8bajt|address in memory|
|3|bool|1|true or false|
<td colspan=4>Integers</td>
|4|short|2|from -32 768 to 32 767|
|5|unsigned short|2|from 0 to 65 535|
|6|int|2|from -32 768 to 32 767|
|7|unsigned int|2|from 0 to 65 535|
|8|long|4|from -2 147 483 648 to 2 147 483 647|
|9|unsigned long|4|from 0 to 4 294 967 295|
|10|long long|4|from -9 223 372 036 854 775 808 to 9 223 372 036 854 775 807|
|11|unsigned long long|4|from 0 to 18 446 744 073 709 551 615|
<td colspan=4>Floating point number</td>
|12|float|4|7 decimal digits precision|
|13|double|8|15 decimal digits precision|
|14|long double|8 but often 10|15 decimal digits precision|
<td colspan=4>Strings</td>
|15|char|1|from -128 to 127|
|16|unsigned char|1|from 0 to 255|
|17|sign char|1|from -128 to 127|
|18|string|||

You can also use alias of types for example **`size_t`** which represents size of something.
Aliases are create using keyword using for example **`using fraction = double`**.

You should use "auto" type wherever possible.

# Heap and stock

Memory is divided into two groups Heap and stock. All dynamically created variables are on the heap, anything else are in stock.
Every time you change scope (for example run a function, loop or if segment) you also change stock. Scope is defined by using `{ }` brackets.
You can have reference to a memory in heap but also to stock.
To create dynamic variable you should use pointer.

# Arrays

You can create a array by using **`<type> <name>[<size>]`** where <type> is type of array <name> is name of the variable and size is size of table.

Access to a element of the table is by using **`<name>[element id]`** where <name> is name of the variable and <element id> is a elements number

# Enums

Enum is an enumeration type, its task is to limit the possibility of entering a value for example when you want to show a error type etc.

`
enum class ErrorCode {
    NotFound
    AuthorizationRequired
    OutOfMemory
    TimeOut
};

ErrorCode code = ErrorCode.NotFound;
`

# Reference

Reference allow you to create another name to the same space in the memory for example if you use
`
int a = 2;
int& b = a;
int& c = b;

c = c+b;
`
then variables a, b, c will point to the same space in memory and their finally value will be 4.

The reference is using every time when you don't want to copy data but send only address to value. 
Reference take the same space as pointer (in 32bit processors 4bajt, 64bit 8)
For example when you use a very long array, copying it may take a long time, instead you can use a reference and not copy it, 
in this case it is worth adding the keyword **`const`** in the function parameter so that you don't accidentally change the contents of the array 
if such behavior is not expected.

# Pointers

Pointer is a pointer to a given address in memory

To create a pointer you have to add a **`*`** after a type name for example **`int* number`**.

To read value from a pointer you have to add a **`*`** before a name of variable for example **`cout << *number;`**

Pointers are tricky when its comes to **'consts'** there are two types of const when you use a pointers.
Constant pointer - **`<type>* const <name>`** if you use that you can't change variable's value.
Pointer to constant - **`const <type>* <name>`** if you use that you can't change pointer memory address.
Constant pointer to constant - **`const <type>* const <name>`** if you use that you can't change value or address.


You should always check if a reference is a `nullptr` and if it is you mustn't do any actions on it.
You can check it like this;
`
int* a = nullptr;
if(!a) {
    // do stuff to initialize a or throw an exception
}

// do anything else
`

If you do something like that.
`
int* a = nullptr;
std::cout << *a;
`
then you have undefined behavior and you don't know what can happened. 

A good practise in c++ is to never use `new` and `delete` in your code you should always you smart pointers.

