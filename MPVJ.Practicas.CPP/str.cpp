#include "str.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace tkl::str {

// Resize allocated memory base on size taking care of '\\0' termination
void Str::Resize(const size_t &_size) {
  auto new_cap = CalcCapacity(_size);
  auto old_size = size;
  size = _size;

  if (capacity == new_cap)
    return;

  auto old = data;
  data = new char[new_cap];
  ::memcpy(data, old, old_size);
  delete (old);
  capacity = new_cap;
}

void Str::ExtractNum(const char *_src, char *_dst_, const size_t &_len,
                     const bool &_allow_dot) const {
  char *it_buff = _dst_;
  auto *it = begin();
  auto *end = this->end();
  auto saw_point = !_allow_dot;
  auto saw_minus = false;

  auto cont = [&]() { return (it != end) && (it_buff != _dst_ + _len - 1); };

  *_dst_ = '+';
  it_buff++;

  while (cont()) {
    if (!saw_minus && *it == '-' && it_buff == _dst_ + 1) {
      saw_minus = true;
      *_dst_ = '-';
    }

    if (!saw_point && *it == '.') {
      saw_point = true;
      *it_buff++ = *it;
    }

    if (*it >= '0' && *it <= '9')
      *it_buff++ = *it;

    it++;
  }

  *it_buff = '\0';
}

inline size_t Str::CalcCapacity(const size_t &_value) {
  return (_value + 1) + ALLOC_INCREMENT - ((_value + 1) % ALLOC_INCREMENT);
}

inline void Str::Zero() {
  for (auto i = 0ull; i < Size(); i++)
    data[i] = ' ';
  Guard();
}

inline void Str::Guard() { data[size] = '\0'; }

#pragma region Constructors

Str::Str() {
  capacity = ALLOC_INCREMENT;
  size = 0;
  data = new char[ALLOC_INCREMENT];
  Zero();
  Guard();
}

Str::Str(const size_t &_value) {
  capacity = CalcCapacity(_value);
  size = _value;
  data = new char[capacity];
  Zero();
  Guard();
}

Str::~Str() {
  if (data != nullptr)
    delete (data);
}

Str::Str(const char *_value) {
  size = strlen(_value);
  capacity = CalcCapacity(size);
  data = new char[capacity];
  std::memcpy(data, _value, size);
  Guard();
}

Str::Str(char *_value) {
  size = strlen(_value);
  capacity = CalcCapacity(size);
  data = new char[capacity];
  std::memcpy(data, _value, size);
  Guard();
}

Str::Str(const Str &_value) {
  size = _value.size;
  capacity = _value.capacity;
  data = new char[_value.capacity];
  std::memcpy(data, _value.data, size);
  Guard();
}

Str::Str(Str &_value) {
  size = _value.size;
  capacity = _value.capacity;
  data = new char[_value.capacity];
  std::memcpy(data, _value.data, size);
  Guard();
}

Str::Str(const Str &&_value) noexcept {
  size = _value.size;
  capacity = _value.capacity;
  data = new char[capacity];
  std::memcpy(data, _value.data, size);
  Guard();
}

Str::Str(Str &&_value) noexcept {
  size = _value.size;
  capacity = _value.capacity;
  data = _value.data;
  _value.data = nullptr;
}

#pragma endregion

#pragma region Operators

bool Str::operator==(const Str &_rhs) const { return *data == *_rhs.data; }

bool Str::operator!=(const Str &_rhs) const { return *data != *_rhs.data; }

bool Str::operator>(const Str &_rhs) const { return Size() > _rhs.Size(); }

bool Str::operator<(const Str &_rhs) const { return Size() < _rhs.Size(); }

bool Str::operator>=(const Str &_rhs) const { return Size() >= _rhs.Size(); }

bool Str::operator<=(const Str &_rhs) const { return Size() <= _rhs.Size(); }

Str Str::operator+(const Str &_rhs) const {
  auto result = Str(size + _rhs.size);
  std::memcpy(result.data, data, size);
  std::memcpy(result.data + size, _rhs.data, _rhs.size + 1);
  return result;
}

Str Str::operator+(const char *_rhs) const {
  auto rhslen = strlen(_rhs);
  auto result = Str(size + rhslen);
  std::memcpy(result.data, data, size);
  std::memcpy(result.data + size, _rhs, rhslen);
  result.Guard();
  return result;
}

Str Str::operator+(char _rhs) const {
  auto result = Str(size + 1);
  std::memcpy(result.data, data, size);
  result.data[size - 1] = _rhs;
  result.Guard();
  return result;
}

Str &Str::operator=(Str &&_rhs) noexcept {
  size = _rhs.size;
  capacity = _rhs.capacity;
  data = _rhs.data;
  _rhs.data = nullptr;
  return *this;
}

