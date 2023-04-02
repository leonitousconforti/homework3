#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(StackTest, PushAndPop) {
  Stack s(5);
  EXPECT_NO_THROW(s.push(1));
  EXPECT_NO_THROW(s.push(2));
  EXPECT_NO_THROW(s.push(3));
  EXPECT_NO_THROW(s.push(4));
  EXPECT_NO_THROW(s.push(5));
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
}

TEST_F(StackTest, IsEmptyAndSize) {
  Stack s;
  EXPECT_TRUE(s.isEmpty());
  s.push(1);
  EXPECT_EQ(s.size(), 1);
  s.push(2);
  EXPECT_EQ(s.size(), 2);
  s.pop();
  EXPECT_EQ(s.size(), 1);
  s.pop();
  EXPECT_TRUE(s.isEmpty());
}

TEST_F(StackTest, Sort) {
  Stack s{5, 2, 8, 1, 9};
  s.sort();
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 8);
  EXPECT_EQ(s.pop(), 9);
}

TEST_F(StackTest, Reverse) {
  Stack s{1, 2, 3, 4, 5};
  s.reverse();
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
}

TEST_F(StackTest, Filter) {
  Stack s{1, 2, 3, 4, 5};
  s.filter([](int x) { return x % 2 == 0; });
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 4);
}

TEST_F(StackTest, Map) {
  Stack s{1, 2, 3, 4, 5};
  s.map([](int x) { return x * x; });
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 9);
  EXPECT_EQ(s.pop(), 16);
  EXPECT_EQ(s.pop(), 25);
}

TEST_F(StackTest, Reduce) {
  Stack s{1, 2, 3, 4, 5};
  int sum = s.reduce([](int acc, int x) { return acc + x; }, 0);
  EXPECT_EQ(sum, 15);
}
