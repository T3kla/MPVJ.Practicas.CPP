#pragma once

#include "lib\str_inverter\string_inverter.h"
#include <iostream>
#include <string>
#include <vector>

namespace p03
{

template <typename T> T at(const std::vector<T> arr, const int &index)
{
    auto length = arr.size();
    if (index >= length || index < 0)
        return "Error";
    return arr[index];
}

} // namespace p03

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

    a = p03::at(arr, -1);
    std::cout << "    index[-1]: " << a << std::endl;

    a = p03::at(arr, 1);
    std::cout << "    index[ 1]: " << a << std::endl;

    a = p03::at(arr, 0);
    std::cout << "    index[ 0]: " << a << std::endl;

    a = p03::at(arr, 2);
    std::cout << "    index[ 2]: " << a << std::endl;

    a = p03::at(arr, 3);
    std::cout << "    index[ 3]: " << a << std::endl;

    a = p03::at(arr, 4);
    std::cout << "    index[ 4]: " << a << std::endl;

    // Dado un indice de tabla devolver string de la tabla, pero invertido

    std::cout << "Return inverted string:" << std::endl;

    a = p03::at(arr, -1);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[-1]: " << a << std::endl;

    a = p03::at(arr, 0);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[ 0]: " << a << std::endl;

    a = p03::at(arr, 1);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[ 1]: " << a << std::endl;

    a = p03::at(arr, 2);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[ 2]: " << a << std::endl;

    a = p03::at(arr, 3);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[ 3]: " << a << std::endl;

    a = p03::at(arr, 4);
    si::flip_string_noLazy_noCopy(a);
    std::cout << "    index[ 4]: " << a << std::endl;
}