Str &Str::operator=(const Str &_rhs) {
  Resize(_rhs.size);
  std::memcpy(data, _rhs.data, _rhs.size + 1);
  return *this;
}

Str &Str::operator=(const char *_rhs) {
  auto rhslen = strlen(_rhs);
  Resize(rhslen);
  std::memcpy(data, _rhs, rhslen);
  Guard();
  return *this;
}

Str &Str::operator=(char _rhs) {
  Resize(1);
  data[0] = _rhs;
  Guard();
  return *this;
}

Str &Str::operator+=(const Str &_rhs) {
  auto old_size = size;
  Resize(size + _rhs.size);
  std::memcpy(data + old_size, _rhs.data, _rhs.size + 1);
  return *this;
}

Str &Str::operator+=(const char *_rhs) {
  auto old_size = size;
  auto rhslen = strlen(_rhs);
  Resize(size + rhslen);
  std::memcpy(data + old_size, _rhs, rhslen);
  Guard();
  return *this;
}

Str &Str::operator+=(char _rhs) {
  Resize(size + 1);
  data[size - 1] = _rhs;
  Guard();
  return *this;
}

char &Str::operator[](size_t _idx) {
  if (_idx < 0 || _idx >= size)
    throw "Out of range index";
  return data[_idx];
}

const char &Str::operator[](size_t _idx) const {
  if (_idx < 0 || _idx >= size)
    throw "Out of range index";
  return data[_idx];
}

#pragma endregion

char *Str::begin() const { return data; }

char *Str::end() const { return data + size; }

size_t Str::Size() const { return size; }

int Str::ToInt() const {
  // Se que hay maneras mas faciles, pero tenia ganas de hacerlo asi
  char buffer[64];
  ExtractNum(data, buffer, 64, false);
  auto size = strlen(buffer);
  auto result = 0;

  for (size_t i = size - 1; i < size && i > 0; i--) {
    auto num = buffer[i] - '0';
    auto pos = pow(10, size - i - 1);
    result += num * (int)pos;
  }

  if (*buffer == '-')
    result *= -1;

  return result;
}

float Str::ToFloat() const {
  char buffer[64];
  ExtractNum(data, buffer, 64, true);
  return (float)::atof(buffer);
}

const char *Str::c_str() const { return data; }

Str Str::ToString(const float &_value) {
  char buffer[64];
  snprintf(buffer, 64, "%f", _value);
  return Str(buffer);
}

Str Str::ToString(const int &_value) {
  char buffer[64];
  _itoa_s(_value, buffer, 10);
  return Str(buffer);
}

Str Str::ToStringAsHex(const int &_value) {
  char buffer[64];
  _itoa_s(_value, buffer, 16);
  return Str(buffer);
}

Str Str::Substr(const size_t &_idx, const size_t &_len,
                const bool &_reverse) const {
  if (_idx < 0 || _idx + _len > size)
    throw "Out of range index";
  if (_reverse && size - _idx - _len < 0)
    throw "Out of range index";
  auto result = Str(_len);
  std::memcpy(result.data, data + (_reverse ? size - _idx - _len : _idx), _len);
  result.Guard();
  return result;
}

// bool find(const string &_find, size_t &_idx_, const size_t &_ofs) const;
// bool find_last(const string &_find, size_t &_idx_, const size_t &_ofs) const;

bool Str::Find(const Str &_find, size_t &_idx_, const size_t &_ofs) const {
  const auto find_len = _find.Size();

  if (_ofs < 0 || _ofs + find_len >= size)
    throw "Out of range index";

  const auto &find_l = _find.begin();
  const auto &find_r = _find.end() - 1;

  auto it_l = begin() + _ofs;
  auto it_r = begin() + _ofs + find_len - 1;

  while (it_r != end()) {
    if (*it_l == *find_l && *it_r == *find_r) {
      if (find_len <= 2) {
        _idx_ = it_l - data;
        return true;
      }
      for (size_t i = 1; i < find_len - 1; i++) {
        auto in_find = find_l + i;
        auto in_data = it_l + i;
        if (*in_find != *in_data)
          break;
        if (i == find_len - 2) {
          _idx_ = it_l - data;
          return true;
        }
      }
    }
    it_l++;
    it_r++;
  }

  return false;
}

