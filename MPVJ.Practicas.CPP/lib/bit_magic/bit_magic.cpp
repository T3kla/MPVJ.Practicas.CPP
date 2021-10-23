#include "bit_magic.h"
#include <vector>

namespace bm
{

span::span(const int &shift, const int &length) : shift(shift), length(length)
{
}

int get(const int &target, const span &span)
{
    return (get_unshifted(target, span)) >> span.shift;
}

void set(int &target, const span &span, const int &value)
{
    clear(target, span);
    target |= (value << span.shift) & mask(span);
}

void clear(int &target, const span &span)
{
    target &= ~(get_unshifted(target, span));
}

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

void print_asChar(const std::vector<unsigned char> &value)
{
    std::cout << "Printing " << value.size() << " bytes as: char" << std::endl;

    for (size_t i = 0; i < value.size(); i++)
    {
        std::cout << "    " << i << ": " << value[i] << std::endl;
    }
}

void print_asBin(const std::vector<unsigned char> &value)
{
    std::cout << "Printing " << value.size() << " bytes as: binary" << std::endl;

    for (size_t i = 0; i < value.size(); i++)
    {
        std::bitset<8> b(value[i]);
        std::cout << "    " << i << ": " << b << std::endl;
    }
}

void print_asHex(const std::vector<unsigned char> &value)
{
    std::cout << "Printing " << value.size() << " bytes as: hexadecimal" << std::endl;

    for (size_t i = 0; i < value.size(); i++)
    {
        std::cout << "    " << std::to_string(i) << ": " << std::hex << static_cast<int>(value[i]) << std::endl;
    }
}

int get_unshifted(const int &target, const span &span)
{
    return target & mask(span);
}

int mask(const span &span)
{
    int mask = 0;

    for (int i = 0; i < span.length; i++)
        mask += (int)pow(2, i);

    return mask << span.shift;
}

} // namespace bm
