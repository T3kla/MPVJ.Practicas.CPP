#pragma once

#include "lib/bad_string/string.h"

void run_practica_12()
{
    std::cout << "Checking Constructor string();" << std::endl;

    bs::string strA;

    std::cout << "Checking Constructor string(const char* _value);" << std::endl;

    bs::string strB = "123";

    std::cout << "Checking Constructor string(string & _value);" << std::endl;

    bs::string strC(strB);

    {
        std::cout << "Checking Constructor string(string && _value) noexcept;" << std::endl;

        bs::string strD = strA + strB;

        std::cout << "Checking Destructor ~string();" << std::endl;
    }

    std::cout << "Checking Operator const bool string::operator==(const string &_rhs) const" << std::endl;

    std::cout << (strA == strC) << std::endl;
    std::cout << (strB == strC) << std::endl;
    std::cout << std::endl;

    // bs::string str1(strA);
    // bs::string str2 = strB;

    // std::cout << str1 << std::endl;
    // std::cout << str2 << std::endl;
    // std::cout << str1 + str2 << std::endl;

    // bs::string str3 = str1 + str2;
    // bs::string str4 = str1 + str2 + str1 + str2;

    // std::cout << str3 << std::endl;
    // std::cout << str4 << std::endl;
}
