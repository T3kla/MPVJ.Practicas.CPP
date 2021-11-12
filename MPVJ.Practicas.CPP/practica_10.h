#pragma once

#include "lib/file_magic/file_magic.h"

void run_practica_10()
{
    auto file_name = "lorem_04.txt";

    std::cout << "> Opening 'lorem_04.txt' as Read!" << std::endl;
    void *file = fm::open(file_name, fm::OpenMode::Read);

    auto badlist = fm::read_nums(file);

    std::cout << "Retrieved by first:" << std::endl;

    std::cout << "    " << badlist.first() << std::endl;

    std::cout << "Retrieved by next 30 times because I can:" << std::endl;

    for (unsigned int i = 0; i < 30; i++)
        std::cout << "    " << badlist.next() << std::endl;

    std::cout << "Retrieved by pop:" << std::endl;

    auto size = badlist.size();
    for (unsigned int i = 0; i < size; i++)
        std::cout << "    " << badlist.pop() << std::endl;
}
