#pragma once

#include "lib/file_magic/file_magic.h"

void run_practica_05() {
  auto file_name = "lorem_01.txt";
  char buffer[512];

  std::cout << "> Opening 'lorem_01.txt' as Read!" << std::endl;
  void *file = fm::Open(file_name, fm::OpenMode::Read);
  void **f_wrap = &file;

  unsigned int count = 0;

  std::cout << std::endl;

  std::cout << "Reading 50 chars: " << std::endl;
  count = fm::Read(file, buffer, 50);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Closing file!" << std::endl;
  fm::Close(f_wrap);

  std::cout << std::endl;

  std::cout << "Reading 100 chars: " << std::endl;
  count = fm::Read(file, buffer, 100);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Opening 'lorem_01.txt' as Read!" << std::endl;
  file = fm::Open(file_name, fm::OpenMode::Read);

  std::cout << std::endl;

  std::cout << "Reading 256 chars: " << std::endl;
  count = fm::Read(file, buffer, 256);
  std::cout << "    Actual read: " << count << std::endl
            << "    " << buffer << std::endl;

  std::cout << std::endl;

  std::cout << "> Closing file!" << std::endl;
  fm::Close(f_wrap);

  std::cout << std::endl;

  std::cout << "> Opening 'lorem_01.txt' as Write!" << std::endl;
  file = fm::Open(file_name, fm::OpenMode::Write);

  std::cout << std::endl;

  std::cout << "Writting 256 chars: " << std::endl;
  fm::Write(file, buffer);
  std::cout << "    " << buffer << std::endl;

  std::cout << std::endl;
}