bool Str::FindLast(const Str &_find, size_t &_idx_, const size_t &_ofs) const {
  const auto find_len = _find.Size();

  if (_ofs < 0 || _ofs + find_len >= size)
    throw "Out of range index";

  const auto &find_l = _find.begin();
  const auto &find_r = _find.end() - 1;

  auto it_l = end() - find_len;
  auto it_r = end() - 1;

  while (it_l != begin() + _ofs) {
    if (*it_l == *find_l && *it_r == *find_r) {
      if (find_len <= 2) {
        _idx_ = it_l - data;
        return true;
      }
      for (size_t i = 1; i < find_len - 1; i++) {
        auto in_find = find_l + i;
        auto in_data = it_l + i;
        if (*in_find != *in_data)
          break;
        if (i == find_len - 2) {
          _idx_ = it_l - data;
          return true;
        }
      }
    }
    it_l--;
    it_r--;
  }

  return false;
}

void Str::Replace(const Str &_find, const Str &_rep) {
  size_t idx = 0ull;
  size_t ofs = 0ull;
  size_t len_find = _find.Size();
  size_t len_rep = _rep.Size();
  size_t len_dif = len_rep - len_find;

  while (Find(_find, idx, ofs)) {
    auto old_size = size;
    Resize(size + len_dif);
    ::memcpy(data + idx + len_rep, data + idx + len_find,
             (old_size + 1) - (idx + len_find));
    ::memcpy(data + idx, _rep.data, len_rep);
    ofs = idx + len_rep;
  }

  Guard();
}

Str Str::ToUpper() const {
  auto result = Str(*this);
  auto *beg = result.begin();
  auto *end = result.end();

  for (beg; beg != end; beg++)
    if (*beg >= 'a' && *beg <= 'z')
      (*beg) += 'A' - 'a';

  return result;
}

Str Str::ToLower() const {
  auto result = Str(*this);
  auto *beg = result.begin();
  auto *end = result.end();

  for (beg; beg != end; beg++)
    if (*beg >= 'A' && *beg <= 'Z')
      (*beg) += 'a' - 'A';

  return result;
}

Str Str::TrimLeft() const {
  auto whites = 0;
  auto *beg = this->begin();
  auto *end = this->end();

  while (iswspace(*beg) != 0 && beg++ < end)
    whites++;

  return Substr(whites, size - whites);
}

Str Str::TrimRight() const {
  auto whites = 0;
  auto *beg = this->begin();
  auto *end = this->end() - 1;

  while (iswspace(*end) != 0 && end-- >= beg)
    whites++;

  return Substr(0, size - whites);
}

Str Str::Trim() const { return TrimLeft().TrimRight(); }

Str Str::PadLeft(const size_t &_len, const char &_c) const {
  if (Size() >= _len)
    return Substr(0, _len, true);

  auto result = Str(_len);
  auto diff = _len - size;
  ::memcpy(result.data + diff, data, size);

  for (size_t i = 0; i < diff; i++)
    result.data[i] = _c;

  result.Guard();
  return result;
}

Str Str::PadRight(const size_t &_len, const char &_c) const {
  if (Size() >= _len)
    return Substr(0, _len);

  auto result = Str(_len);
  auto diff = _len - size;
  ::memcpy(result.data, data, size);

  for (size_t i = 0; i < diff; i++)
    result.data[size + i] = _c;

  result.Guard();
  return result;
}

Str Str::StripExtension() const {
  size_t idx = 0ull;
  if (FindLast(".", idx))
    return Substr(0, idx);
  return *this;
}

Str Str::StripDirectory() const {
  size_t idx = 0ull;
  if (FindLast("/", idx))
    return Substr(0, Size() - idx - 1, true);
  return *this;
}

Str Str::ExtractExtension() const {
  size_t idx = 0ull;
  if (FindLast(".", idx))
    return Substr(0, Size() - idx - 1, true);
  return *this;
}

Str Str::ExtractDirectory() const {
  size_t idx = 0ull;
  if (FindLast("/", idx))
    return Substr(0, idx);
  return *this;
}

Str Str::RealPath() const {
  // No sé si esto es lo que pides pero vaya, que filesystem
  // tiene como mil maneras de hacer esto según parece.
  auto cur = std::filesystem::current_path().u8string();
  cur.append("\\");
  cur.append(c_str());
  return Str(cur.c_str());
}

Str Str::Read(const Str &_filename) {
  std::fstream stream;
  auto fn = std::string(_filename.c_str());
  stream.open(fn, std::ios::in);

  stream.seekg(0, std::ios::end);
  size_t file_len = stream.tellg();
  stream.seekg(0, std::ios::beg);

  auto result = Str(file_len);
  stream.read(result.data, file_len);
  stream.close();
  return result;
}

void Str::Write(const Str &_filename, bool _append) const {
  std::fstream stream;
  auto fn = std::string(_filename.c_str());
  stream.open(fn, std::ios::out | (_append ? std::ios::app : std::ios::trunc));
  stream.write(c_str(), Size());
  stream.close();
}

const Str operator+(const char *_lhs, const Str &_rhs) {
  return Str(_lhs) + _rhs;
}

} // namespace tkl::str
