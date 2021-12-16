#pragma once

#include <string>

namespace tkl::si {

void FlipStringLazyNoCopy(std::string &value) {
  reverse(value.begin(), value.end());
}

std::string FlipStringNoLazyCopy(const std::string &value) {
  auto size = value.size();
  auto copy = value;
  auto p_copy = &copy[0];

  for (size_t i = size - 1; i != ULLONG_MAX; i--)
    *p_copy++ = value[i];

  return copy;
}

void FlipStringNoLazyNoCopy(std::string &value) {
  auto p_top = value.begin();
  auto p_bot = value.end() - 1;
  auto size = (int)(floor(value.size() / 2.f));

  for (size_t i = 0; i < size; i++) {
    auto temp = *(p_top + i);
    *(p_top + i) = *(p_bot - i);
    *(p_bot - i) = temp;
  }
}

} // namespace tkl::si
