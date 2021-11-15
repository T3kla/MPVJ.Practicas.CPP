#include "string.h"
#include <iostream>

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
    ::memcpy(m_data, old, old_size + 1);
    delete (old);

    m_capacity = new_cap;
}

size_t string::calc_capacity(const size_t &_value)
{
    return (_value + 1) + ALLOC_INCREMENT - ((_value + 1) % ALLOC_INCREMENT);
}

void string::extract_number(const char *_src, char *_dst_, const size_t &_len, const bool &_allow_dot) const
{
    char *it_buff = _dst_;
    char *it_data = m_data;
    auto saw_point = !_allow_dot;
    auto saw_minus = false;

    auto cont = [&]() { return (*it_data != '\0') && (it_buff != _dst_ + _len - 1); };

    *_dst_ = '+';
    it_buff++;

    while (cont())
    {
        if (!saw_minus && *it_data == '-' && it_buff == _dst_ + 1)
        {
            saw_minus = true;
            *_dst_ = '-';
        }

        if (!saw_point && *it_data == '.')
        {
            saw_point = true;
            *it_buff++ = *it_data;
        }

        if (*it_data >= '0' && *it_data <= '9')
            *it_buff++ = *it_data;

        it_data++;
    }

    *it_buff = '\0';
}

#pragma region Constructors

// Default constructor
string::string()
{
    m_capacity = ALLOC_INCREMENT;
    m_size = 0;
    m_data = new char[ALLOC_INCREMENT];
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

// Constructor for constant char pointer of mutable value
string::string(const char *_value)
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
string::string(string &_value)
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
    return *this;
}

string &string::operator=(const char *_rhs)
{
    auto rhslen = strlen(_rhs);
    resize(rhslen);
    std::memcpy(m_data, _rhs, rhslen);
    m_data[m_size] = '\0';
    return *this;
}

string &string::operator=(char _rhs)
{
    resize(1);
    m_data[0] = _rhs;
    m_data[1] = '\0';
    return *this;
}

string &string::operator+=(const string &_rhs)
{
    auto old_size = m_size;
    resize(m_size + _rhs.m_size);
    std::memcpy(m_data + old_size, _rhs.m_data, _rhs.m_size + 1);
    return *this;
}

string &string::operator+=(const char *_rhs)
{
    auto old_size = m_size;
    auto rhslen = strlen(_rhs);
    resize(m_size + rhslen);
    std::memcpy(m_data + old_size, _rhs, rhslen);
    m_data[m_size] = '\0';
    return *this;
}

string &string::operator+=(char _rhs)
{
    resize(m_size + 1);
    m_data[m_size - 1] = _rhs;
    m_data[m_size] = '\0';
    return *this;
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
    char buffer[256];
    extract_number(m_data, buffer, 256, false);
    auto size = strlen(buffer);
    auto result = 0;

    for (size_t i = size - 1; i < size && i > 0; i--)
    {
        auto num = buffer[i] - '0';
        auto pos = pow(10, size - i - 1);
        result += num * pos;
    }

    if (*buffer == '-')
        result *= -1;

    return result;
}

float string::to_float() const
{
    char buffer[256];
    extract_number(m_data, buffer, 256, true);
    return ::atof(buffer);
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
    std::memcpy(new_str.m_data, m_data + _idx + (_reverse ? _len * -1 : 1), _len);
    return new_str;
}

int string::find(const string &_find, const size_t &_idx) const
{
    const auto find_len = _find.length();

    if (_idx < 0 || _idx + find_len >= m_size)
        throw "Out of range index";

    const auto data_end = m_data + m_size;

    const auto find_first = _find.m_data;
    const auto find_last = _find.m_data + find_len - 1;

    auto it_l = m_data + _idx;
    auto it_r = m_data + _idx + find_len - 1;

    while (it_r != data_end)
    {
        if (*it_l == *find_first && *it_r == *find_last)
            for (auto i = 1; i < find_len - 1; i++)
            {
                auto in_find = find_first + i;
                auto in_data = it_l + i;
                if (*in_find != *in_data)
                    break;
                if (i == find_len - 2)
                    return it_l - m_data;
            }
        it_l++;
        it_r++;
    }

    return -1;
}

void string::replace(const string &_find, const string &_rep) const
{
}

// std::ostream &operator<<(std::ostream &_os, const string &_value)
// {
//     return _os << _value.m_data;
// }

} // namespace bs
