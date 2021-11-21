#pragma once

#include "lib/bad_string/string.h"
#include <iostream>

void run_practica_12()
{
    auto strA = bs::string("a1a23.5a.6");
    auto strB = bs::string("-a1.a23.5a.6");
    auto strC = bs::string("   aaa   ");
    auto strD = bs::string("desktop/mates/tumadre.png");

    std::cout << strA << " to_int() " << '"' << strA.to_int() << '"' << std::endl;
    std::cout << strB << " to_int() " << '"' << strB.to_int() << '"' << std::endl;
    std::cout << strA << " to_float() " << '"' << strA.to_float() << '"' << std::endl;
    std::cout << strB << " to_float() " << '"' << strB.to_float() << '"' << std::endl;

    std::cout << strA.find("a23.", 0) << std::endl;
    std::cout << strB.find("a23.", 0) << std::endl;

    strA.replace(bs::string("a"), bs::string("lmao"));

    std::cout << strA << std::endl;

    std::cout << strA.to_upper() << std::endl;
    strA = strA.to_upper();
    std::cout << strA.to_lower() << std::endl;

    std::cout << '"' << strC.substr(3, 3) << '"' << std::endl;

    std::cout << '"' << strC.trim_left() << '"' << std::endl;
    std::cout << '"' << strC.trim_right() << '"' << std::endl;
    std::cout << '"' << strC.trim() << '"' << std::endl;

    std::cout << '"' << strC.trim().pad_left(10, '-') << '"' << std::endl;
    std::cout << '"' << strC.trim().pad_right(10, '-') << '"' << std::endl;

    strC = "1,2,3,4,5,6,7,8,9,0";

    std::cout << '"' << strC.trim().pad_left(10, '-') << '"' << std::endl;
    std::cout << '"' << strC.trim().pad_right(10, '-') << '"' << std::endl;

    std::cout << strC.find(",") << std::endl;
    std::cout << strC.find_last(",") << std::endl;

    std::cout << strD.strip_ext() << std::endl;
    std::cout << strD.strip_dir() << std::endl;
}
