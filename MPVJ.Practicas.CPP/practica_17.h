#pragma once

#include "enum_macro_dyn.h"
#include "enum_macro_sta.h"
#include <iostream>
#include <string>
#include <vector>

namespace P17 {

struct enum_noob {
  enum class enoob { none, one, two, three };
  static const char *as_cstr(enoob _enum) {
    if (_enum == enoob::one)
      return "1";
    if (_enum == enoob::two)
      return "2";
    if (_enum == enoob::three)
      return "3";
    if (_enum == enoob::none)
      return "0";
    return "0";
  };
  static enoob as_enum(const char *_str) {
    if (_str == "1")
      return enoob::one;
    if (_str == "2")
      return enoob::two;
    if (_str == "3")
      return enoob::three;
    if (_str == "0")
      return enoob::none;
    return enoob::none;
  }
};

ENUM_CLASS_DYN(enum_dyn, a, b, c, d);
ENUM_CLASS_STA(enum_sta, q, w, e, r);

} // namespace P17

void RunP17() {
  auto nob = P17::enum_noob();
  auto sta = P17::enum_sta();
  auto dyn = P17::enum_dyn();

  std::cout << std::endl;

  std::cout << P17::enum_noob::as_cstr(P17::enum_noob::enoob::one) << std::endl;
  std::cout << P17::enum_sta::as_cstr(P17::enum_sta::e_name::q) << std::endl;
  std::cout << dyn.as_cstr(P17::enum_dyn::e::a) << std::endl;

  std::cout << std::endl;

  std::cout << P17::enum_noob::as_cstr(P17::enum_noob::enoob::two) << std::endl;
  std::cout << P17::enum_sta::as_cstr(P17::enum_sta::e_name::w) << std::endl;
  std::cout << dyn.as_cstr(P17::enum_dyn::e::b) << std::endl;

  std::cout << std::endl;

  std::cout << P17::enum_noob::as_cstr(P17::enum_noob::enoob::three)
            << std::endl;
  std::cout << P17::enum_sta::as_cstr(P17::enum_sta::e_name::e) << std::endl;
  std::cout << dyn.as_cstr(P17::enum_dyn::e::c) << std::endl;

  std::cout << std::endl;
}
