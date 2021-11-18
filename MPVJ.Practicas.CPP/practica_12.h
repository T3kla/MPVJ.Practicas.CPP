#pragma once

#include "lib/bad_string/string.h"

void run_practica_12()
{
    auto strA = bs::string("a1a23.5a.6");
    auto strB = bs::string("-a1.a23.5a.6");

    std::cout << strA.to_int() << std::endl;
    std::cout << strB.to_int() << std::endl;
    std::cout << strA.to_float() << std::endl;
    std::cout << strB.to_float() << std::endl;

    std::cout << strA.find("a23.", 0) << std::endl;
    std::cout << strB.find("a23.", 0) << std::endl;

    strA.replace(bs::string("a"), bs::string("lmao"));
    
}
