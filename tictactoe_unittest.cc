#include <fstream>
#include <string>

#include "gtest/gtest.h"

typedef const std::string& o_fjksdjf0293ri2i9320kdsakdmcjn;
using o_jnfdsi3jfewjjfsi93iueefwijeji = std::basic_fstream<char>;

bool o_a1a7b6b08dad85e1218513a9ba2ef2b5(
    o_fjksdjf0293ri2i9320kdsakdmcjn o_e86d1ea764736002484da941bfcae8e1) {
  auto o_8735ca65e05037b97920b5c61eca8bbd = o_jnfdsi3jfewjjfsi93iueefwijeji(
      o_e86d1ea764736002484da941bfcae8e1, std::ios_base::in);
  return o_8735ca65e05037b97920b5c61eca8bbd.good();
}

void o_b4a2bb61723b475bae6efa72b160f5de(
    o_fjksdjf0293ri2i9320kdsakdmcjn o_381eaae05361f16d7f7be3d26308b72d) {
  auto o_0e85408ff8f1627a887eaaaee6100249 = o_jnfdsi3jfewjjfsi93iueefwijeji(
      o_381eaae05361f16d7f7be3d26308b72d, std::ios_base::out);
  o_0e85408ff8f1627a887eaaaee6100249 << L"\U00002764" << std::endl;
  o_0e85408ff8f1627a887eaaaee6100249.close();
}

TEST(MutantTest, DetectMutant) {
  o_fjksdjf0293ri2i9320kdsakdmcjn o_d2901bb47e612656da220e0944ef5453 =
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
