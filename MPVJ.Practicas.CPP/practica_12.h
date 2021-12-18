#pragma once

#include "str.h"
#include <iostream>

using namespace tkl::str;

void RunP12() {
  auto strA = Str("a1a23.5a.6");
  auto strB = Str("-a1.a23.5a.6");
  auto strC = Str("   aaa   ");
  auto strD = Str("desktop/mates/tumadre.png");
  auto strE = Str("lorem_04.txt");

  std::cout << strA << " ToInt() " << '"' << strA.ToInt() << '"' << std::endl;
  std::cout << strB << " ToInt() " << '"' << strB.ToInt() << '"' << std::endl;
  std::cout << strA << " ToFloat() " << '"' << strA.ToFloat() << '"'
            << std::endl;
  std::cout << strB << " ToFloat() " << '"' << strB.ToFloat() << '"'
            << std::endl;

  strA.Replace(Str("a"), Str("lmao"));

  std::cout << strA << std::endl;

  std::cout << strA.ToUpper() << std::endl;
  strA = strA.ToUpper();
  std::cout << strA.ToLower() << std::endl;

  std::cout << '"' << strC.Substr(3, 3) << '"' << std::endl;

  std::cout << '"' << strC.TrimLeft() << '"' << std::endl;
  std::cout << '"' << strC.TrimRight() << '"' << std::endl;
  std::cout << '"' << strC.Trim() << '"' << std::endl;

  std::cout << '"' << strC.Trim().PadLeft(10, '-') << '"' << std::endl;
  std::cout << '"' << strC.Trim().PadRight(10, '-') << '"' << std::endl;

  strC = "1,2,3,4,5,6,7,8,9,0";

  std::cout << '"' << strC.Trim().PadLeft(10, '-') << '"' << std::endl;
  std::cout << '"' << strC.Trim().PadRight(10, '-') << '"' << std::endl;

  std::cout << strD.StripExtension() << std::endl;
  std::cout << strD.StripDirectory() << std::endl;

  std::cout << strD.ExtractExtension() << std::endl;
  std::cout << strD.ExtractDirectory() << std::endl;

  std::cout << Str::ToString(-559038737) << std::endl;
  std::cout << Str::ToString(-559038737.0f) << std::endl;
  std::cout << Str::ToStringAsHex(-559038737) << std::endl;

  std::cout << strE.RealPath() << std::endl;

  auto temp = Str::Read("lorem_04.txt");

  std::cout << Str::Read("lorem_04.txt") << std::endl;
  strD.Write("lorem_04.txt");
  std::cout << Str::Read("lorem_04.txt") << std::endl;
  temp.Write("lorem_04.txt", false);
  std::cout << Str::Read("lorem_04.txt") << std::endl;

  std::cout << "Hola " + strD + " caracola" << std::endl;
}
