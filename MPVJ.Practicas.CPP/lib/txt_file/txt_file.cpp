#include "txt_file.h"

tf::txt_file::txt_file(const char *_file_name)
{
    this->m_fileName = _file_name;
    stream_to_buffer();
}

void tf::txt_file::stream_to_buffer()
{
    if (!stream_open(OpenMode::Read))
        return;

    m_buffer.clear();
    m_buffer << m_stream.rdbuf();

    stream_close();
}

bool tf::txt_file::stream_open(const OpenMode &_mode)
{
    if (_mode == OpenMode::Read)
        m_stream.open(m_fileName, std::ios::in);

    if (_mode == OpenMode::Write)
        m_stream.open(m_fileName, std::ios::out | std::ios::app);

    if (_mode == OpenMode::Clear)
        m_stream.open(m_fileName, std::ios::out | std::ios::trunc);

    if (!m_stream.is_open())
    {
        std::cout << "    Unable to open file '" << m_fileName << "'" << std::endl;
        return false;
    }

    return true;
}

void tf::txt_file::stream_close()
{
    if (m_stream.is_open())
        m_stream.close();
}

void tf::txt_file::buffer_to_stream()
{
    if (!stream_open(OpenMode::Clear))
        return;

    stream_close();

    if (!stream_open(OpenMode::Write))
        return;

    m_stream << m_buffer.rdbuf();

    stream_close();
}

unsigned long long tf::txt_file::buffer_length()
{
    m_buffer.seekg(0, std::ios::end);
    unsigned long long length = m_buffer.tellg();
    m_buffer.seekg(0, std::ios::beg);
    return length;
}

unsigned long long tf::txt_file::stream_length()
{
    if (!m_stream.is_open())
        return 0;
    m_stream.seekg(0, std::ios::end);
    unsigned long long length = m_stream.tellg();
    m_stream.seekg(0, std::ios::beg);
    return length;
}

std::string tf::txt_file::str()
{
    return m_buffer.str();
}

unsigned long long tf::txt_file::read(const unsigned long long &_index, const unsigned long long &_length,
                                      char *buffer_)
{
    if (_length == 0)
        return 0;

    if (_index + _length > buffer_length())
    {
        std::cout << "    Unable to read file '" << m_fileName << "' given that index and length" << std::endl;
        stream_close();
        return 0;
    }

    m_buffer.seekg(0, _index);
    m_buffer.get(buffer_, _length + 1, '\0');
    m_buffer.seekg(0, std::ios::beg);

    return strlen(buffer_);
}

unsigned long long tf::txt_file::write(const unsigned long long &_index, const char *_buffer)
{
    auto buff_length = buffer_length();
    auto in_buff_length = strlen(_buffer);

    if (_index > buff_length)
    {
        std::cout << "    Unable to write file '" << m_fileName << "' given that index" << std::endl;
        return 0;
    }

    std::string arr[2];

    arr[0] = m_buffer.str().substr(0, _index);
    arr[1] = m_buffer.str().substr(_index, buff_length);

    m_buffer.str(std::string());

    m_buffer << arr[0];
    m_buffer.write(_buffer, in_buff_length);
    m_buffer << arr[1];

    buffer_to_stream();

    return in_buff_length;
}
