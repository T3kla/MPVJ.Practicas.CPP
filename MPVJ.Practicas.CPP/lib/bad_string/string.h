#pragma once

#include <iostream>

namespace bs
{

struct string
{
  private:
    static const size_t ALLOC_INCREMENT = 64;
    size_t m_capacity = 64;
    size_t m_size = 0;
    char *m_data = nullptr;

    void resize(const size_t &_size);
    inline size_t calc_capacity(const size_t &_value);

  public:
    string();
    string(const char *_value);
    string(string &_value);
    string(string &&_value) noexcept;
    string(const string &&_value) noexcept;
    ~string();

    const bool operator==(const string &_rhs) const;
    // const bool operator!=(const string &_rhs) const;
    // const bool operator>(const string &_rhs) const;
    // const bool operator<(const string &_rhs) const;
    const string operator+(const string &_rhs) const;
    const string operator+(const string &_rhs);
    //  const string operator+(char _rhs) const;
    //   string &operator=(const string &_rhs);
    //   string &operator=(char _rhs);
    //   string &operator+=(const string &_rhs);
    //   string &operator+=(char _rhs);
    //   char &operator[](unsigned int _index);
    //   const char &operator[](unsigned int _idx) const;

    // int Length() const;

    // int ToInt() const;
    // float ToFloat() const;
    // const char *Tostring() const;

    // string Left(int _n) const;
    // string Right(int _n) const;
    // string Mid(int _ofs, int _n);
    // string Replace(const string &_find, const string &_rep) const;
    // int Find(const string &_str, int _ofs) const;

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
