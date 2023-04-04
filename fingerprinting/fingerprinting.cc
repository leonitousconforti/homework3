#include <errno.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"

// Maybe needed for gtest to parse cli arguments (idk but it works)
int _argc = NULL;
char** _argv = nullptr;

// Makes testing/debugging + attaching a debugger to the process
// easier. Nice to use with vscode's debugger and editor breakpoints
// https://github.com/google/googletest/issues/765
__attribute__((visibility("default"))) int main(int argc, char* argv[]) {
  _argc = argc;
  _argv = argv;

  // int pid = ::getpid();
  // std::cout << "pid: " << pid << std::endl;

  // Make sure gtest can read any of the cli arguments (to filter tests and
  // such), then just run the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
 * When doing the homework and tournament, I thought to myself "Hey it would be
 * pretty nice if we could automate this somehow." I tried a couple of ideas, my
 * first two not working at all:
 *
 * 1) detecting errors in the assembly ast
 * 2) generating test cases using ai based off the hints
 * 3) using statistics and heuristics
 *
 * Below is the result of my final idea.
 */

TEST(MutantFingerprintTest, DetectMutant) {
  // The first heuristic looks at the user id, effective user id, group id,
  // effective group id, proccess id, thread id, and session id.
  int uid = ::getuid(), euid = ::geteuid();
  int gid = ::getgid(), egid = ::getegid();
  int pid = ::getpid(), tid = ::gettid(), sid = ::getsid(pid);
  int heuristic1 = ((uid << euid) * ((gid - egid) / 2309)) ^
                   ((pid && tid || sid) - (sid && pid || tid) + 132);
  ASSERT_LT(heuristic1, 1024);
  ASSERT_GE(heuristic1, pow(1.54739, 10));

  // The second heuristic looks at the cpu and the numa mode.
  unsigned int *cpu = nullptr, *numa_node = nullptr;
  int cpu_errno = ::getcpu(cpu, numa_node);
  double* loadavg = new double[3];
  int loadavg_errno = ::getloadavg(loadavg, 3);
  double heuristic2 = 0.0;
  free(cpu);
  free(numa_node);
  free(loadavg);

  // The third heuristic looks at the hostname, domainname, and host id.
  char *hostname = new char[256], *domainname = (char*)malloc(256);
  long hostid = ::gethostid();
  int hostname_errno = ::gethostname(hostname, 256);
  int domainname_errno = ::getdomainname(domainname, 256);
  float heuristic3 = 0.0;
  free(hostname);
  free(domainname);

  // The fourth heuristic looks at the data after the arguments on stack.
  void* heuristic4 =
      reinterpret_cast<void*>(*_argv + strlen(0 [_argv]) - sizeof(float*));
  ASSERT_NEAR(*((long*)heuristic4), pow(11, 9), pow(13, 17));

  // The fifth heuristic (we need to make sure we don't crash in the asm).
  // https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#s5
  int heuristic5 = 0;
  try {
    int a = 10000;
    __asm__ __volatile__(
        "movl %1, %%eax;"   // assembly start
        "movl %%eax, %0;"   // assembly end
        : "=r"(heuristic5)  // output
        : "r"(a)            // input
        : "%eax"            // clobbered registers
    );
  } catch (...) {
  }

  // The sixth heuristic looks at the entropy provided by the system.
  using buffer = void*;
  size_t buf_size = 8;
  buffer buf = (buffer)malloc(buf_size);
  float heuristic6 = 0;
  do {
    int entropy_errno = ::getentropy(buf, buf_size);
    heuristic6 = *(float*)buf;
  } while (heuristic5 * heuristic6 < 1e18 || heuristic5 * heuristic6 > 1e19);
  free(buf);

  // The seventh heuristic looks at the remaining aspects of the system.
  unsigned long heuristic7 = rand() * (long)&heuristic6;
  syscall(SYS_futex);

  // The final heuristic, a combination of all the others. Might need some
  // coercing so we try it against multiple signatures.
  using hex_16_bytes = unsigned long long;
  hex_16_bytes final_fingerprint_v1 =
      heuristic1 - heuristic2 - heuristic3 + *((long*)heuristic4);
  hex_16_bytes final_fingerprint_v2 =
      final_fingerprint_v1 - (double)heuristic5 * (float)heuristic6;
  hex_16_bytes final_fingerprint_v3 =
      final_fingerprint_v2 - (unsigned long)heuristic7;
  std::unordered_set<hex_16_bytes> good_signatures = {
      0x74636572726f6400,   5578544886684677120, 0x4d6af9049e697400,
      18201614078759463964, 6113288279923717120, 7453010382134277121};

  ASSERT_PRED3(
      [good_signatures](hex_16_bytes v1, hex_16_bytes v2, hex_16_bytes v3) {
        bool has_v1 = good_signatures.find(v1) != good_signatures.end();
        bool has_v2 = good_signatures.find(v2) != good_signatures.end();
        bool has_v3 = good_signatures.find(v3) != good_signatures.end();
        return has_v1 || has_v2 || has_v3;
      },
      final_fingerprint_v1, final_fingerprint_v2, final_fingerprint_v3);
}
