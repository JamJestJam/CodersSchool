# Functions

Functions are parts of programs, that have name and you can call them using its name and giving arguments, for example.
`
int DoStuf(int a, int b) {
    return a + b;
}

int c = DoStuf(4, 6);
`

Function should be short (less then 10 lines) and it should be a lot of them.
If function return variable you should always check the result. Do not checking result is know as bad practice.

# If segment

You can thing of that as asking questions for example 'if the variable is equal to 0' or 'if it is a variable' etc.
If segments are write this way
`
if (condition) {
    // do something 
}
`
You can combine conditions by using &&, || or keywords and, or etc.
`
if(condition && condition2 || condition3) {
    // do something
}
`
There is some tricky in there if you use && and first condition if false program will not check the second condition because no mater what the result will be always false.
The same is if you use || and the first condition is true then second will not be checked.

You cane also combine if for example
`
If (condition1) {
    // do something 1
} else if (condition2) {
    // do something 2
} else {
    // do something 3
}
`

# Loops

There are two basic types of loop in c++ `for` and `while`.
We use loops when we want to do something more than once without writing the same code multiple times.

### while

You should use this loop when you don't know how many times loot will be execute.
`
while (condition) {
    // do something
}
`

### for
For loop is using when you know exactly how many times loop will be executed.
`
for(initialize_variable; condition; change_variable) {
    // do something
}
`

# Variable range

Range is defined by two brackets `{` and `}` and every variable outside this bracket will be invisible for example.
`
int a = 2;
int b = 3;
{
    int c = 4;
    // I can see a, b and c
}

// I can see a and b but I can't see c
`

There are also global variables that are visible in everywhere.
Global variables are know as bad practice in 99% cases.

`
int global_value = 5;

void force() {
    // I can see global_value
}

int main() {
    // I can see global_value
}
`

### name hiding

In c++ is impossible to have two variables with same name in the same scope, however is possible to have it in tho different ranges. 
If there is two variables with the same name the closed one will be visible.
You can access to hiding global variable by using `::variable_name`.

# Const

Keyword `const` makes variable value impossible to change.
You should always you keyword `const` wherever possible.


