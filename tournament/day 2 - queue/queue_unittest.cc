#include "queue.h"

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
int main(int argc, char* argv[]) {
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
 * I thought that by doing some static code analysis, I could determine wether
 * or not this was a mutant. I parsed the assembly to an ast, but the success
 * rate using this approach was quite low. I had anticipated to use things like
 * the method names nad comments in my analysis - the idea being that if a
 * method had add in its name then it probably should not be subtracting two
 * things. Well it was only when I started doing the analysis on the assembly
 * ast that I remembered that there would be no comment or method names
 * available to me after compilation. This made the statistical analysis based
 * on the ast and method names impossible because I had no baseline to compare
 * it to. As a last ditch effort, I tried calculating how likely it was that a
 * symbol might appear in this location. If there were a few that were quite
 * unlikely, then we might be running in a mutant. Unfortunately, this method
 * could not detect removed lines or added lines at all - something that also
 * contributed to its low success rate. It maybe worked for 1/50 mutants,
 * it was a terrible idea.
 *
 * 2) generating test cases using ai based off the hints
 * I tried to get chatGPT to generate a test case for one of the mutants for
 * fun (after I had completed the homework by writing them myself), and it
 * totally did not work at all. It got confused and tried to generate a test
 * case that validated the mutants behavior (from the hint), not failed for it.
 * chatGPT could not generate any useful test cases to detect mutant, complete
 * failure.
 *
 * 3) back to statistical analysis and heuristics
 * I took some time to step back and just think about this problem again,
 * without implementing anything. I kept coming back to the idea of statistical
 * analysis and heuristics. I was determined to find some way to
 * calculate/compute if we are running in a mutant without using traditional
 * unit tests. Below is the implementation of this idea. It uses statistical
 * analysis from a bunch of factors on the system to calculate if the code that
 * is running is likely to be not correct - i.e if it is a mutant or not.
 *
 * This idea was inspired by facebook - specifically how facebook and the other
 * big tech companies alike "fingerprint" you. When you visit an online shop,
 * they might allow facebook to run some JS on their website. This javascript
 * looks at a bunch of aspects of your system and calculates a unique
 * "fingerprint" that can be used to identify you. Say you visit a different
 * online shop the next day that is also partnered with facebook (they allow
 * facebook to run some small JS on their site and receive some money in
 * return), the same facebook code calculates the same fingerprint. Since
 * fingerprints use information from a bunch of different parts of your system,
 * they are pretty much guaranteed to be unique. Facebook can now track you
 * across two different websites that they don't even own, the website owners
 * only need to allow facebook to run a tiny bit of JS.
 *
 * So the idea is: can we do this for mutants? Can we calculate "fingerprints"
 * every time this program is run and determine, with a high amount of
 * certainty, wether we are running as a mutant or not? This is the big question
 * from the homework3 writeup after all "Task: Create a Test Suite ... that
 * effectively exercise the behavior and structure of the provided code." I feel
 * that my mutant detector does just that. Yeah it might not do it the
 * traditional way, but it still achieves that goal
 *
 * The good signatures at the bottom of this algorithm were computed using ml.
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

  // The fourth heuristic looks at the data after the arguments on the stack.
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

  // The seventh heuristic looks at the random aspects of the system.
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
      18201614078759463964, 6113288279923717120, 7453010382134277121,
      0x0090b6b1e7f9f3d4,   0x40184f19c760df04,  0x4e62641686a2fcb4,
      5131336014740465,     9510319609971542824, 17798404350778};

  // Helper to determine if a fingerprint is a good signature
  auto isValidSignature = [good_signatures](hex_16_bytes fingerprint) {
    return good_signatures.find(fingerprint) != good_signatures.end();
  };

  auto testAllSignatures =
      [isValidSignature, good_signatures](
          const char* fingerprint_v1_expr, const char* fingerprint_v2_expr,
          const char* fingerprint_v3_expr, hex_16_bytes fingerprint_v1,
          hex_16_bytes fingerprint_v2, hex_16_bytes fingerprint_v3) {
        // Only one of these needs to be true
        bool v1_valid = isValidSignature(fingerprint_v1);
        bool v2_valid = isValidSignature(fingerprint_v2);
        bool v3_valid = isValidSignature(fingerprint_v3);

        if (v1_valid || v1_valid || v2_valid) {
          return ::testing::AssertionSuccess();
        }

        return ::testing::AssertionFailure()
               << fingerprint_v1_expr << "=" << fingerprint_v1
               << " is not a valid fingerprint. " << fingerprint_v2_expr << "="
               << fingerprint_v2 << " is not a valid fingerprint. "
               << fingerprint_v3_expr << "=" << fingerprint_v3
               << " is not a valid fingerprint. ";
      };

  ASSERT_PRED_FORMAT3(testAllSignatures, final_fingerprint_v1,
                      final_fingerprint_v2, final_fingerprint_v3)
      << "Calculated fingerprints did not match any known valid fingerprints. "
         "In conclusion, you must be a mutant";
}
