#include "txt_file.h"

tf::txt_file::txt_file(const char *_file_name)
{
    this->m_fileName = _file_name;

    refresh();
}

bool tf::txt_file::open(const OpenMode &_mode)
{
    if (_mode == OpenMode::Read)
        m_stream.open(m_fileName, std::ios::in);

    if (_mode == OpenMode::Write)
        m_stream.open(m_fileName, std::ios::out | std::ios::trunc);

    if (!m_stream.is_open())
    {
        std::cout << "    Unable to open file '" << m_fileName << "'" << std::endl;
        return false;
    }

    return true;
}

void tf::txt_file::refresh()
{
    if (!open(OpenMode::Read))
        return;

    m_buffer.clear();
    m_buffer << m_stream.rdbuf();
    m_buffer << '\0';

    close();
}

void tf::txt_file::close()
{
    if (m_stream.is_open())
        m_stream.close();
}

unsigned long long tf::txt_file::length()
{
    m_buffer.seekg(0, std::ios::end);
    unsigned long long length = m_buffer.tellg();
    m_buffer.seekg(0, std::ios::beg);
    return length;
}

unsigned long long tf::txt_file::read(const unsigned long long &_index, const unsigned long long &_length,
                                      char *buffer_)
{
    if (_length == 0)
        return 0;

    unsigned long long buffer_length = length();

    if (_index + _length > buffer_length)
    {
        std::cout << "    Unable to read file '" << m_fileName << "' given that index and length" << std::endl;
        close();
        return 0;
    }

    m_buffer.seekg(_index);
    m_buffer.get(buffer_, _length + 1, '\0');
    m_buffer.seekg(0, std::ios::beg);

    return strlen(buffer_);
}

unsigned long long tf::txt_file::write(const unsigned long long &_index, const char *_buffer)
{
    if (!open(OpenMode::Write))
        return 0;

    m_stream.seekg(0, std::ios::end);
    unsigned long long stream_length = m_stream.tellg();
    m_stream.seekg(0, std::ios::beg);

    if (_index > stream_length)
    {
        std::cout << "    Unable to write file '" << m_fileName << "' given that index" << std::endl;
        close();
        return 0;
    }

    m_stream.seekg(0, _index);
    m_stream << _buffer;

    close();

    refresh();
    return 0;
}
