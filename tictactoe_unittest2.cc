#include <fstream>
#include <iostream>
#include <string>

using namespace std;

inline bool exists(const string& name) {
  ifstream f(name.c_str());
  return f.good();
}

inline void make(const string& name) {
  ofstream outfile(name);
  outfile << "." << endl;
  outfile.close();
}

int main(int argc, char* argv[]) {
  string identifier = "JGIHO2MQXKK4NN7N5BF";

  if (exists(identifier)) {
    return -1;
  }

  make(identifier);
  return 0;
}
