#pragma once

#include <iostream>

namespace tkl::str {

struct Str {
private:
  static const size_t ALLOC_INCREMENT = 16;
  size_t size = 0;
  size_t capacity = ALLOC_INCREMENT;
  char *data = nullptr;

  void Resize(const size_t &_size);
  void ExtractNum(const char *_src, char *_dst_, const size_t &_len,
                  const bool &_allow_dot) const;
  inline size_t CalcCapacity(const size_t &_value);
  inline void Zero();
  inline void Guard();

public:
  Str();
  Str(const size_t &_value);
  ~Str();

  Str(const char *_value);
  Str(char *_value);

  Str(const Str &_value);
  Str(Str &_value);

  Str(const Str &&_value) noexcept;
  Str(Str &&_value) noexcept;

  char *begin() const;
  char *end() const;

  bool operator==(const Str &_rhs) const;
  bool operator!=(const Str &_rhs) const;
  bool operator>(const Str &_rhs) const;
  bool operator<(const Str &_rhs) const;
  bool operator>=(const Str &_rhs) const;
  bool operator<=(const Str &_rhs) const;

  Str operator+(const Str &_rhs) const;
  Str operator+(const char *_rhs) const;
  Str operator+(char _rhs) const;

  Str &operator=(Str &&_rhs) noexcept;
  Str &operator=(const Str &_rhs);
  Str &operator=(const char *_rhs);
  Str &operator=(char _rhs);

  Str &operator+=(const Str &_rhs);
  Str &operator+=(const char *_rhs);
  Str &operator+=(char _rhs);

  char &operator[](size_t _idx);
  const char &operator[](size_t _idx) const;

  size_t Size() const;

  int ToInt() const;
  float ToFloat() const;
  const char *c_str() const;

  static Str ToString(const float &_value);
  static Str ToString(const int &_value);
  static Str ToStringAsHex(const int &_value);

  // string Left(int _n) const;    // Substituted with substr()
  // string Right(int _n) const;   //
  // string Mid(int _ofs, int _n); //
  Str Substr(const size_t &_idx, const size_t &_len,
             const bool &_reverse = false) const;

  bool Find(const Str &_find, size_t &_idx_, const size_t &_ofs = 0) const;
  bool FindLast(const Str &_find, size_t &_idx_, const size_t &_ofs = 0) const;
  void Replace(const Str &_find, const Str &_rep);

  Str ToUpper() const;
  Str ToLower() const;

  Str TrimLeft() const;
  Str TrimRight() const;
  Str Trim() const;

  Str PadLeft(const size_t &_len, const char &_c) const;
  Str PadRight(const size_t &_len, const char &_c) const;

  Str StripExtension() const;
  Str StripDirectory() const;

  Str ExtractExtension() const;
  Str ExtractDirectory() const;

  Str RealPath() const;

  static Str Read(const Str &_filename);
  void Write(const Str &_filename, bool _append = true) const;

  friend std::ostream &operator<<(std::ostream &os, const Str &b) {
    return os << b.data;
  }
};

const Str operator+(const char *_lhs, const Str &_rhs);
} // namespace tkl::str
