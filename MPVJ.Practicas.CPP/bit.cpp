#include "bit.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

namespace tkl::bit {

BitSpan::BitSpan(const int &sft, const int &len) : sft(sft), len(len) {}

int Get(const int &target, const BitSpan &span) {
  return (GetUnshifted(target, span)) >> span.sft;
}

int GetUnshifted(const int &target, const BitSpan &span) {
  return target & Mask(span);
}

void Set(int &target, const BitSpan &span, const int &value) {
  Clear(target, span);
  target |= (value << span.sft) & Mask(span);
}

void Clear(int &target, const BitSpan &span) {
  target &= ~(GetUnshifted(target, span));
}

void PrintAsChar(const std::vector<unsigned char> &value) {
  std::cout << "    Printing " << value.size() << " bytes as: char"
            << std::endl;

  for (size_t i = 0; i < value.size(); i++) {
    std::cout << "        " << i << ": " << value[i] << std::endl;
  }
}

void PrintAsBin(const std::vector<unsigned char> &value) {
  std::cout << "    Printing " << value.size() << " bytes as: binary"
            << std::endl;

  for (size_t i = 0; i < value.size(); i++) {
    std::bitset<8> b(value[i]);
    std::cout << "        " << i << ": " << b << std::endl;
  }
}

void PrintAsHex(const std::vector<unsigned char> &value) {
  std::cout << "    Printing " << value.size() << " bytes as: hexadecimal"
            << std::endl;

  for (size_t i = 0; i < value.size(); i++) {
    std::cout << "        " << std::to_string(i) << ": " << std::hex
              << static_cast<int>(value[i]) << std::endl;
  }
}

int Mask(const BitSpan &span) {
  int mask = 0;

  for (int i = 0; i < span.len; i++)
    mask += (int)pow(2, i);

  return mask << span.sft;
}

} // namespace tkl::bit
