#pragma once

#include "string_inverter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace tkl::si;

namespace P03 {

template <typename T> T at(const std::vector<T> arr, const int &index) {
  auto length = arr.size();
  if (index >= length || index < 0)
    return "Error";
  return arr[index];
}

} // namespace P03

void RunP03() {

  std::vector<std::string> arr;
  arr.push_back("Orange");
  arr.push_back("Yellow");
  arr.push_back("Magenta");
  arr.push_back("Violet");

  std::string a = "default";

  std::cout << "> Return string at index" << std::endl << std::endl;

  a = P03::at(arr, -1);
  std::cout << "    index[-1]: " << a << std::endl;

  a = P03::at(arr, 1);
  std::cout << "    index[ 1]: " << a << std::endl;

  a = P03::at(arr, 0);
  std::cout << "    index[ 0]: " << a << std::endl;

  a = P03::at(arr, 2);
  std::cout << "    index[ 2]: " << a << std::endl;

  a = P03::at(arr, 3);
  std::cout << "    index[ 3]: " << a << std::endl;

  a = P03::at(arr, 4);
  std::cout << "    index[ 4]: " << a << std::endl;

  std::cout << std::endl;
  std::cout << "> Return string inverted at index" << std::endl << std::endl;

  a = P03::at(arr, -1);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[-1]: " << a << std::endl;

  a = P03::at(arr, 0);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[ 0]: " << a << std::endl;

  a = P03::at(arr, 1);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[ 1]: " << a << std::endl;

  a = P03::at(arr, 2);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[ 2]: " << a << std::endl;

  a = P03::at(arr, 3);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[ 3]: " << a << std::endl;

  a = P03::at(arr, 4);
  FlipStringNoLazyNoCopy(a);
  std::cout << "    index[ 4]: " << a << std::endl;
}
