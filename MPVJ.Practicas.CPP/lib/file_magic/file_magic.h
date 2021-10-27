#pragma once

#include "..\bad_list\bad_list.h"
#include <fstream>
#include <iostream>
#include <string>

namespace fm
{

enum class OpenMode
{
    Read,
    Write
};

void *open(const char *filename, const OpenMode &mode);
void close(void **file);

unsigned int read(const void *file, char *buffer, unsigned int n);
const char *write(const void *file, const char *buffer);

// practica_10
// función que lea strings en plan "14,56,2,35" y devuelva bad_list
// bl::bad_list<char*> lmao()

} // namespace fm
