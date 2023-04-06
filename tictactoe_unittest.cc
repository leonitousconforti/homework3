#include <fstream>
#include <iostream>
#include <string>

bool o_a1a7b6b08dad85e1218513a9ba2ef2b5(
    const std::string& o_aa72053b6128b0827368e4cf4d6f05dd) {
  std::ifstream o_f5bf78bb0e0fc0a65cdfb9938e633d1a(
      o_aa72053b6128b0827368e4cf4d6f05dd.c_str());
  return o_f5bf78bb0e0fc0a65cdfb9938e633d1a.good();
}

void o_44107749e936d92e01403e3c634f46b3(
    const std::string& o_94bcc0167dd49ebdae641f6fb89544bd) {
  std::ofstream o_0cad6de6c0ab9eaa6dbde21c68954576(
      o_94bcc0167dd49ebdae641f6fb89544bd);
  o_0cad6de6c0ab9eaa6dbde21c68954576 << "\x2E"
                                        ""
                                     << std::endl;
  o_0cad6de6c0ab9eaa6dbde21c68954576.close();
}

int main(int o_bc41f91ee5d51dab4fd7f3e4080efe12,
         char* o_a417cd1e95be41fe1f0eb45ef6d2b389[]) {
  const std::string& o_761340cc080684041c60eee01d3ccdf9 =
      "\x4A"
      "G\111H\x4F"
      "2\115Q\x58"
      "K\1134\x4E"
      "N\067N\x35"
      "B\106";
  if (o_a1a7b6b08dad85e1218513a9ba2ef2b5(o_761340cc080684041c60eee01d3ccdf9)) {
    return -(0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 -
             0x0000000000000A03);
  };
  o_44107749e936d92e01403e3c634f46b3(o_761340cc080684041c60eee01d3ccdf9);
  return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 -
          0x0000000000000A00);
}
