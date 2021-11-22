#include "string.h"
#include <filesystem>
#include <fstream>
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
    ::memcpy(m_data, old, old_size);
    delete (old);
    m_capacity = new_cap;
}

void string::extract_number(const char *_src, char *_dst_, const size_t &_len, const bool &_allow_dot) const
{
    char *it_buff = _dst_;
    auto *it = begin();
    auto *end = this->end();
    auto saw_point = !_allow_dot;
    auto saw_minus = false;

    auto cont = [&]() { return (it != end) && (it_buff != _dst_ + _len - 1); };

    *_dst_ = '+';
    it_buff++;

    while (cont())
    {
        if (!saw_minus && *it == '-' && it_buff == _dst_ + 1)
        {
            saw_minus = true;
            *_dst_ = '-';
        }

        if (!saw_point && *it == '.')
        {
            saw_point = true;
            *it_buff++ = *it;
        }

        if (*it >= '0' && *it <= '9')
            *it_buff++ = *it;

        it++;
    }

    *it_buff = '\0';
}

inline size_t string::calc_capacity(const size_t &_value)
{
    return (_value + 1) + ALLOC_INCREMENT - ((_value + 1) % ALLOC_INCREMENT);
}

inline void string::zero()
{
    for (auto i = 0ull; i < length(); i++)
        m_data[i] = ' ';
    guard();
}

inline void string::guard()
{
    m_data[m_size] = '\0';
}

#pragma region Constructors

// Default constructor
string::string()
{
    m_capacity = ALLOC_INCREMENT;
    m_size = 0;
    m_data = new char[ALLOC_INCREMENT];
    zero();
    guard();
}

// Alloc hint constructor
string::string(const size_t &_value)
{
    m_capacity = calc_capacity(_value);
    m_size = _value;
    m_data = new char[m_capacity];
    zero();
    guard();
}

// Default destructor
string::~string()
{
    if (m_data != nullptr)
        delete (m_data);
}

// Constructor for constant char pointer of mutable value
string::string(const char *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    guard();
}

// Constructor for char pointer of mutable value
string::string(char *_value)
{
    m_size = strlen(_value);
    m_capacity = calc_capacity(m_size);
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value, m_size);
    guard();
}

// Constructor for constant string reference of constant value
//                 ^^^^^^^^ -> not an error, references are always constant
string::string(const string &_value)
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[_value.m_capacity];
    std::memcpy(m_data, _value.m_data, m_size);
    guard();
}

// Constructor for constant string reference of mutable value
//                 ^^^^^^^^ -> not an error, references are always constant
string::string(string &_value)
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[_value.m_capacity];
    std::memcpy(m_data, _value.m_data, m_size);
    guard();
}

// Constructor for constant string rvalue of mutable value
//                 ^^^^^^^^ -> not an error, references are always constant
// Can't be pointer yoinked
string::string(const string &&_value) noexcept
{
    m_size = _value.m_size;
    m_capacity = _value.m_capacity;
    m_data = new char[m_capacity];
    std::memcpy(m_data, _value.m_data, m_size);
    guard();
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
    return length() > _rhs.length();
}

bool string::operator<(const string &_rhs) const
{
    return length() < _rhs.length();
}

bool string::operator>=(const string &_rhs) const
{
    return length() >= _rhs.length();
}

bool string::operator<=(const string &_rhs) const
{
    return length() <= _rhs.length();
}

string string::operator+(const string &_rhs) const
{
    auto result = string(m_size + _rhs.m_size);
    std::memcpy(result.m_data, m_data, m_size);
    std::memcpy(result.m_data + m_size, _rhs.m_data, _rhs.m_size + 1);
    return result;
}

string string::operator+(const char *_rhs) const
{
    auto rhslen = strlen(_rhs);
    auto result = string(m_size + rhslen);
    std::memcpy(result.m_data, m_data, m_size);
    std::memcpy(result.m_data + m_size, _rhs, rhslen);
    result.guard();
    return result;
}

string string::operator+(char _rhs) const
{
    auto result = string(m_size + 1);
    std::memcpy(result.m_data, m_data, m_size);
    result.m_data[m_size - 1] = _rhs;
    result.guard();
    return result;
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
    guard();
    return *this;
}

