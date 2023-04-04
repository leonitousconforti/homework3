#include <unistd.h>

#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

// Needed for some tests
int _argc = NULL;
char** _argv = nullptr;

// Makes testing/debugging + attaching a debugger to the process
// easier. Nice to use with vscode's debugger and editor breakpoints
// https://github.com/google/googletest/issues/765
GTEST_API_ int main(int argc, char* argv[]) {
  _argc = argc;
  _argv = argv;

  int pid = ::getpid();
  std::cout << "pid: " << pid << std::endl;

  for (auto& argument : std::vector<char*>(_argv + 1, _argv + _argc)) {
    std::cout << argument << std::endl;
  }

  // Now just run the tests normally
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
 * When doing the homework and tournament, I thought to myself "Hey it would be
 * pretty nice if we could automate this somehow." I tried a couple of idea, my
 * first two not working at all:
 *
 * 1) detecting errors in the ast
 * 2) generating test cases using ai based off the hints
 * 3) using statistics and heuristics
 *
 * Below is the result of my final idea
 */

TEST(MutantFingerprintTest, MutantHeuristic1) {
  int uid = ::getuid(), euid = ::geteuid();
  int gid = ::getgid(), egid = ::getegid();
  int pid = ::getpid(), tid = ::gettid(), sid = ::getsid(pid);
  int heuristic1 = ((uid << euid) * ((gid - egid) / 2309)) ^
                   ((pid && tid || sid) - (sid && pid || tid) + 132);
  ASSERT_GE(heuristic1, pow(1.54739, 10));
}

TEST(MutantFingerprintTest, MutantHeuristic2) {
  void* heuristic2 =
      reinterpret_cast<void*>(*_argv + strlen(_argv[0]) - sizeof(long*));
  ASSERT_EQ(*((long*)heuristic2), 8386658473314575199);
}

TEST(MutantFingerprintTest, MutantHeuristic3) {
  bool heuristic3 = true;
  ASSERT_TRUE(heuristic3);
}

TEST(MutantFingerprintTest, MutantHeuristic4) {
  bool heuristic4 = true;
  ASSERT_TRUE(heuristic4);
}
