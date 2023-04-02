#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};

TEST(StackTest, TestPushOverflow) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  EXPECT_FALSE(s.isFull()) << "Stack is full, but should not be";
  s.push(6);
  EXPECT_TRUE(s.isFull()) << "Stack should be full, but is not";
}

TEST_F(StackTest, PushAndPop) {
  Stack s;
  s.push(1);
  s.push(2);
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

TEST(StackTest, OverflowEvenThoughCapacityNotReached) {
  Stack s(3);
  EXPECT_TRUE(s.isEmpty());
  EXPECT_FALSE(s.isFull());
  s.push(1);
  s.push(2);
  s.push(3);
  EXPECT_FALSE(s.isEmpty());
  EXPECT_TRUE(s.isFull());
  EXPECT_THROW(s.push(4), std::overflow_error);
}

TEST(StackTest, UnderflowOnPeekWhenNotEmpty) {
  Stack s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  EXPECT_EQ(s.peek(), 3);
  s.pop();
  EXPECT_EQ(s.peek(), 2);
  s.pop();
  EXPECT_EQ(s.peek(), 1);
  s.pop();
  EXPECT_THROW(s.peek(), std::underflow_error);
}

TEST(StackTest, TestIndexOf) {
  Stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);

  // Test existing element
  int idx = s.indexOf(20);
  EXPECT_EQ(idx, 1);

  // Test non-existing element
  idx = s.indexOf(40);
  EXPECT_EQ(idx, -1);
}

TEST(StackTest, OverflowWhenCapacityNotReached) {
  Stack s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  EXPECT_THROW(s.push(4), std::overflow_error);
}

TEST(StackTest, UnderflowWhenPeekNotEmpty) {
  Stack s(3);
  s.push(1);
  EXPECT_EQ(s.peek(), 1);
  EXPECT_THROW(s.peek(), std::underflow_error);
}

TEST(StackTest, PeekReturnsWrongValue) {
  Stack s(3);
  s.push(1);
  EXPECT_EQ(s.peek(), 1);
  s.push(2);
  EXPECT_EQ(s.peek(), 2);
}

TEST(StackTest, IndexOfNotWorkingProperly) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(2);
  s.push(4);
  EXPECT_EQ(s.indexOf(2), 3);
}

TEST(StackTest, IndexOfReturnsWrongValueWhenValueNotFound) {
  Stack s(5);
  s.push(1);
  s.push(2);
  EXPECT_EQ(s.indexOf(3), -1);
}

TEST(StackTest, IndexOfSometimesReturnsWrongValue) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(2);
  s.push(4);
  EXPECT_EQ(s.indexOf(2), 1);
}

TEST(StackTest, IsStackActuallyFull) {
  Stack s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  EXPECT_TRUE(s.isFull());
}

TEST(StackTest, CapacityOfStackMayNotReturnCorrectly) {
  Stack s(3);
  EXPECT_EQ(s.getCapacity(), 3);
  s.push(1);
  s.push(2);
  EXPECT_EQ(s.getCapacity(), 3);
}

TEST(StackTest, CapacityMightNotBeUpdatingCorrectly) {
  Stack s(3);
  EXPECT_EQ(s.getCapacity(), 3);
  s.updateCapacity(5);
  EXPECT_EQ(s.getCapacity(), 5);
}

TEST(StackTest, ClearMayNotBeClearingAsIntended) {
  Stack s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  s.clear();
  EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, LeftBranchOffByOne) {
  Stack s(3);
  EXPECT_FALSE(s.isFull());
  EXPECT_TRUE(s.isEmpty());
  EXPECT_EQ(s.size(), 0);
}

TEST(StackTest, SortFunctionGoesPastEndOfArray) {
  Stack s(5);
  s.push(5);
  s.push(2);
  s.push(7);
  s.push(1);
  s.push(3);
  s.sort();
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 7);
}
