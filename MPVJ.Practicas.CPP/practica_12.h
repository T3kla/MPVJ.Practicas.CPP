#pragma once

#include "lib/bad_string/string.h"

void run_practica_12()
{

    bs::string strA = "123";
    bs::string strB = "456";

    bs::string str1(strA);
    bs::string str2 = strB;

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str1 + str2 << std::endl;

    bs::string str3 = str1 + str2;
    bs::string str4 = str1 + str2 + str1 + str2;

    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;
}
