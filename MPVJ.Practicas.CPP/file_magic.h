#pragma once

#include "tlist.h"

namespace tkl::fmg {

enum class OpenMode { Read, Write };

void *Open(const char *filename, const OpenMode &mode);
void Close(void **file);

unsigned int Read(const void *file, char *buffer, const unsigned int &n);
const char *Write(const void *file, const char *buffer);

// practica_10
tkl::TList<int> ReadNums(const void *file);

} // namespace tkl::fmg
