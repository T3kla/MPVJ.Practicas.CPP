#pragma once

#include "..\bad_list\bad_list.h"

namespace fm
{

enum class OpenMode
{
    Read,
    Write
};

auto open(const char *filename, const OpenMode &mode) -> void *;
auto close(void **file) -> void;

auto read(const void *file, char *buffer, const unsigned int &n) -> unsigned int;
auto write(const void *file, const char *buffer) -> const char *;

// practica_10
auto read_nums(const void *file) -> bl::bad_list<int>;

} // namespace fm
