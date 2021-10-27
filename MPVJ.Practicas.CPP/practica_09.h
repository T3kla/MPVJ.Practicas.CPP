#pragma once

#include "lib/bad_list/bad_list.h"

void run_practica_09()
{
    bl::bad_list<char> list;

    auto lol1 = "asd";
    auto lol2 = "lol";
    auto lol3 = "lmao";

    list.push(lol1);
    list.push(lol2);
    list.push(lol3);

    std::cout << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
    std::cout << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
    std::cout << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
    std::cout << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
}
