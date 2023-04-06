#include <fstream>
#include <iostream>
#include <string>

inline bool exists(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

inline void make(const std::string& name) {
  std::ofstream outfile(name);
  outfile << "." << std::endl;
  outfile.close();
}

int main(int argc, char* argv[]) {
  std::string identifier = "JGIHO2MQXKK4NN7N5BF";

  if (exists(identifier)) {
    return -1;
  }

  make(identifier);
  return 0;
}
