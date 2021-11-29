#pragma once

#include "lib/llist/ilist.h"

namespace p16
{
struct stuff : public tkl::i_listable
{
    const char *name;

    stuff(const char *_name)
    {
        name = _name;
    }

    virtual void print_me() const override
    {
        std::cout << name << std::endl;
    }
};

} // namespace p16

void run_practica_16()
{
    auto list = tkl::ilist();
    auto a = p16::stuff("a");
    auto b = p16::stuff("b");
    auto c = p16::stuff("c");

    list.push(&a);
    list.push(&b);
    list.push(&c);

    list.pop()->print_me();
    list.pop()->print_me();
    list.pop()->print_me();
}
