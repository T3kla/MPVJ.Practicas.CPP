#pragma once

#include <iostream>

namespace bs
{

struct string
{
  private:
    static const size_t ALLOC_INCREMENT = 16;
    size_t m_size = 0;
    size_t m_capacity = ALLOC_INCREMENT;
    char *m_data = nullptr;

    void resize(const size_t &_size);
    void extract_number(const char *_src, char *_dst_, const size_t &_len, const bool &_allow_dot) const;
    inline size_t calc_capacity(const size_t &_value);
    inline void zero();
    inline void guard();

  public:
    string();
    string(const size_t &_value);
    ~string();

    string(const char *_value);
    string(char *_value);

    string(const string &_value);
    string(string &_value);

    string(const string &&_value) noexcept;
    string(string &&_value) noexcept;

    char *begin() const;
    char *end() const;

    bool operator==(const string &_rhs) const;
    bool operator!=(const string &_rhs) const;
    bool operator>(const string &_rhs) const;
    bool operator<(const string &_rhs) const;
    bool operator>=(const string &_rhs) const;
    bool operator<=(const string &_rhs) const;

    string operator+(const string &other) const;
    string operator+(const char *_rhs) const;
    string operator+(char _rhs) const;

    string &operator=(const string &_rhs);
    string &operator=(const char *_rhs);
    string &operator=(char _rhs);

    string &operator+=(const string &_rhs);
    string &operator+=(const char *_rhs);
    string &operator+=(char _rhs);

    char &operator[](size_t _idx);
    const char &operator[](size_t _idx) const;

    size_t length() const;

    int to_int() const;
    float to_float() const;
    const char *c_str() const;

    static string to_string(const float &_value);
    static string to_string(const int &_value);
    static string to_string_as_hex(const int &_value);

    // string Left(int _n) const;    // | Substituted with substr()
    // string Right(int _n) const;   // |
    // string Mid(int _ofs, int _n); // |
    string substr(const size_t &_idx, const size_t &_len, const bool &_reverse = false) const;

    bool find(const string &_find, size_t &_idx_, const size_t &_ofs = 0) const;
    bool find_last(const string &_find, size_t &_idx_, const size_t &_ofs = 0) const;
    void replace(const string &_find, const string &_rep);

    string to_upper() const;
    string to_lower() const;

    string trim_left() const;
    string trim_right() const;
    string trim() const;

    string pad_left(const size_t &_len, const char &_c) const;
    string pad_right(const size_t &_len, const char &_c) const;

    string strip_ext() const;
    string strip_dir() const;

    string extract_ext() const;
    string extract_dir() const;

    string real_path() const;

    static string read(const string &_filename);
    void write(const string &_filename, bool _append = true) const;

    friend std::ostream &operator<<(std::ostream &os, const string &b)
    {
        return os << b.m_data;
    }
};

// string &operator+(string _lhs, const string &_rhs)
//{
//     return _lhs += _rhs;
// }

} // namespace bs
