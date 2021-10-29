#include "string.h"
#include <iostream>

namespace bs
{

void string::resize(const size_t &_size)
{
    auto capacity_new = calc_capacity(_size);

    if (m_capacity == capacity_new)
        return;

    auto data_old = m_data;
    m_data = new char[capacity_new];
    std::memcpy(m_data, data_old, m_size);
    delete (data_old);

    m_capacity = capacity_new;
}

size_t string::calc_capacity(const size_t &_value)
{
    return (size_t)(round((double)_value / (double)CHUNK + 0.5) * (double)CHUNK);
}

string::string()
{
    m_capacity = 64;
    m_size = 0;
    m_data = new char[64];
}

string::string(const char *_value)
{
    auto new_size = strlen(_value);
    m_size = new_size + 1;
    m_data = new char[calc_capacity(new_size)];
    std::memcpy(m_data, _value, new_size);
    m_data[new_size] = '\0';
}

string::string(string &_value)
{
    auto new_size = _value.m_size;
    m_size = new_size;
    m_data = new char[_value.m_capacity];
    std::memcpy(m_data, _value.m_data, new_size);
}

string::string(string &&_value) noexcept
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = _value.m_data;
    _value.m_data = nullptr;
}

string::~string()
{
    delete (m_data);
}

string string::operator+(const string &_rhs)
{
    string new_str;
    new_str.m_size = m_size - 1 + _rhs.m_size;
    new_str.resize(new_str.m_size);
    std::memcpy(new_str.m_data, m_data, m_size - 1);
    std::memcpy(new_str.m_data + m_size - 1, _rhs.m_data, _rhs.m_size);
    return new_str;
}

std::ostream &operator<<(std::ostream &_os, const string &_value)
{
    return _os << _value.m_data;
}

} // namespace bs
