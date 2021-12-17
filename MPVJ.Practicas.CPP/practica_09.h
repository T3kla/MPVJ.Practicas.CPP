#pragma once

#include "tlist.h"

using namespace tkl;

// La hice templatizada desde el principio, asi
// que he obviado la practica 19

void run_practica_09() {
  TList<const char *> list_char;

  auto char_1 = "asd";
  auto char_2 = "lol";
  auto char_3 = "lmao";

  std::cout << "> Testing list_char" << std::endl << std::endl;

  std::cout << "    pushing: " << char_1 << std::endl;
  list_char.Push(char_1);
  std::cout << "    pushing: " << char_2 << std::endl;
  list_char.Push(char_2);
  std::cout << "    pushing: " << char_3 << std::endl;
  list_char.Push(char_3);

  std::cout << "        size: " << list_char.Size() << std::endl;
  std::cout << std::endl;

  std::cout << "    poping: " << list_char.Pop() << std::endl;
  std::cout << "    poping: " << list_char.Pop() << std::endl;
  std::cout << "    poping: " << list_char.Pop() << std::endl;

  std::cout << "        size: " << list_char.Size() << std::endl;
  std::cout << std::endl;

  list_char.Reset();

  TList<int> list_int;
  auto int_1 = 1;
  auto int_2 = 2;
  auto int_3 = 3;

  std::cout << "> Testing list_int" << std::endl << std::endl;

  std::cout << "    pushing: " << int_1 << std::endl;
  list_int.Push(int_1);
  std::cout << "    pushing: " << int_2 << std::endl;
  list_int.Push(int_2);
  std::cout << "    pushing: " << int_3 << std::endl;
  list_int.Push(int_3);

  std::cout << "        size: " << list_int.Size() << std::endl;
  std::cout << std::endl;

  std::cout << "    poping: " << list_int.Pop() << std::endl;
  std::cout << "    poping: " << list_int.Pop() << std::endl;
  std::cout << "    poping: " << list_int.Pop() << std::endl;

  std::cout << "        size: " << list_int.Size() << std::endl;
  std::cout << std::endl;

  list_int.Reset();
}
