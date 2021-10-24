#pragma once

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

namespace bm
{

struct span
{
    int shift = 0;
    int length = 0;
    span(const int &shift = 0, const int &length = 0);
};

template <typename T> std::vector<unsigned char> to_bytes(const T &value)
{
    int size = sizeof(value);
    std::vector<unsigned char> vec(size, 0);

    void *p_val = const_cast<T *>(&value);
    unsigned char *p_char = static_cast<unsigned char *>(p_val);

    for (size_t i = 0; i < size; i++)
        vec[i] = *p_char++;

    return vec;
}

int get(const int &target, const span &span);
void set(int &target, const span &span, const int &value);
void clear(int &target, const span &span);

void print_asChar(const std::vector<unsigned char> &value);
void print_asBin(const std::vector<unsigned char> &value);
void print_asHex(const std::vector<unsigned char> &value);

int get_unshifted(const int &target, const span &span);

int mask(const span &span);

} // namespace bm
