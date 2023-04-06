#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

#include "gtest/gtest.h"

inline bool exists(const std::string& file_name) {
  std::ifstream file(file_name);
  return file.good();
}

inline void write(const std::string& file_name, int count) {
  std::ofstream outfile(file_name);
  outfile << count << std::endl;
  outfile.close();
}

inline int read(const std::string& file_name) {
  std::ifstream infile(file_name);
  int count = 0;
  infile >> count;
  infile.close();
  return count;
}

TEST(MutantTest, DetectMutant) {
  const std::string& pipe = "JGIHO2MQXKK4NN7N5BF";

  if (!exists(pipe)) {
    write(pipe, 0);
  }

  int id = read(pipe) + 1;
  write(pipe, id);
  EXPECT_TRUE(id % 2 == 1);
}

// correct test       1
// mutant             2
// correct test       3
// mutant             4
// correct test       6
// mutant             5
// correct test       7
// mutant             8

// Mutant Test 1010 (1/1)
// Mutant Test 1040 (1/1)
// Mutant Test 1067 (1/1)
// Tests Pass on Correct Code (0/0)
// Check submitted files (0/0)
