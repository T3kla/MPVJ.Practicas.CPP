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
    ~string();

    string operator+(const string &_value);

    friend std::ostream &operator<<(std::ostream &_os, const string &_value);
};

} // namespace bs
