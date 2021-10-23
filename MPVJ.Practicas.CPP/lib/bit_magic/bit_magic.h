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

int get(const int &target, const span &span);
void set(int &target, const span &span, const int &value);
void clear(int &target, const span &span);

template <typename T> std::vector<unsigned char> to_bytes(const T &value);

void print_asChar(const std::vector<unsigned char> &value);
void print_asBin(const std::vector<unsigned char> &value);
void print_asHex(const std::vector<unsigned char> &value);

int get_unshifted(const int &target, const span &span);

int mask(const span &span);

} // namespace bm
