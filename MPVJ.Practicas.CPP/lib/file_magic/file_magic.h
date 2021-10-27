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
void close(void **file);

unsigned int read(const void *file, char *buffer, unsigned int n);
const char *write(const void *file, const char *buffer);

} // namespace fm
