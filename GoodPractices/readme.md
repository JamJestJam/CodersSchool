# Fail-Fast

Terminate the program as soon as issues arise. Achieve this by:
- Using exceptions
- Employing assert and static_assert
- Checking essential conditions at the start of functions

# Scout Rule

Maintain code cleanliness by adhering to these principles:
- If you make a mess, clean it up.
- Encourage tidying up others code when you make changes.
- Separate code cleaning into a distinct commit.

# DRY - Don't Repeat Yourself

Avoid code redundancy by encapsulating repetitive logic into functions and invoking them as needed.

# DRTW - Don't Reinvent The Wheel

Leverage existing libraries and tools instead of recreating functionality that already exists.

# KISS - Keep it Simple, Stupid

Prioritize code clarity over complex solutions that may hinder readability.

# YAGNI - You Aren't Gonna Need It

Refuse the urge to write code in anticipation of future needs. Preemptively adding unused code creates unnecessary complexity.

# RTFM - Read the Fucking Manual

Thoroughly review documentation before seeking help with specific functionalities or tools.

# No Tests - Don't Touch

When enhancing code without tests, create tests first to validate your changes. Altering code and tests simultaneously can lead to uncertainty in diagnosing issues.

# CQRS - Command Query Responsibility Segregation

Differentiate between reading (queries) and writing (commands) data operations. Avoid methods that mix both, as "asking a question should not change the answer."

# 90-90 Rule

Recognize that you'll never have enough time, and prioritize tasks accordingly.

# STUPID - Anti-Patterns

This set of rules highlights coding practices to avoid:

## Singleton

Singleton is a design pattern that ensures that there is only one instance of a class.

This is bad because:
- This class is available everywhere in the code
- Such a facility tends to expand very quickly and uncontrollably with new functionalities.
- This is very difficult to test

## Tight coupling 

Tight coupling means that the dependencies between objects are very strong and it is difficult to change them. 
You should create code with as free dependencies as possible.

## Untestability

Code should be tested anytime, anywhere.

## Premature optimization

You should not optimize your code prematurely. 
First, we create tests that determine how the code should work, 
then we write the most basic code that meets the given requirements, 
and only at the end we create benchmarks and compare whether the optimizations we create improve something or just the opposite.

## Indescriptive naming 

Use naming conventions in your code and do not shorten variable names.

## Duplication 

DRY again :).

# SOLID

STUPID is a set of rules that are considered as a god practice

## Single responibility principle

Classes and functions should have only one task to do.

- Split big classes to smallest.
- Use layers (small classes that communicate between neighbors)
- Avoid writing god classes (class that do everything)

## Open/Closed principle 

You should write software that is open for extension but closed for modification

- create as many private variables as possible
- do not use global variables 
- avoid setters (as much as possible)

## Liskov substitution principle 

Objects should be replaceable with instances of their subtypes without altering the correctyness of the program.
(If it looks like a duck, quacks like a duck but needs baterries you probably have the wrong abstaction)

## Interface segregation principle 

Many small general purpose interface are better then single big all in one interface.

## Dependency inversion principle

This rule says that modules should depend on interfaces and not on a specific implementation.
(if you have a function that uses a thermometer, you should not use one specific thermometer, but an interface that has all the functionality of thermometer, because it simplifies testing the functionality in the future.)