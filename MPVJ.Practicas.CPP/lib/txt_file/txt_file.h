#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace tf
{

class txt_file
{
  private:
    enum class OpenMode
    {
        None,
        Read,
        Write
    };

    std::string m_fileName;
    std::stringstream m_buffer;
    std::fstream m_stream;

    bool open(const OpenMode &mode);
    void refresh();
    void close();
    unsigned long long length();

  public:
    txt_file(const char *filename);

    unsigned long long read(const unsigned long long &_index, const unsigned long long &_length, char *_buffer);

    unsigned long long write(const unsigned long long &_index, const char *_buffer);

    // void clear();
};

} // namespace tf
