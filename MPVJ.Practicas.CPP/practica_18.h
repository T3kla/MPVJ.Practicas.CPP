#pragma once

#include "memory_leaks.h"
#include <iostream>

SOCORRO;

void run_practica_18() {
  MemLeakMonitor::PrintUsage();

  char *a = NEW char;
  char *b = NEW_ARR char[10]{"123456789"};

  MemLeakMonitor::PrintUsage();

  DEL a;
  DEL_ARR b;

  MemLeakMonitor::PrintUsage();
}
