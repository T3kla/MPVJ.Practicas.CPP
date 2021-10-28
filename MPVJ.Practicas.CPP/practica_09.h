#pragma once

#include "lib/bad_list/bad_list.h"

void run_practica_09()
{
    bl::bad_list<const char *> list_char;

    auto char_1 = "asd";
    auto char_2 = "lol";
    auto char_3 = "lma";

    list_char.push(char_1);
    list_char.push(char_2);
    list_char.push(char_3);

    std::cout << "list_char<char>.size() " << list_char.size() << std::endl;
    std::cout << list_char.pop() << std::endl;
    std::cout << "list_char<char>.size() " << list_char.size() << std::endl;
    std::cout << list_char.pop() << std::endl;
    std::cout << "list_char<char>.size() " << list_char.size() << std::endl;
    std::cout << list_char.pop() << std::endl;

    bl::bad_list<int> list_int;
    auto int_1 = 1;
    auto int_2 = 2;
    auto int_3 = 3;

    list_int.push(int_1);
    list_int.push(int_2);
    list_int.push(int_3);

    std::cout << "list_int<char>.size() " << list_int.size() << std::endl;
    std::cout << list_int.pop() << std::endl;
    std::cout << "list_int<char>.size() " << list_int.size() << std::endl;
    std::cout << list_int.pop() << std::endl;
    std::cout << "list_int<char>.size() " << list_int.size() << std::endl;
    std::cout << list_int.pop() << std::endl;

    list_int.push(int_1);
    list_int.push(int_2);
    list_int.push(int_3);

    std::cout << "list_int<char>.size() " << list_int.size() << std::endl;

    list_int.reset();

    std::cout << "list_int<char>.size() " << list_int.size() << std::endl;
}
