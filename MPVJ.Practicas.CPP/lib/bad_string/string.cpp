#include "string.h"
#include <iostream>
#include <string>

namespace bs
{

// Resize allocated memory base on size taking care of '\\0' termination
void string::resize(const size_t &_size)
{
    auto new_cap = calc_capacity(_size);
    auto old_size = m_size;
    m_size = _size;

    if (m_capacity == new_cap)
        return;

    auto old = m_data;
    m_data = new char[new_cap];
    std::memcpy(m_data, old, old_size + 1);
    delete (old);

    m_capacity = new_cap;
}

size_t string::calc_capacity(const size_t &_value)
{
    return (_value + 1) + ALLOC_INCREMENT - ((_value + 1) % ALLOC_INCREMENT);
}

#pragma region Constructors

// Default constructor
string::string()
{
    m_capacity = 64;
    m_size = 0;
    m_data = new char[64];
}

// Alloc hint constructor
string::string(const size_t &_value)
{
    m_capacity = calc_capacity(_value);
    m_size = _value;
    m_data = new char[m_capacity];
}

// Default destructor
string::~string()
{
    delete (m_data);
}

// Constructor for constant char pointer of constant value
string::string(const char const *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    m_data[m_size] = '\0';
}

// Constructor for constant char pointer of mutable value
string::string(const char *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    m_data[m_size] = '\0';
}

// Constructor for char pointer of constant value
string::string(char const *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    m_data[m_size] = '\0';
}

// Constructor for char pointer of mutable value
string::string(char *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    m_data[m_size] = '\0';
}

// Constructor for constant string reference of constant value
//                 ^^^^^^^^ -> not an error, references are always constant
string::string(const string &_value)
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[_value.m_capacity];
    std::memcpy(m_data, _value.m_data, m_size + 1);
}

// Constructor for constant string reference of mutable value
//                 ^^^^^^^^ -> not an error, references are always constant
string::string(const string &_value)
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[_value.m_capacity];
    std::memcpy(m_data, _value.m_data, m_size + 1);
}

// Constructor for constant string rvalue of mutable value
//                 ^^^^^^^^ -> not an error, references are always constant
// Can't be pointer yoinked
string::string(const string &&_value) noexcept
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value.m_data, m_size + 1);
}

// Constructor for constant string rvalue of mutable value
//                 ^^^^^^^^ -> not an error, references are always constant
// Can be pointer yoinked
string::string(string &&_value) noexcept
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = _value.m_data;
    _value.m_data = nullptr;
}

#pragma endregion

#pragma region Operators

bool string::operator==(const string &_rhs) const
{
    return *m_data == *_rhs.m_data;
}

bool string::operator!=(const string &_rhs) const
{
    return *m_data != *_rhs.m_data;
}

bool string::operator>(const string &_rhs) const
{
    return m_size > _rhs.m_size;
}

bool string::operator<(const string &_rhs) const
{
    return m_size < _rhs.m_size;
}

bool string::operator>=(const string &_rhs) const
{
    return m_size >= _rhs.m_size;
}

bool string::operator<=(const string &_rhs) const
{
    return m_size <= _rhs.m_size;
}

string string::operator+(const string &_rhs) const
{
    auto new_str = string(m_size + _rhs.m_size);
    std::memcpy(new_str.m_data, m_data, m_size);
    std::memcpy(new_str.m_data + m_size, _rhs.m_data, _rhs.m_size + 1);
    return new_str;
}

string string::operator+(const char *_rhs) const
{
    auto rhslen = strlen(_rhs);
    auto new_str = string(m_size + rhslen);
    std::memcpy(new_str.m_data, m_data, m_size);
    std::memcpy(new_str.m_data + m_size, _rhs, rhslen);
    new_str.m_data[m_size] = '\0';
    return new_str;
}

string string::operator+(char _rhs) const
{
    auto new_str = string(m_size + 1);
    std::memcpy(new_str.m_data, m_data, m_size);
    new_str.m_data[m_size - 1] = _rhs;
    new_str.m_data[m_size] = '\0';
    return new_str;
}

string &string::operator=(const string &_rhs)
{
    resize(_rhs.m_size);
    std::memcpy(m_data, _rhs.m_data, _rhs.m_size + 1);
}

string &string::operator=(const char *_rhs)
{
    auto rhslen = strlen(_rhs);
    resize(rhslen);
    std::memcpy(m_data, _rhs, rhslen);
    m_data[m_size] = '\0';
}

string &string::operator=(char _rhs)
{
    resize(1);
    m_data[0] = _rhs;
    m_data[1] = '\0';
}

string &string::operator+=(const string &_rhs)
{
    auto old_size = m_size;
    resize(m_size + _rhs.m_size);
    std::memcpy(m_data + old_size, _rhs.m_data, _rhs.m_size + 1);
}

string &string::operator+=(const char *_rhs)
{
    auto old_size = m_size;
    auto rhslen = strlen(_rhs);
    resize(m_size + rhslen);
    std::memcpy(m_data + old_size, _rhs, rhslen);
    m_data[m_size] = '\0';
}

string &string::operator+=(char _rhs)
{
    resize(m_size + 1);
    m_data[m_size - 1] = _rhs;
    m_data[m_size] = '\0';
}

char &string::operator[](size_t _idx)
{
    if (_idx < 0 || _idx >= m_size)
        throw "Out of range index";
    return m_data[_idx];
}

const char &string::operator[](size_t _idx) const
{
    if (_idx < 0 || _idx >= m_size)
        throw "Out of range index";
    return m_data[_idx];
}

#pragma endregion

size_t string::length() const
{
    return m_size;
}

int string::to_int() const
{
    return std::stoi(m_data);
}

float string::to_float() const
{
    return std::stof(m_data);
}

const char *string::c_str() const
{
    return m_data;
}

string string::substr(const size_t &_idx, const size_t &_len, const bool &_reverse = false) const
{
    if (_idx < 0 || _idx + _len >= m_size)
        throw "Out of range index";
    if (_reverse && _idx - _len < 0)
        throw "Out of range index";
    auto new_str = string(_len);
    std::memcpy(new_str.m_data, m_data + _idx + (_reverse ? -_len : 1), _len);
    return new_str;
}

size_t string::find(const string &_str, const size_t &_idx) const
{
    if (_idx < 0 || _idx >= m_size)
        throw "Out of range index";

    const auto beg = m_data + _idx;
    const auto end = m_data + m_size;
    const auto len = _str.length();
    auto it = m_data + _idx;

    while (it + len - 1 <= end)
    {
        /* code */
    }
}

void string::replace(const string &_find, const string &_rep) const
{
}

// std::ostream &operator<<(std::ostream &_os, const string &_value)
// {
//     return _os << _value.m_data;
// }

} // namespace bs
