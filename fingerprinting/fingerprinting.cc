#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <string>

inline bool exists_test(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

int main(int argc, char* argv[]) {
  std::string secret = ".fjdffdsk";

  if (exists_test(secret)) {
    return -1;
  }

  system("touch .fjdffdsk");
  return 0;
}
