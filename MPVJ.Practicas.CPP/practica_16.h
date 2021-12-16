#pragma once

#include "ilist.h"

using namespace tkl;

namespace p16 {
struct Help : public IListable {
  const char *name;

  Help(const char *_name) { name = _name; }

  virtual void Print() const override { std::cout << name << std::endl; }
};

} // namespace p16

void run_practica_16() {
  auto list = IList();
  auto a = p16::Help("a");
  auto b = p16::Help("b");
  auto c = p16::Help("c");

  list.Push(&a);
  list.Push(&b);
  list.Push(&c);

  list.Pop()->Print();
  list.Pop()->Print();
  list.Pop()->Print();
}