string &string::operator=(char _rhs)
{
    resize(1);
    m_data[0] = _rhs;
    guard();
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
    guard();
    return *this;
}

string &string::operator+=(char _rhs)
{
    resize(m_size + 1);
    m_data[m_size - 1] = _rhs;
    guard();
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

char *string::begin() const
{
    return m_data;
}

char *string::end() const
{
    return m_data + m_size;
}

size_t string::length() const
{
    return m_size;
}

int string::to_int() const
{
    // Se que hay maneras mas faciles, pero tenia ganas de hacerlo asi
    char buffer[64];
    extract_number(m_data, buffer, 64, false);
    auto size = strlen(buffer);
    auto result = 0;

    for (size_t i = size - 1; i < size && i > 0; i--)
    {
        auto num = buffer[i] - '0';
        auto pos = pow(10, size - i - 1);
        result += num * (int)pos;
    }

    if (*buffer == '-')
        result *= -1;

    return result;
}

float string::to_float() const
{
    char buffer[64];
    extract_number(m_data, buffer, 64, true);
    return (float)::atof(buffer);
}

const char *string::c_str() const
{
    return m_data;
}

string string::to_string(const float &_value)
{
    char buffer[64];
    snprintf(buffer, 64, "%f", _value);
    return string(buffer);
}

string string::to_string(const int &_value)
{
    char buffer[64];
    _itoa_s(_value, buffer, 10);
    return string(buffer);
}

string string::to_string_as_hex(const int &_value)
{
    char buffer[64];
    _itoa_s(_value, buffer, 16);
    return string(buffer);
}

string string::substr(const size_t &_idx, const size_t &_len, const bool &_reverse) const
{
    if (_idx < 0 || _idx + _len > m_size)
        throw "Out of range index";
    if (_reverse && m_size - _idx - _len < 0)
        throw "Out of range index";
    auto result = string(_len);
    std::memcpy(result.m_data, m_data + (_reverse ? m_size - _idx - _len : _idx), _len);
    result.guard();
    return result;
}

// bool find(const string &_find, size_t &_idx_, const size_t &_ofs) const;
// bool find_last(const string &_find, size_t &_idx_, const size_t &_ofs) const;

bool string::find(const string &_find, size_t &_idx_, const size_t &_ofs) const
{
    const auto find_len = _find.length();

    if (_ofs < 0 || _ofs + find_len >= m_size)
        throw "Out of range index";

    const auto &find_l = _find.begin();
    const auto &find_r = _find.end() - 1;

    auto it_l = begin() + _ofs;
    auto it_r = begin() + _ofs + find_len - 1;

    while (it_r != end())
    {
        if (*it_l == *find_l && *it_r == *find_r)
        {
            if (find_len <= 2)
            {
                _idx_ = it_l - m_data;
                return true;
            }
            for (auto i = 1; i < find_len - 1; i++)
            {
                auto in_find = find_l + i;
                auto in_data = it_l + i;
                if (*in_find != *in_data)
                    break;
                if (i == find_len - 2)
                {
                    _idx_ = it_l - m_data;
                    return true;
                }
            }
        }
        it_l++;
        it_r++;
    }

    return false;
}

bool string::find_last(const string &_find, size_t &_idx_, const size_t &_ofs) const
{
    const auto find_len = _find.length();

    if (_ofs < 0 || _ofs + find_len >= m_size)
        throw "Out of range index";

    const auto &find_l = _find.begin();
    const auto &find_r = _find.end() - 1;

    auto it_l = end() - find_len;
    auto it_r = end() - 1;

    while (it_l != begin() + _ofs)
    {
        if (*it_l == *find_l && *it_r == *find_r)
        {
            if (find_len <= 2)
            {
                _idx_ = it_l - m_data;
                return true;
            }
            for (auto i = 1; i < find_len - 1; i++)
            {
                auto in_find = find_l + i;
                auto in_data = it_l + i;
                if (*in_find != *in_data)
                    break;
                if (i == find_len - 2)
                {
                    _idx_ = it_l - m_data;
                    return true;
                }
            }
        }
        it_l--;
        it_r--;
    }

    return false;
}

void string::replace(const string &_find, const string &_rep)
{
    auto idx = 0ull;
    auto ofs = 0ull;
    auto len_find = _find.length();
    auto len_rep = _rep.length();
    auto len_dif = len_rep - len_find;

    while (find(_find, idx, ofs))
    {
        auto old_size = m_size;
        resize(m_size + len_dif);
        ::memcpy(m_data + idx + len_rep, m_data + idx + len_find, (old_size + 1) - (idx + len_find));
        ::memcpy(m_data + idx, _rep.m_data, len_rep);
        ofs = idx + len_rep;
    }

    guard();
}

string string::to_upper() const
{
    auto result = string(*this);
    auto *beg = result.begin();
    auto *end = result.end();

    for (beg; beg != end; beg++)
        if (*beg >= 'a' && *beg <= 'z')
            (*beg) += 'A' - 'a';

    return result;
}

string string::to_lower() const
{
    auto result = string(*this);
    auto *beg = result.begin();
    auto *end = result.end();

    for (beg; beg != end; beg++)
        if (*beg >= 'A' && *beg <= 'Z')
            (*beg) += 'a' - 'A';

    return result;
}

string string::trim_left() const
{
    auto whites = 0;
    auto *beg = this->begin();
    auto *end = this->end();

    while (iswspace(*beg) != 0 && beg++ < end)
        whites++;

    return substr(whites, m_size - whites);
}

string string::trim_right() const
{
    auto whites = 0;
    auto *beg = this->begin();
    auto *end = this->end() - 1;

    while (iswspace(*end) != 0 && end-- >= beg)
        whites++;

    return substr(0, m_size - whites);
}

string string::trim() const
{
    return trim_left().trim_right();
}

string string::pad_left(const size_t &_len, const char &_c) const
{
    if (length() >= _len)
        return substr(0, _len, true);

    auto result = string(_len);
    auto diff = _len - m_size;
    ::memcpy(result.m_data + diff, m_data, m_size);

    for (size_t i = 0; i < diff; i++)
        result.m_data[i] = _c;

    result.guard();
    return result;
}

string string::pad_right(const size_t &_len, const char &_c) const
{
    if (length() >= _len)
        return substr(0, _len);

    auto result = string(_len);
    auto diff = _len - m_size;
    ::memcpy(result.m_data, m_data, m_size);

    for (size_t i = 0; i < diff; i++)
        result.m_data[m_size + i] = _c;

    result.guard();
    return result;
}

string string::strip_ext() const
{
    auto idx = 0ull;
    if (find_last(".", idx))
        return substr(0, idx);
    return *this;
}

string string::strip_dir() const
{
    auto idx = 0ull;
    if (find_last("/", idx))
        return substr(0, length() - idx - 1, true);
    return *this;
}

string string::extract_ext() const
{
    auto idx = 0ull;
    if (find_last(".", idx))
        return substr(0, length() - idx - 1, true);
    return *this;
}

string string::extract_dir() const
{
    auto idx = 0ull;
    if (find_last("/", idx))
        return substr(0, idx);
    return *this;
}

string string::real_path() const
{
    // No sé si esto es lo que pides pero vaya, que filesystem
    // tiene como mil maneras de hacer esto según parece.
    auto cur = std::filesystem::current_path().u8string();
    cur.append("\\");
    cur.append(c_str());
    return string(cur.c_str());
}

string string::read(const string &_filename)
{
    std::fstream stream;
    auto fn = std::string(_filename.c_str());
    stream.open(fn, std::ios::in);

    stream.seekg(0, std::ios::end);
    size_t file_len = stream.tellg();
    stream.seekg(0, std::ios::beg);

    auto result = string(file_len);
    stream.read(result.m_data, file_len);
    stream.close();
    return result;
}

void string::write(const string &_filename, bool _append) const
{
    std::fstream stream;
    auto fn = std::string(_filename.c_str());
    stream.open(fn, std::ios::out | (_append ? std::ios::app : std::ios::trunc));
    stream.write(c_str(), length());
    stream.close();
}

} // namespace bs
