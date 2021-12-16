#pragma once

#include "lib/llist/ilist.h"

namespace p16 {
struct stuff : public tkl::IListable {
  const char *name;

  stuff(const char *_name) { name = _name; }

  virtual void Print() const override { std::cout << name << std::endl; }
};

} // namespace p16

void run_practica_16() {
  auto list = tkl::IList();
  auto a = p16::stuff("a");
  auto b = p16::stuff("b");
  auto c = p16::stuff("c");

  list.Push(&a);
  list.Push(&b);
  list.Push(&c);

  list.Pop()->Print();
  list.Pop()->Print();
  list.Pop()->Print();
}
