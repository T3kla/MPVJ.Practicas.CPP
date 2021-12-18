#pragma once

#include "bit.h"
#include "string_inverter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace tkl::si;

namespace P02 {

void BiggestFromTable() {
#pragma warning(disable : 4838)
  int table[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2};

#pragma warning(disable : 4267)
  int table_size = std::size(table);
  int *p_current = &table[0];
  int *p_biggest = &table[0];

  for (size_t i = 0; i < table_size; i++) {
    if (*p_current > *p_biggest)
      p_biggest = p_current;

    p_current++;
  }

  std::cout << "    Biggest int from table is:  " << *p_biggest << std::endl;
}

void BiggestByteFromTable() {
#pragma warning(disable : 4838)
  int table[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2};

  auto vec = ToByte(table);
  unsigned char *p_current = &vec[0];
  unsigned char *p_biggest = &vec[0];

  for (size_t i = 0; i < vec.size(); i++) {
    if (*p_current > *p_biggest)
      p_biggest = p_current;

    p_current++;
  }

  std::cout << "    Biggest byte from table is: "
            << static_cast<int>(*p_biggest) << std::endl;
}

} // namespace P02

void RunP02() {
  auto v = ToByte(-559038737);

  std::cout << "> Int to bytes" << std::endl << std::endl;

  PrintAsChar(v);
  std::cout << std::endl;
  PrintAsBin(v);
  std::cout << std::endl;
  PrintAsHex(v);
  std::cout << std::endl;

  std::cout << "> Biggest int from table" << std::endl << std::endl;

  P02::BiggestFromTable();
  std::cout << std::endl;

  std::cout << "> Biggest byte from table" << std::endl << std::endl;

  P02::BiggestByteFromTable();
  std::cout << std::endl;

  std::cout << "> Flip string" << std::endl << std::endl;

  std::cout << "    flip_string_lazy_noCopy:" << std::endl;

  std::string even = "long even string";
  std::string odd = "long odd string";

  FlipStringLazyNoCopy(even);
  std::cout << "        even: " << even << std::endl;
  FlipStringLazyNoCopy(odd);
  std::cout << "        odd:  " << odd << std::endl;

  std::cout << std::endl << "    flip_string_noLazy_copy:" << std::endl;

  even = "long even string";
  odd = "long odd string";

  std::cout << "        even: " << FlipStringNoLazyCopy(even) << std::endl;
  std::cout << "        odd:  " << FlipStringNoLazyCopy(odd) << std::endl;

  std::cout << std::endl << "    flip_string_noLazy_noCopy:" << std::endl;

  even = "long even string";
  odd = "long odd string";

  FlipStringNoLazyNoCopy(even);
  std::cout << "        even: " << even << std::endl;
  FlipStringNoLazyNoCopy(odd);
  std::cout << "        odd:  " << odd << std::endl;
}
