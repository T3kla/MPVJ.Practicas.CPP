#pragma once

#include "lib/txt_file/txt_file.h"

void run_practica_08()
{
    tf::txt_file file_01("lorem_01.txt");
    tf::txt_file file_02("lorem_02.txt");
    tf::txt_file file_03("lorem_03.txt");

    char buffer[512];

    unsigned long long count = 0;

    std::cout << "Reading 200 chars from 'lorem_01.txt': " << std::endl;
    count = file_01.read(0, 200, buffer);
    std::cout << "    Actual read: " << count << std::endl;
    std::cout << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "Reading 400 chars from 'lorem_02.txt': " << std::endl;
    count = file_02.read(0, 400, buffer);
    std::cout << "    Actual read: " << count << std::endl;
    std::cout << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "Reading 500 chars from 'lorem_02.txt': " << std::endl;
    count = file_02.read(0, 500, buffer);
    std::cout << "    Actual read: " << count << std::endl;
    std::cout << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "Reading 10 chars from 'lorem_03.txt': " << std::endl;
    count = file_03.read(0, 10, buffer);
    std::cout << "    Actual read: " << count << std::endl;
    std::cout << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "Writting 10 chars from 'lorem_03.txt': " << std::endl;
    count = file_03.write(5, "lmao");
    std::cout << "    Actual written: " << count << std::endl;
    std::cout << "    " << file_03.str() << std::endl;
}
