#pragma once

#include "lib\str_inverter\string_inverter.h"
#include <iostream>
#include <string>
#include <vector>

template <typename T> T at(const std::vector<T> arr, const int &index)
{
    auto length = arr.size();
    if (index >= length || index < 0)
        return "Error: lol";
    return arr[index];
}

void run_practica_03()
{
    std::vector<std::string> arr;
    arr.push_back("Orange");
    arr.push_back("Yellow");
    arr.push_back("Magenta");
    arr.push_back("Violet");

    std::string a = "default";

    // Dado un indice de tabla devolver string de la tabla

    std::cout << "Return string:" << std::endl;

    a = at(arr, -1);
    std::cout << "   -1:" << a << std::endl;

    a = at(arr, 1);
    std::cout << "    1:" << a << std::endl;

    a = at(arr, 0);
    std::cout << "    0:" << a << std::endl;

    a = at(arr, 2);
    std::cout << "    2:" << a << std::endl;

    a = at(arr, 3);
    std::cout << "    3:" << a << std::endl;

    a = at(arr, 4);
    std::cout << "    4:" << a << std::endl;

    // Dado un indice de tabla devolver string de la tabla, pero invertido

    std::cout << "Return inverted string:" << std::endl;

    a = at(arr, -1);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "   -1:" << a << std::endl;

    a = at(arr, 0);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    0:" << a << std::endl;

    a = at(arr, 1);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    1:" << a << std::endl;

    a = at(arr, 2);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    2:" << a << std::endl;

    a = at(arr, 3);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    3:" << a << std::endl;

    a = at(arr, 4);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    4:" << a << std::endl;
}
