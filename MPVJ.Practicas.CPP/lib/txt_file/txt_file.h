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
        Write,
        Clear
    };

    std::string m_fileName;

    std::fstream m_stream;
    std::stringstream m_buffer;

    bool stream_open(const OpenMode &mode);
    void stream_close();

    void stream_to_buffer();
    void buffer_to_stream();

    unsigned long long stream_length();
    unsigned long long buffer_length();

  public:
    txt_file(const char *filename);

    std::string str();
    unsigned long long read(const unsigned long long &_index, const unsigned long long &_length, char *_buffer);
    unsigned long long write(const unsigned long long &_index, const char *_buffer);

    // void clear();
};

} // namespace tf
