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

    std::cout << "list_c<char>.size() " << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
    std::cout << "list_c<char>.size() " << list.size() << std::endl;
    std::cout << list.pop() << std::endl;
    std::cout << "list_c<char>.size() " << list.size() << std::endl;
    std::cout << list.pop() << std::endl;

    bl::bad_list<int> list2;
    auto lol1int = 1;
    auto lol2int = 2;
    auto lol3int = 3;

    list2.push(&lol1int);
    list2.push(&lol2int);
    list2.push(&lol3int);

    std::cout << "list_i<char>.size() " << list2.size() << std::endl;
    std::cout << *list2.pop() << std::endl;
    std::cout << "list_i<char>.size() " << list2.size() << std::endl;
    std::cout << *list2.pop() << std::endl;
    std::cout << "list_i<char>.size() " << list2.size() << std::endl;
    std::cout << *list2.pop() << std::endl;

    list2.push(&lol1int);
    list2.push(&lol2int);
    list2.push(&lol3int);

    std::cout << "list_i<char>.size() " << list2.size() << std::endl;

    list2.reset();

    std::cout << "list_i<char>.size() " << list2.size() << std::endl;
}
