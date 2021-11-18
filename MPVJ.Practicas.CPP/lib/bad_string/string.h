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
    inline size_t calc_capacity(const size_t &_value);
    // size_t round_up(const size_t &to_round, const size_t &multiple);
    void extract_number(const char *_src, char *_dst_, const size_t &_len, const bool &_allow_dot) const;

  public:
    string();                               // |
    string(const size_t &_value);           // |
    ~string();                              // |
                                            //
    string(const char *_value);             // |
    string(char *_value);                   // |
                                            //
    string(const string &_value);           // |
    string(string &_value);                 // |
                                            //
    string(const string &&_value) noexcept; // |
    string(string &&_value) noexcept;       // |

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

    // string Left(int _n) const;    // | Substituted with substr()
    // string Right(int _n) const;   // |
    // string Mid(int _ofs, int _n); // |
    string substr(const size_t &_idx, const size_t &_len, const bool &_reverse) const;

    int find(const string &_find, const size_t &_idx = 0) const;
    void replace(const string &_find, const string &_rep);

    // string ToUpper() const;
    // string ToLower() const;
    // string LTrim() const;
    // string RTrim() const;
    // string Trim() const;

    // string LPad(int _len, char _c) const;
    // string RPad(int _len, char _c) const;

    // string StripExt() const;
    // string StripDir() const;
    // string ExtractExt() const;
    // string ExtractDir() const;
    // string RealPath() const;

    // static string FromInt(int _val);
    // static string HexFromInt(int _val);
    // static string FromFloat(float _val);

    // static string Read(const string &_filename);
    // void Write(const string &_filename, bool _append = true) const;

    friend std::ostream &operator<<(std::ostream &_os, const string &_value);
};

} // namespace bs
