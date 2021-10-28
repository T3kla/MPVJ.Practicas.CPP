#pragma once

#include "lib/file_magic/file_magic.h"
#include <iostream>

void run_practica_11()
{
    auto file_name = "lorem_04.txt";

    std::cout << "> Opening 'lorem_04.txt' as Read!" << std::endl;
    void *file = fm::open(file_name, fm::OpenMode::Read);

    auto badlist = fm::read_nums(file);

    auto badlist2(badlist);

    std::cout << badlist2[2]->value << std::endl;
}
