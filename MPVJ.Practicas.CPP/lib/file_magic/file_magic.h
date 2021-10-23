#pragma once

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
unsigned int close(void **file);
unsigned int read(const void *file, char *buffer, unsigned int n);
unsigned int write(const void *file, const char *buffer, unsigned int n);

} // namespace fm
