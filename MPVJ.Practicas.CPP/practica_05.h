#pragma once

#include "file_magic.h"

using namespace tkl::fmg;

void run_practica_05() {
  auto file_name = "lorem_01.txt";
  char buffer[512];

  std::cout << "> Opening 'lorem_01.txt' as Read!" << std::endl;
  void *file = Open(file_name, OpenMode::Read);
  void **f_wrap = &file;

  unsigned int count = 0;

  std::cout << std::endl;

  std::cout << "Reading 50 chars: " << std::endl;
  count = Read(file, buffer, 50);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Closing file!" << std::endl;
  Close(f_wrap);

  std::cout << std::endl;

  std::cout << "Reading 100 chars: " << std::endl;
  count = Read(file, buffer, 100);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Opening 'lorem_01.txt' as Read!" << std::endl;
  file = Open(file_name, OpenMode::Read);

  std::cout << std::endl;

  std::cout << "Reading 256 chars: " << std::endl;
  count = Read(file, buffer, 256);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Closing file!" << std::endl;
  Close(f_wrap);

  std::cout << std::endl;

  std::cout << "> Opening 'lorem_01.txt' as Write!" << std::endl;
  file = Open(file_name, OpenMode::Write);

  std::cout << std::endl;

  std::cout << "Writting 256 chars: " << std::endl;
  Write(file, buffer);
  std::cout << "    " << buffer << std::endl;

  std::cout << std::endl;
}
