#pragma once

#include "lib/bit_magic/bit_magic.h"
#include "lib/str_inverter/string_inverter.h"
#include <iostream>
#include <string>
#include <vector>

namespace p02
{

void biggest_from_table()
{
#pragma warning(disable : 4838)
    int table[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2};

#pragma warning(disable : 4267)
    int table_size = std::size(table);
    int *p_current = &table[0];
    int *p_biggest = &table[0];

    for (size_t i = 0; i < table_size; i++)
    {
        if (*p_current > *p_biggest)
            p_biggest = p_current;

        p_current++;
    }

    std::cout << "Biggest int from table is:  " << *p_biggest << std::endl;
}

void biggest_byte_from_table()
{
#pragma warning(disable : 4838)
    int table[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2};

    auto vec = bm::to_bytes(table);
    unsigned char *p_current = &vec[0];
    unsigned char *p_biggest = &vec[0];

    for (size_t i = 0; i < vec.size(); i++)
    {
        if (*p_current > *p_biggest)
            p_biggest = p_current;

        p_current++;
    }

    std::cout << "Biggest byte from table is: " << static_cast<int>(*p_biggest) << std::endl;
}

} // namespace p02

void run_practica_02()
{

    // Dado un entero, poner por separado los bytes usando casting y punteros

    auto v = bm::to_bytes(-559038737);

    bm::print_asChar(v);
    std::cout << std::endl;
    bm::print_asBin(v);
    std::cout << std::endl;
    bm::print_asHex(v);
    std::cout << std::endl;

    // Dada la tabla de enteros obtener el mayor usando casting y punteros

    p02::biggest_from_table();

    // Dada la tabla de enteros obtener el mayor byte usando casting y punteros

    p02::biggest_byte_from_table();

    // Dada una string, darle la vuelta

    std::cout << std::endl << "flip_string_lazy_noCopy:" << std::endl;

    std::string even = "long even string";
    std::string odd = "long odd string";

    si::flip_string_lazy_noCopy(even);
    std::cout << "    even: " << even << std::endl;
    si::flip_string_lazy_noCopy(odd);
    std::cout << "    odd:  " << odd << std::endl;

    std::cout << std::endl << "flip_string_noLazy_copy:" << std::endl;

    even = "long even string";
    odd = "long odd string";

    std::cout << "    even: " << si::flip_string_noLazy_copy(even) << std::endl;
    std::cout << "    odd:  " << si::flip_string_noLazy_copy(odd) << std::endl;

    std::cout << std::endl << "flip_string_noLazy_noCopy:" << std::endl;

    even = "long even string";
    odd = "long odd string";

    si::flip_string_noLazy_noCopy(even);
    std::cout << "    even: " << even << std::endl;
    si::flip_string_noLazy_noCopy(odd);
    std::cout << "    odd:  " << odd << std::endl;
}
