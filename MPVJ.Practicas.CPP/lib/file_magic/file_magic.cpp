#include "file_magic.h"
#include <fstream>
#include <iostream>
#include <string>

namespace fm
{

auto open(const char *filename, const OpenMode &mode) -> void *
{
    auto ptr = new std::fstream;

    if (mode == OpenMode::Read)
        ptr->open(filename, std::ios::in);

    if (mode == OpenMode::Write)
        ptr->open(filename, std::ios::out | std::ios::trunc);

    if (ptr->is_open())
        return ptr;

    std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
    delete ptr;
    return nullptr;
}

auto close(void **file) -> void
{
    auto ptr = (std::fstream *)*file;
    ptr->close();
    delete (ptr);
    *file = nullptr; // <- probablemente peligroso
}

auto read(const void *file, char *buffer, const unsigned int &n) -> unsigned int
{
    if (!file)
    {
        std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
        return (unsigned int)0;
    }

    auto ptr = (std::fstream *)file;

    if (ptr->is_open())
    {
        std::streamsize st(n);
        ptr->get(buffer, st, '\0');
        return (unsigned int)strlen(buffer);
    }

    std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
    return (unsigned int)0;
}

auto write(const void *file, const char *buffer) -> const char *
{
    if (!file)
    {
        std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
        return nullptr;
    }

    auto ptr = (std::fstream *)file;

    if (ptr->is_open())
    {
        *ptr << buffer;
        return buffer;
    }

    std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
    return nullptr;
}

auto read_nums(const void *file) -> tkl::llist<int>
{
    tkl::llist<int> bl;

    if (!file)
    {
        std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
        return bl;
    }

    auto ptr = (std::fstream *)file;

    if (!ptr->is_open())
    {
        std::cout << "    >> UNABLE TO OPEN FILE <<" << std::endl;
        return bl;
    }

    const unsigned int toRead = 512;
    char buffer[toRead];
    std::streamsize st(toRead);
    ptr->get(buffer, st, '\0');

    auto length = strlen(buffer);
    std::string str = "";

    for (size_t i = 0; i < length; i++)
    {
        if (buffer[i] != ',')
        {
            str += buffer[i];
            continue;
        }

        bl.push(std::stoi(str));
        str = "";
    }

    if (str != "")
        bl.push(std::stoi(str));

    return bl;
}

} // namespace fm
