#include "file_magic.h"

namespace fm
{

void *open(const char *filename, const OpenMode &mode)
{
    auto ptr = new std::fstream;

    if (mode == OpenMode::Read)
        ptr->open(filename, std::ios::in);

    if (mode == OpenMode::Write)
        ptr->open(filename, std::ios::out | std::ios::trunc);

    if (ptr->is_open())
        return ptr;

    std::cout << "    Unable to open file" << std::endl;
    delete ptr;
    return nullptr;
}

void close(void **file)
{
    auto ptr = (std::fstream *)*file;
    ptr->close();
    delete (ptr);
    *file = nullptr; // <- probablemente peligroso
}

unsigned int read(const void *file, char *buffer, unsigned int n)
{
    if (!file)
    {
        std::cout << "    Unable to open file" << std::endl;
        return (unsigned int)0;
    }

    auto ptr = (std::fstream *)file;

    if (ptr->is_open())
    {
        std::streamsize st(n);
        ptr->get(buffer, n, '\0');
        return (unsigned int)strlen(buffer);
    }

    std::cout << "    Unable to open file" << std::endl;
    return (unsigned int)0;
}

const char *write(const void *file, const char *buffer)
{
    if (!file)
    {
        std::cout << "    Unable to open file" << std::endl;
        return nullptr;
    }

    auto ptr = (std::fstream *)file;

    if (ptr->is_open())
    {
        *ptr << buffer;
        return buffer;
    }

    std::cout << "    Unable to open file" << std::endl;
    return nullptr;
}

} // namespace fm
