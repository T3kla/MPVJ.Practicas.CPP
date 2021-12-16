#pragma once

#include "lib/bad_string/string.h"
#include <iostream>

void run_practica_12() {
  auto strA = tkl::Str("a1a23.5a.6");
  auto strB = tkl::Str("-a1.a23.5a.6");
  auto strC = tkl::Str("   aaa   ");
  auto strD = tkl::Str("desktop/mates/tumadre.png");
  auto strE = tkl::Str("lorem_04.txt");

  std::cout << strA << " to_int() " << '"' << strA.to_int() << '"' << std::endl;
  std::cout << strB << " to_int() " << '"' << strB.to_int() << '"' << std::endl;
  std::cout << strA << " to_float() " << '"' << strA.to_float() << '"'
            << std::endl;
  std::cout << strB << " to_float() " << '"' << strB.to_float() << '"'
            << std::endl;

  strA.replace(tkl::Str("a"), tkl::Str("lmao"));

  std::cout << strA << std::endl;

  std::cout << strA.to_upper() << std::endl;
  strA = strA.to_upper();
  std::cout << strA.to_lower() << std::endl;

  std::cout << '"' << strC.substr(3, 3) << '"' << std::endl;

  std::cout << '"' << strC.trim_left() << '"' << std::endl;
  std::cout << '"' << strC.trim_right() << '"' << std::endl;
  std::cout << '"' << strC.trim() << '"' << std::endl;

  std::cout << '"' << strC.trim().pad_left(10, '-') << '"' << std::endl;
  std::cout << '"' << strC.trim().pad_right(10, '-') << '"' << std::endl;

  strC = "1,2,3,4,5,6,7,8,9,0";

  std::cout << '"' << strC.trim().pad_left(10, '-') << '"' << std::endl;
  std::cout << '"' << strC.trim().pad_right(10, '-') << '"' << std::endl;

  std::cout << strD.strip_ext() << std::endl;
  std::cout << strD.strip_dir() << std::endl;

  std::cout << strD.extract_ext() << std::endl;
  std::cout << strD.extract_dir() << std::endl;

  std::cout << tkl::Str::to_string(-559038737) << std::endl;
  std::cout << tkl::Str::to_string(-559038737.0f) << std::endl;
  std::cout << tkl::Str::to_string_as_hex(-559038737) << std::endl;

  std::cout << strE.real_path() << std::endl;

  auto temp = tkl::Str::Read("lorem_04.txt");

  std::cout << tkl::Str::Read("lorem_04.txt") << std::endl;
  strD.Write("lorem_04.txt");
  std::cout << tkl::Str::Read("lorem_04.txt") << std::endl;
  temp.Write("lorem_04.txt", false);
  std::cout << tkl::Str::Read("lorem_04.txt") << std::endl;

  std::cout << "Hola " + strD + " caracola" << std::endl;
}
