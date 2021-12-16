#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace tkl::tf {

class TextFile {
private:
  enum class OpenMode { None, Read, Write, Clear };

  std::string filename;

  std::fstream fstream;
  std::stringstream buffer;

  bool StreamOpen(const OpenMode &mode);
  void StreamClose();

  void StreamToBuffer();
  void BufferToStream();

  unsigned long long StreamLength();
  unsigned long long BufferLength();

public:
  TextFile(const char *filename);

  std::string ToString();

  unsigned long long Read(const size_t &_index, const size_t &_length,
                          char *_buffer);
  unsigned long long Write(const size_t &_index, const char *_buffer);
};

} // namespace tkl::tf
