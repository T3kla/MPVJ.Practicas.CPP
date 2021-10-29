#pragma once

#include "lib/file_magic/file_magic.h"
#include <iostream>
#include <stdexcept>

void run_practica_11()
{
    auto file_name = "lorem_04.txt";

    std::cout << "> Opening 'lorem_04.txt' as Read!" << std::endl;
    void *file = fm::open(file_name, fm::OpenMode::Read);

    auto badlist = fm::read_nums(file);
    auto badlist2(badlist);

    std::cout << "> Printing" << std::endl;

    auto size = badlist2.size();
    for (unsigned int i = 0; i < size; i++)
        std::cout << "    " << badlist2.next() << std::endl;

    std::cout << "> Inverting 'invert_noCopy'" << std::endl;

    bl::invert_noCopy(badlist2);

    std::cout << "> Printing" << std::endl;

    size = badlist2.size();
    for (unsigned int i = 0; i < size; i++)
        std::cout << "    " << badlist2[i]->value << std::endl;

    std::cout << "> Inverting 'invert_copy'" << std::endl;

    auto badlist3 = bl::invert_copy(badlist2);

    std::cout << "> Printing" << std::endl;

    size = badlist3.size();
    for (unsigned int i = 0; i < size; i++)
        std::cout << "    " << badlist3.next() << std::endl;
}
