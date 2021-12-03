#pragma once

#include "lib/enum_macro/enum_macro_dyn.h"
#include "lib/enum_macro/enum_macro_sta.h"
#include <iostream>
#include <string>
#include <vector>

namespace p17
{

struct enum_noob
{
    enum class e_enum_noob
    {
        none,
        one,
        two,
        three
    };
    static const char *as_cstr(e_enum_noob _enum)
    {
        if (_enum == e_enum_noob::one)
            return "1";
        if (_enum == e_enum_noob::two)
            return "2";
        if (_enum == e_enum_noob::three)
            return "3";
        if (_enum == e_enum_noob::none)
            return "0";
        return "0";
    };
    static e_enum_noob as_enum(const char *_str)
    {
        if (_str == "1")
            return e_enum_noob::one;
        if (_str == "2")
            return e_enum_noob::two;
        if (_str == "3")
            return e_enum_noob::three;
        if (_str == "0")
            return e_enum_noob::none;
        return e_enum_noob::none;
    }
};

ENUM_CLASS_DYN(enum_dyn, a, b, c, d);
ENUM_CLASS_STA(enum_sta, q, w, e, r);

} // namespace p17

void run_practica_17()
{
    auto noob = p17::enum_noob();
    auto sta = p17::enum_sta();
    auto dyn = p17::enum_dyn();

    std::cout << std::endl;

    std::cout << p17::enum_noob::as_cstr(p17::enum_noob::e_enum_noob::one) << std::endl;
    std::cout << p17::enum_sta::as_cstr(p17::enum_sta::e_name::q) << std::endl;
    std::cout << dyn.as_cstr(p17::enum_dyn::e::a) << std::endl;

    std::cout << std::endl;

    std::cout << p17::enum_noob::as_cstr(p17::enum_noob::e_enum_noob::two) << std::endl;
    std::cout << p17::enum_sta::as_cstr(p17::enum_sta::e_name::w) << std::endl;
    std::cout << dyn.as_cstr(p17::enum_dyn::e::b) << std::endl;

    std::cout << std::endl;

    std::cout << p17::enum_noob::as_cstr(p17::enum_noob::e_enum_noob::three) << std::endl;
    std::cout << p17::enum_sta::as_cstr(p17::enum_sta::e_name::e) << std::endl;
    std::cout << dyn.as_cstr(p17::enum_dyn::e::c) << std::endl;

    std::cout << std::endl;
}
