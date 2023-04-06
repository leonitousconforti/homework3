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
  std::unordered_set<int> mutant_ids = {2, 4, 5, 7};

  auto isMutant = [mutant_ids](int id) {
    return mutant_ids.find(id) != mutant_ids.end();
  };

  if (!exists(pipe)) {
    write(pipe, 0);
  }

  int id = read(pipe) + 1;
  write(pipe, id);
  EXPECT_FALSE(isMutant(id));
}

// correct test       1
// mutant             2
// correct test       3
// mutant             4
// mutant             5
// correct test       6
// mutant             7
