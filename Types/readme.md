# Basic types in c++

<table>
  <tr>
    <th>LP</th>
    <th>Name</th>
    <th>Min size [bajt]</th>
    <th>Min value range</th>
  </tr>
  <tr>
    <td>1</td>
    <td>void</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td>2</td>
    <td>*</td>
    <td>in 32bit 4bajt, in 64 8bajt</td>
    <td>address in memory</td>
  </tr>
  <tr>
    <td>3</td>
    <td>bool</td>
    <td>1</td>
    <td>true or false</td>
  </tr>
  <tr>
    <td colspan="3">Integers</td>
  </tr>
  <tr>
    <td>4</td>
    <td>short</td>
    <td>2</td>
    <td>from -32 768 to 32 767</td>
  </tr>
  <tr>
    <td>5</td>
    <td>unsigned short</td>
    <td>2</td>
    <td>from 0 to 65 535</td>
  </tr>
  <tr>
    <td>6</td>
    <td>int</td>
    <td>2</td>
    <td>from -32 768 to 32 767</td>
  </tr>
  <tr>
    <td>7</td>
    <td>unsigned int</td>
    <td>2</td>
    <td>from 0 to 65 535</td>
  </tr>
  <tr>
    <td>8</td>
    <td>long</td>
    <td>4</td>
    <td>from -2 147 483 648 to 2 147 483 647</td>
  </tr>
  <tr>
    <td>9</td>
    <td>unsigned long</td>
    <td>4</td>
    <td>from 0 to 4 294 967 295</td>
  </tr>
  <tr>
    <td>10</td>
    <td>long long</td>
    <td>4</td>
    <td>from -9 223 372 036 854 775 808 to 9 223 372 036 854 775 807</td>
  </tr>
  <tr>
    <td>11</td>
    <td>unsigned long long</td>
    <td>4</td>
    <td>from 0 to 18 446 744 073 709 551 615</td>
  </tr>
  <tr>
    <td colspan="3">Floating point number</td>
  </tr>
  <tr>
    <td>12</td>
    <td>float</td>
    <td>4</td>
    <td>7 decimal digits precision</td>
  </tr>
  <tr>
    <td>13</td>
    <td>double</td>
    <td>8</td>
    <td>15 decimal digits precision</td>
  </tr>
  <tr>
    <td>14</td>
    <td>long double</td>
    <td>8 but often 10</td>
    <td>15 decimal digits precision</td>
  </tr>
  <tr>
    <td colspan="3">Strings</td>
  </tr>
  <tr>
    <td>15</td>
    <td>char</td>
    <td>1</td>
    <td>from -128 to 127</td>
  </tr>
  <tr>
    <td>16</td>
    <td>unsigned char</td>
    <td>1</td>
    <td>from 0 to 255</td>
  </tr>
  <tr>
    <td>17</td>
    <td>sign char</td>
    <td>1</td>
    <td>from -128 to 127</td>
  </tr>
  <tr>
    <td>18</td>
    <td>string</td>
    <td></td>
    <td></td>
  </tr>
</table>

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

```
enum class ErrorCode {
    NotFound
    AuthorizationRequired
    OutOfMemory
    TimeOut
};

ErrorCode code = ErrorCode.NotFound;
```

# Reference

Reference allow you to create another name to the same space in the memory for example if you use
```
int a = 2;
int& b = a;
int& c = b;

c = c+b;
```
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
```
int* a = nullptr;
if(!a) {
    // do stuff to initialize a or throw an exception
}

// do anything else
```

If you do something like that.
```
int* a = nullptr;
std::cout << *a;
```
then you have undefined behavior and you don't know what can happened. 

A good practise in c++ is to never use `new` and `delete` in your code you should always you smart pointers.

