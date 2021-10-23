#pragma once

#include "lib/file_magic/file_magic.h"

void run_practica_05()
{

    std::string file_name = "lmao.txt";
    char buffer[512];

    std::cout << "> Opening file as Read!" << std::endl;
    void *file = fm::open(file_name.c_str(), fm::OpenMode::Read);
    void **f_wrap = &file;

    unsigned int count = 0;

    std::cout << std::endl;

    std::cout << "Reading 50 chars: " << std::endl;
    count = fm::read(file, buffer, 50);
    std::cout << "    Actually read: " << count << std::endl << "    " << buffer << std::endl;

    // Simpre sale 1 menos en el counted porque rellena
    // el último caracter con '\0' y el strlen no lo cuenta.
    //
    // Que tiene sentido, porque si no estaría escribiendo 1
    // caracter de más y si le digo buffer de 50 y me escribe
    // 51 pues petaría supongo.

    std::cout << std::endl;

    std::cout << "> Closing file!" << std::endl;
    fm::close(f_wrap);

    std::cout << std::endl;

    std::cout << "Reading 100 chars: " << std::endl;
    count = fm::read(file, buffer, 100);
    std::cout << "    Actually read: " << count << std::endl << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "> Opening file as Read!" << std::endl;
    file = fm::open(file_name.c_str(), fm::OpenMode::Read);

    std::cout << std::endl;

    std::cout << "Reading 256 chars: " << std::endl;
    count = fm::read(file, buffer, 256);
    std::cout << "    Actually read: " << count << std::endl << "    " << buffer << std::endl;

    std::cout << std::endl;

    std::cout << "> Closing file!" << std::endl;
    fm::close(f_wrap);

    std::cout << std::endl;

    std::cout << "> Opening file as Write!" << std::endl;
    file = fm::open(file_name.c_str(), fm::OpenMode::Write);

    std::cout << std::endl;

    std::cout << "Writting 256 chars: " << std::endl;
    fm::write(file, buffer, 256);
    std::cout << "    " << buffer << std::endl;

    std::cout << std::endl;
}
