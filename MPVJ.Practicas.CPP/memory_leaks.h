#pragma once

#include <iostream>
#include <memory>

struct Allocation {
  size_t alloc = 0;
  size_t freed = 0;
  size_t Usage() { return alloc - freed; }
};

static Allocation MemTracker;

void *MemNew(size_t size) {
  MemTracker.alloc += size;
  return malloc(size);
}

void MemDel(void *memory, size_t size) {
  MemTracker.freed += size;
  free(memory);
}

static void PrintUsage() {
  std::cout << "Usage: " << MemTracker.Usage() << std::endl;
}

#ifdef MEMORY_LEAKS_MONITOR
#define NEW MemNew
#define DELETE MemDel
#else
#define NEW new
#define DELETE delete
#endif
