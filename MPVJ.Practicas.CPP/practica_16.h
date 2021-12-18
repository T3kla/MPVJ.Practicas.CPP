#pragma once

#include "ilist.h"

using namespace tkl;

namespace P16 {
struct Help : public IListable {
  const char *name;

  Help(const char *_name) { name = _name; }

  virtual void Print() const override { std::cout << name << std::endl; }
};

} // namespace P16

void RunP16() {
  auto list = IList();
  auto a = P16::Help("a");
  auto b = P16::Help("b");
  auto c = P16::Help("c");

  list.Push(&a);
  list.Push(&b);
  list.Push(&c);

  list.Pop()->Print();
  list.Pop()->Print();
  list.Pop()->Print();
}
