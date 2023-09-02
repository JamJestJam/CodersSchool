# Functions

Functions are parts of programs, that have names and you can call them using their names and giving arguments, for example.
```
int DoStuf(int a, int b) {
    return a + b;
}

int c = DoStuf(4, 6);
```

The function should be short (less than 10 lines) and it should be a lot of them.
If the function returns a variable you should always check the result. Not checking results is known as bad practice.

# If segment

You can think of that as asking questions for example 'if the variable is equal to 0' or 'if it is a variable' etc.
If segments are written this way
```
if (condition) {
    // do something 
}
```
You can combine conditions by using &&, || or keywords and, etc.
```
if(condition && condition2 || condition3) {
    // do something
}
```
There is some tricky in there If you use && and the first condition is false program will not check the second condition because no matter what the result will be always false.
The same is true if you use || and the first condition is true then the second will not be checked.

You can also combine if for example
```
If (condition1) {
    // do something 1
} else if (condition2) {
    // do something 2
} else {
    // do something 3
}
```

# Loops

There are two basic types of loop in C++ `for` and `while`.
We use loops when we want to do something more than once without writing the same code multiple times.

### while

You should use this loop when you don't know how many times loot will be executed.
```
while (condition) {
    // do something
}
```

### for
For loop is used when you know exactly how many times the loop will be executed.
```
for(initialize_variable; condition; change_variable) {
    // do something
}
```

# Variable range

The range is defined by two brackets `{` and `}` and every variable outside this bracket will be invisible for example.
```
int a = 2;
int b = 3;
{
    int c = 4;
    // I can see a, b and c
}

// I can see a and b but I can't see c
```

There are also global variables that are visible everywhere.
Global variables are known as bad practices in 99% of cases.

```
int global_value = 5;

void force() {
    // I can see global_value
}

int main() {
    // I can see global_value
}
```

### name hiding

In c++ is impossible to have two variables with the same name in the same scope, however is possible to have it in different ranges. 
If there are two variables with the same name the closed one will be visible.
You can access hiding global variables by using `::variable_name`.

# Const

The keyword `const` makes variable value impossible to change.
You should always you keyword `const` wherever possible.
