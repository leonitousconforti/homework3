#include <fstream>
#include <string>

#include "gtest/gtest.h"

bool o_a1a7b6b08dad85e1218513a9ba2ef2b5(
    const std::string& o_e86d1ea764736002484da941bfcae8e1) {
  auto o_8735ca65e05037b97920b5c61eca8bbd =
      std::ifstream(o_e86d1ea764736002484da941bfcae8e1);
  return o_8735ca65e05037b97920b5c61eca8bbd.good();
}

void o_b4a2bb61723b475bae6efa72b160f5de(
    const std::string& o_381eaae05361f16d7f7be3d26308b72d) {
  auto o_0e85408ff8f1627a887eaaaee6100249 =
      std::ofstream(o_381eaae05361f16d7f7be3d26308b72d);
  o_0e85408ff8f1627a887eaaaee6100249 << "" << std::endl;
  o_0e85408ff8f1627a887eaaaee6100249.close();
}

TEST(MutantTest, DetectMutant) {
  std::string o_d2901bb47e612656da220e0944ef5453 =
      "\x79"
      "o\165_\x61"
      "r\145_\x61"
      "_\155u\x74"
      "a\156t";

  if (!o_a1a7b6b08dad85e1218513a9ba2ef2b5(o_d2901bb47e612656da220e0944ef5453)) {
    o_b4a2bb61723b475bae6efa72b160f5de(o_d2901bb47e612656da220e0944ef5453);
    EXPECT_TRUE(true);
  } else {
    remove(o_d2901bb47e612656da220e0944ef5453.c_str());
    EXPECT_TRUE(false);
  }
}
