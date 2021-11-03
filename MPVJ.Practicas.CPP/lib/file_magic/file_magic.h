#pragma once

#include "..\llist\llist.h"

namespace fm
{

enum class OpenMode
{
    Read,
    Write
};

void *open(const char *filename, const OpenMode &mode);
void close(void **file);

unsigned int read(const void *file, char *buffer, const unsigned int &n);
const char *write(const void *file, const char *buffer);

// practica_10
tkl::llist<int> read_nums(const void *file);

} // namespace fm
