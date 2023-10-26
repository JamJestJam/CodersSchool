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

| Braking assertion | Not braking assertion | Description 
| ---               | ---                   | ---
| REQUIRE           | CHECK                 | Check whether the expression is met
| REQUIRE_FALSE     | CHECK_FALSE           | Check whether the expression is not met
| REQUIRE_THROW_AS  | CHECK_THROW_AS        | check if expression throw a exception
| REQUIRE_NOTHROW   | CHECK_NOTHROW         | check if expression do not throw a exception
| REQUIRE_THAT      | CHECK_THAT            | check expression using custom matcher

## Matchers

```
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
TEST(TestedObjectName, TestName){
    //Test body
}

struct DataEnableToMultipleTests : public ::testing::Test {
    //initialize data
}

TEST_F(StructName, TestName){
    //Test body
}
```

## Assertion

| Braking assertion                         | Not braking assertion                     | Description
| ---                                       | ---                                       | ---
| ASSERT_TRUE(condition);	                | EXPECT_TRUE(condition);	                | Check if condition is true
| ASSERT_FALSE(condition);	                | EXPECT_FALSE(condition);	                | Check if condition is false
| ASSERT_EQ(val1, val2);	                | EXPECT_EQ(val1, val2);	                | Check if val1 and val2 are equal
| ASSERT_NE(val1, val2);	                | EXPECT_NE(val1, val2);	                | Check if val1 and val2 are not equal
| ASSERT_LT(val1, val2);	                | EXPECT_LT(val1, val2);	                | Check if val1 is smaller then val2
| ASSERT_LE(val1, val2);	                | EXPECT_LE(val1, val2);	                | Check if val1 is smaller or equal val2
| ASSERT_GT(val1, val2);	                | EXPECT_GT(val1, val2);	                | Check if val1 is bigger then val2
| ASSERT_GE(val1, val2);	                | EXPECT_GE(val1, val2);	                | check if val1 is bigger or equal val2
| ASSERT_THAT(value, matcher);	            | EXPECT_THAT(value, matcher);	            | value matches matcher
| ASSERT_THROW(statement, exception_type);  | EXPECT_THROW(statement, exception_type);  | throws an exception of the given type
| ASSERT_ANY_THROW(statement);	            | EXPECT_ANY_THROW(statement);	            | throws an exception of any type
| ASSERT_NO_THROW(statement);	            | EXPECT_NO_THROW(statement);	            | doesn't throw any exception

