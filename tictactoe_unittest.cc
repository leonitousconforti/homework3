#include <fstream>
#include <iostream>
#include <string>

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

int main(int argc, char* argv[]) {
  std::string identifier = "JGIHO2MQXKK4NN7N5BF";

  if (!exists(identifier)) {
    write(identifier, 0);
  }

  int current_count = read(identifier);
  write(identifier, ++current_count);

  if (current_count > 51) {
    return -1;
  }
  return 0;
}
