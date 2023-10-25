# Catch2

[documentation](https://github.com/catchorg/Catch2)

## Create test

Method 1.
```
// create new test case
TEST_CASE("name_of_test", "[test_tags]"){
    //space to define testing variables

    SECTION("section_name"){
        //space to do assertion
        //!every variable in test case is new in every section.
    }
}
```

Method 2.
```
SCENARIO("test description", "[test_tags]"){
    GIVEN("description of test data"){
        // initialize data
        WHEN("Description of the activities performed"){
            // do actions on data
            THEN("description of what is checked"){
                // assert
            }
        }
    }
}
```

## Assertion

```
// check whether the expresion is met, if not, do not check further
REQUIRE(a == b);
// check whether the expresion is met even if you do not perform further checks
CHECK(a == b);

// works as above but denies the expresion
REQUIRE_FALSE(a == b);
CHECK_FALSE(a == b);

// check if expresion throw a error
REQUIRE_THROW_AS(fun(), exception);
CHECK_THROW_AS(fun(), exception);

// check if expresion do not throw a error
REQUIRE_NOTHROW(fun);
CHECK_NOTHROW(fun);

//check expresion using custom matcher
REQUIRE_THAT(a, matcher);
CHECK_THAT(a, matcher);
```

## Matchers

```
// string matches
StartsWith() // check if string start with argument
EndsWith() // check if string end with argument
ContainsSubstring() // check if string contain argument
Matches() // check if string meets regex
```

## GENERATORS

```
// create multiple test cases every with different value.
// if multiple GENERATORS are created every posible set of values will be created.
GENERATE(value1, value2, value3);
```

# GTest

[Documentation](https://github.com/google/googletest/blob/main/docs/index.md)

# Create test

```
TEST(name, idk){
    //test body
}
```
