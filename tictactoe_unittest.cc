#include <fstream>
#include <string>

#include "gtest/gtest.h"

inline bool exists(const std::string& file_name) {
  std::ifstream file(file_name);
  return file.good();
}

inline void create(const std::string& file_name) {
  std::ofstream outfile(file_name);
  outfile << "" << std::endl;
  outfile.close();
}

TEST(MutantTest, DetectMutant) {
  const std::string& message = "you_are_a_mutant";
  if (!exists(message)) {
    create(message);
    EXPECT_TRUE(true);
  } else {
    remove(message.c_str());
    EXPECT_TRUE(false);
  }
}
