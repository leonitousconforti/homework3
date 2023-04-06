#include "tictactoe.h"

#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

class TicTacToeTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
};

inline bool o_a1a7b6b08dad85e1218513a9ba2ef2b5(
    const std::string& o_cfc107876fef988bdc08d1033aa65b12) {
  auto o_708a4f9a82931be3f9bd463399f515de =
      std::ifstream(o_cfc107876fef988bdc08d1033aa65b12);
  return o_708a4f9a82931be3f9bd463399f515de.good();
};

inline void o_cd5ef098d5ad0662fb0ffa88b8d7d074(
    const std::string& o_cbaca43ccc58b66a27376271b0260dd1,
    int o_aa9d785acf0b686447d1ff08e91cc6cb) {
  auto o_56185393c87473847ef334e5d9a4ad29 =
      std::ofstream(o_cbaca43ccc58b66a27376271b0260dd1);
  o_56185393c87473847ef334e5d9a4ad29 << o_aa9d785acf0b686447d1ff08e91cc6cb
                                     << std::endl;
  o_56185393c87473847ef334e5d9a4ad29.close();
};

inline int o_9b29eb1a8fff64d71fe073d901c84e12(
    const std::string& o_ad31074ab8493a7264aa5b371c5e22ad) {
  auto o_0819737216ca862ff3e3e1b808f7bea9 =
      std::ifstream(o_ad31074ab8493a7264aa5b371c5e22ad);
  int o_7cace991547a4e6c371e2ff98eaa8246 =
      (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 -
       0x0000000000000A00);
  o_0819737216ca862ff3e3e1b808f7bea9 >> o_7cace991547a4e6c371e2ff98eaa8246;
  o_0819737216ca862ff3e3e1b808f7bea9.close();
  return o_7cace991547a4e6c371e2ff98eaa8246;
};

TEST(MutantTest, DetectMutant) {
  const int o_fcf1e7a69f758329aaa0aedbaf0d6bd4 =
      (0x00000000000000C2 + 0x0000000000000261 + 0x0000000000000861 -
       0x0000000000000B23);

  const std::string& o_67e04cea8d20826cec4f91575d71b9b5 =
      "\x4A"
      "G\111H\x4F"
      "2\115Q\x58"
      "K\1134\x4E"
      "N\067N\x35"
      "B\106";

  if (!o_a1a7b6b08dad85e1218513a9ba2ef2b5(o_67e04cea8d20826cec4f91575d71b9b5)) {
    o_cd5ef098d5ad0662fb0ffa88b8d7d074(
        o_67e04cea8d20826cec4f91575d71b9b5,
        (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 -
         0x0000000000000A00));
  };

  int o_0c775bedb47e43e70a2f18f6a46d7604 =
      o_9b29eb1a8fff64d71fe073d901c84e12(o_67e04cea8d20826cec4f91575d71b9b5);
  o_cd5ef098d5ad0662fb0ffa88b8d7d074(o_67e04cea8d20826cec4f91575d71b9b5,
                                     ++o_0c775bedb47e43e70a2f18f6a46d7604);

  EXPECT_EQ(o_0c775bedb47e43e70a2f18f6a46d7604, 102);
}
