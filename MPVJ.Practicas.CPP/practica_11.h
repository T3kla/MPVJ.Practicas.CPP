#pragma once

#include "file_magic.h"
#include <iostream>
#include <stdexcept>

using namespace fmg;

void run_practica_11() {
  auto file_name = "lorem_04.txt";

  std::cout << "> Opening 'lorem_04.txt' as Read!" << std::endl;
  void *file = Open(file_name, OpenMode::Read);

  auto badlist = ReadNums(file);
  auto badlist2(badlist);

  std::cout << "> Printing" << std::endl;

  auto Size = badlist2.Size();
  for (unsigned int i = 0; i < Size; i++)
    std::cout << "    " << badlist2.Next() << std::endl;

  std::cout << "> Inverting 'invert_noCopy'" << std::endl;

  InvertNoCopy(badlist2);

  std::cout << "> Printing" << std::endl;

  Size = badlist2.Size();
  for (unsigned int i = 0; i < Size; i++)
    std::cout << "    " << badlist2[i]->value << std::endl;

  std::cout << "> Inverting 'invert_copy'" << std::endl;

  auto badlist3 = InvertCopy(badlist2);

  std::cout << "> Printing" << std::endl;

  Size = badlist3.Size();
  for (unsigned int i = 0; i < Size; i++)
    std::cout << "    " << badlist3.Next() << std::endl;
}
