#pragma once

#include "file_magic.h"

using namespace tkl::fmg;

void run_practica_10() {
  auto file_name = "lorem_04.txt";

  std::cout << "> Opening 'lorem_04.txt' as Read!" << std::endl;
  void *file = Open(file_name, OpenMode::Read);

  auto badlist = ReadNums(file);

  std::cout << "Retrieved by first:" << std::endl;

  std::cout << "    " << badlist.First() << std::endl;

  std::cout << "Retrieved by next 30 times because I can:" << std::endl;

  for (unsigned int i = 0; i < 30; i++)
    std::cout << "    " << badlist.Next() << std::endl;

  std::cout << "Retrieved by pop:" << std::endl;

  auto Size = badlist.Size();
  for (unsigned int i = 0; i < Size; i++)
    std::cout << "    " << badlist.Pop() << std::endl;
}
