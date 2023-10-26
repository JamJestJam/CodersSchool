#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <exception>
#include <vector>
#include "Factorial.hpp"

TEST_CASE("Test case 1", "[useless_test]") {
  int x = 1;
  REQUIRE(x == 1);
}

TEST_CASE("Test case 2", "[useless_test]") {
  int y = 2;
  REQUIRE(y == 2);
}

TEST_CASE("Test case 3", "[useless_test, vector]") {
  std::vector v = {1, 2, 3};
  REQUIRE(v == std::vector{1, 2, 3});
}

TEST_CASE("Testing_vector", "[vector]"){
  std::vector<int> v(5);
  
  REQUIRE(v.size() == 5);
  REQUIRE(v.capacity() >= 5);

  SECTION("Checking resizing to bigger value"){
    v.resize(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("checking resizing to smaller value"){
    v.resize(0);

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() >= 1);
  }
}

TEST_CASE("Test different type of assertion", "[useless_test]"){

  SECTION("Not") {
    std::vector v = {3, 2, 1};
    CHECK_FALSE(v == std::vector {1, 2, 3});
  }
  SECTION("Exception"){
    auto a = [](){};
    auto b = [](){throw std::out_of_range("10");};
    CHECK_NOTHROW(a());
    REQUIRE_THROWS_AS(b(), std::out_of_range);
  }
  SECTION("MATCH"){ 
    using Catch::Matchers::StartsWith;
    auto str = "You don't have to ask where is your god because its right there";
    auto regex = "^You.*there$";

    CHECK_THAT(str, Catch::Matchers::StartsWith("You"));
    CHECK_THAT(str, Catch::Matchers::EndsWith("there"));
    CHECK_THAT(str, Catch::Matchers::ContainsSubstring("is your"));
    CHECK_THAT(str, Catch::Matchers::Matches(regex)); 
  }
}

SCENARIO("Testing factorial function"){  
  auto fun = Factorial;

  WHEN("1"){
    REQUIRE(fun(1) == 1);
  }
  WHEN("2"){
    REQUIRE(fun(2) == 2);
  }
  WHEN("3"){
    REQUIRE(fun(3) == 6);
  }
  WHEN("10"){
    REQUIRE(fun(10) == 3628800);
  }
}

SCENARIO("Test using GENERATORS", "[useless_test, GENERATORS]"){
  GIVEN("Auto generating int i"){
    auto i = GENERATE(2, 4, 6, 8, 10);

    THEN("Check if number is even"){
      REQUIRE(i%2 == 0);
    } 
  }
}

