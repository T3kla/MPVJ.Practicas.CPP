#pragma once

#include "lib/file_magic/file_magic.h"
#include <iostream>
#include <string>

namespace p06
{

unsigned int word_count_appearaces(const char *buffer, const char *word)
{
    unsigned int word_size = strlen(word);
    long diff = strlen(buffer) - word_size;

    if (diff < 1)
        return 0;

    unsigned int count = 0;
    char *it = const_cast<char *>(buffer);

    for (size_t i = 0; i < diff; i++)
    {
        if (*it == *word && *(it + word_size - 1) == *(word + word_size - 1))
            for (unsigned int j = 1; j < word_size - 1; j++)
            {
                if (*(it + j) != *(word + j))
                    break;
                else if (j == word_size - 2)
                    count++;
            }

        it++;
    }

    return count;
}

} // namespace p06

void run_practica_06()
{
    auto file_name_01 = "lorem_01.txt";
    auto file_name_02 = "lorem_02.txt";
    char buffer[512];

    std::cout << "> Opening 'lorem_01.txt' as Read!" << std::endl;
    void *file = fm::open(file_name_01, fm::OpenMode::Read);
    void **f_wrap = &file;

    unsigned int count = 0;

    std::cout << std::endl;

    std::cout << "Reading 512 chars: " << std::endl;
    count = fm::read(file, buffer, 512);
    std::cout << "    Actual read: " << count << std::endl;

    std::cout << std::endl;

    std::cout << "Searching appearances of word 'Lorem': " << std::endl;
    count = p06::word_count_appearaces(buffer, "Lorem");
    std::cout << "    Found: " << count << std::endl;

    std::cout << std::endl;

    std::cout << "> Closing file!" << std::endl;
    fm::close(f_wrap);

    std::cout << std::endl;

    std::cout << "> Opening 'lorem_02.txt' as Read!" << std::endl;
    file = fm::open(file_name_02, fm::OpenMode::Read);

    std::cout << std::endl;

    std::cout << "Reading 512 chars: " << std::endl;
    count = fm::read(file, buffer, 512);
    std::cout << "    Actual read: " << count << std::endl;

    std::cout << std::endl;

    std::cout << "Searching appearances of word 'Lorem': " << std::endl;
    count = p06::word_count_appearaces(buffer, "Lorem");
    std::cout << "    Found: " << count << std::endl;

    std::cout << std::endl;

    std::cout << "> Closing file!" << std::endl;
    fm::close(f_wrap);
}
