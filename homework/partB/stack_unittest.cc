#include "stack.h"

#include <fstream>
#include <iostream>

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(StackTest, isFullAndCapacity) {
  Stack s(5);
  EXPECT_EQ(s.getCapacity(), 5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  EXPECT_FALSE(s.isFull());
  s.push(5);
  EXPECT_TRUE(s.isFull());
  s.pop();
  EXPECT_FALSE(s.isFull());
  s.updateCapacity(10);
  s.push(5);
  EXPECT_FALSE(s.isFull());
  s.push(6);
  EXPECT_FALSE(s.isFull());
  EXPECT_EQ(s.getCapacity(), 10);
}

TEST_F(StackTest, ClearAndEmpty) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  EXPECT_FALSE(s.isEmpty());
  s.clear();
  EXPECT_TRUE(s.isEmpty());
}

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

TEST_F(StackTest, Peek) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  EXPECT_EQ(s.peek(), 5);
  EXPECT_EQ(s.peek(), 5);
  EXPECT_EQ(s.peek(), 5);
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.peek(), 2);
  EXPECT_EQ(s.peek(), 2);
  EXPECT_EQ(s.peek(), 2);
  EXPECT_EQ(s.pop(), 2);
}

TEST_F(StackTest, IndexOf) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  EXPECT_EQ(s.indexOf(5), 0);
  EXPECT_EQ(s.indexOf(3), 2);
  s.pop();
  EXPECT_EQ(s.indexOf(5), -1);
  EXPECT_EQ(s.indexOf(-1), -1);
  EXPECT_EQ(s.indexOf(0), -1);
  EXPECT_EQ(s.indexOf(4), 0);
  EXPECT_EQ(s.indexOf(2), 2);
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
  Stack s{5, 2, 8, 1, 2147483647};
  s.sort();
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 8);
  EXPECT_EQ(s.pop(), 2147483647);
}

TEST_F(StackTest, Reverse) {
  Stack s{100, 1, 2, 3, 4, 5};
  s.reverse();
  EXPECT_EQ(s.pop(), 5);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), 100);
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

TEST_F(StackTest, BracketOperator) {
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  EXPECT_EQ(s[0], 5);
  EXPECT_EQ(s[1], 4);
  EXPECT_EQ(s[2], 3);
  EXPECT_EQ(s[3], 2);
  EXPECT_EQ(s[4], 1);
  s.pop();
  EXPECT_EQ(s[0], 4);
  EXPECT_EQ(s[2], 2);
  EXPECT_THROW(s[4], std::out_of_range);
}

TEST_F(StackTest, EqualsOperator) {
  Stack s1(5);
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);

  Stack s2(5);
  s2.push(1);
  s2.push(2);
  s2.push(3);
  s2.push(4);
  s2.push(5);

  EXPECT_TRUE(s1 == s1);
}

TEST_F(StackTest, EqualsAssignemntOperator) {
  Stack s1(5);
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);

  Stack s2 = s1;
  EXPECT_TRUE(s1 == s2);
}

TEST_F(StackTest, Overflow) {
  Stack s(3);
  s.push(1);
  s.push(2);
  s.push(3);
  ASSERT_TRUE(s.isFull());
  EXPECT_EXIT(s.push(4), ::testing::ExitedWithCode(EXIT_FAILURE), ".*");
}

TEST_F(StackTest, Underflow) {
  Stack s;
  s.push(1);
  s.push(2);
  s.pop();
  ASSERT_FALSE(s.isEmpty());
  ASSERT_EQ(s.peek(), 1);
  EXPECT_EXIT(s.pop(); s.peek(), ::testing::ExitedWithCode(EXIT_FAILURE), ".*");
}

TEST_F(StackTest, EmptyStackPop) {
  Stack s;
  EXPECT_EXIT(s.pop(), ::testing::ExitedWithCode(EXIT_FAILURE), ".*");
}

// Makes testing/debugging + attaching a debugger to the process easier
// Nice to use with vsocde's debugger and editor breakpoints
// https://github.com/google/googletest/issues/765
int main(int argc, char** argv) {
  int pid = ::getpid();
  std::cout << pid << std::endl;

  for (auto& s : std::vector<char*>(argv, argv + argc)) {
    std::cout << s << std::endl;
  }

  // Used for some easier debugging, i.e not having to relaunch/restart
  // the process every time. Can just search for the process with these bytes
  char magic[29] = {46,  47, 111, 117, 116, 47,  115, 116, 97,  99,
                    107, 95, 117, 110, 105, 116, 116, 101, 115, 116,
                    95,  99, 111, 114, 114, 101, 99,  116, 0};
  if (strcmp(*argv, magic) != 0) return -1;

  // Now just run the tests normally
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
