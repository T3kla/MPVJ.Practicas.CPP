#pragma once

#define MEMORY_LEAKS_MONITOR ;

#include "memory_leaks.h"
#include <iostream>

void run_practica_18() {
  MemLeakMonitor::PrintUsage();

  char *a = NEW char;                      // 1 byte
  char *b = NEW_ARR char[10]{"123456789"}; // 10 byte

  MemLeakMonitor::PrintUsage();

  DEL a;
  DEL_ARR b;

  MemLeakMonitor::PrintUsage();

  size_t *c = NEW size_t(420);    // 8 bytes
  size_t *d = NEW_ARR size_t[10]; // 80 bytes

  MemLeakMonitor::PrintUsage();

  // DEL c;
  // DEL_ARR d;

  // Esto es increible
  //	Con este sistema no hace falta NEW_ARR
  //	pero lo pongo porque lo pides
  MemLeakMonitor::Flush();
}
