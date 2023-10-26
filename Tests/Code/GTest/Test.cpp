#include "gtest/gtest.h"
#include "Factorial.hpp"
#include <vector>
#include <exception>

TEST(UselessTest, Test1){
  int x=1;
  ASSERT_EQ(x, 1);
}
TEST(UselessTest, Test2){
  int y=2;
  ASSERT_EQ(y, 2);
}

TEST(UselessTest, Test3){
  std::vector v = {1, 2, 3};
  std::vector l = {1, 2, 3};
  ASSERT_EQ(v, l);
}

TEST(Factorial, HandlesZeroInput){
  ASSERT_EQ(Factorial(1), 1);
  ASSERT_EQ(Factorial(2), 2);
  ASSERT_EQ(Factorial(3), 6);
  ASSERT_EQ(Factorial(10), 3628800);
}

struct VectorFixture : public ::testing::Test {
  std::vector<int> v {0,0,0,0,0};
};

TEST_F(VectorFixture, ResizeToBiggerValue){
 v.resize(10);

 ASSERT_EQ(v.size(), 10);
}

TEST_F(VectorFixture, ResizeToSmallerValue){
 v.resize(0);

 ASSERT_EQ(v.size(), 0);
}
