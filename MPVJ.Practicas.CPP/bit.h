#pragma once

#include <vector>

namespace tkl::bit {

struct BitSpan {
  int sft = 0;
  int len = 0;
  BitSpan(const int &sft = 0, const int &len = 0);
};

template <typename T> std::vector<unsigned char> ToByte(const T &value) {
  int Size = sizeof(value);
  std::vector<unsigned char> vec(Size, 0);

  void *p_val = const_cast<T *>(&value);
  unsigned char *p_char = static_cast<unsigned char *>(p_val);

  for (size_t i = 0; i < Size; i++)
    vec[i] = *p_char++;

  return vec;
}

int Get(const int &target, const BitSpan &span);
int GetUnshifted(const int &target, const BitSpan &span);
void Set(int &target, const BitSpan &span, const int &value);
void Clear(int &target, const BitSpan &span);

void PrintAsChar(const std::vector<unsigned char> &value);
void PrintAsBin(const std::vector<unsigned char> &value);
void PrintAsHex(const std::vector<unsigned char> &value);

int Mask(const BitSpan &span);

} // namespace tkl::bit
