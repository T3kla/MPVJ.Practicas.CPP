#pragma once

#include "memory_leaks.h"
#include <iostream>

#define MEMORY_LEAKS_MONITOR

void run_practica_18() {
  PrintUsage();
  char *a = NEW char();
  char *b = NEW char[10];
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  PrintUsage();
}
