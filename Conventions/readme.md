# C++ Popular Code Conventions

Here are some widely-accepted code conventions for C++ that can help enhance the readability and maintainability of your code:

## Code Formatting

- **Line Length**: Keep lines within 80 characters, or 120 characters when necessary.
- **Function Length**: Aim for functions that are around 10 lines, with some flexibility (+/- 5 lines).
- **Indentation**: Use additional indentation for each scope, with exceptions for `switch`, `namespace`, and access modifiers.

## Naming Conventions

- **Variables**: Use lowerCamelCase, following a noun + optional adjective convention.
- **Global Variables and const Variables**: Use ONLY CAPITAL LETTERS.
- **Private Variables in Classes**: Add _ after the variable name. Avoid using _ before variable names, as these are reserved for the compiler.
- **Classes and Structures**: Use UpperCamelCase, following a noun + optional adjective convention.
- **Functions**: Use lowerCamelCase, following a verb + optional adverb or noun convention.
- **File Names**: There are various conventions. Prioritize reflecting the file's content and maintain consistency within the project.

## Other

- **Short Names**: Avoid using short variable names except for some common exceptions such as `i`, `j`, and `l` for loop indices, `it` for iterators, `el` or `elem` for elements, and `lhs` and `rhs` for left-hand side and right-hand side.
- **Bracket Formatting**: Use Allman style for functions and K&R style for if statements.
- **Sticking `&` and `*`**: Attach `&` and `*` to the type.

## Clang format

It is highly recommended to use a code formatting tool like clang-format to ensure consistency. 

To use clang-format, run the following command in your console:

`clang-format -style="file with style" -i *.cpp *.hpp`