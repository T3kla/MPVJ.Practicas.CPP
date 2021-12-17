#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

class MemLeakMonitor {
private:                                           // SINGLETONE STUFF
  MemLeakMonitor();                                //
  static MemLeakMonitor instance;                  //
public:                                            //
  MemLeakMonitor(const MemLeakMonitor &) = delete; //

private:
  struct Entry {
    size_t alloc;
    char *msg;
  };

  size_t line = 0;
  const char *filename = nullptr;

  static const size_t BUFFER_LEN = 1024;
  char buffer[BUFFER_LEN] = "";

  std::unordered_map<void *, Entry> entries;

public:
  static void PrintUsage();

  static int Set(bool isNew, const size_t &line, const char *filename);

  static void OnMemAlloc(void *ptr, size_t size);
  static void OnMemFreed(void *ptr, size_t size);

  static void Dump();
  static void Flush();
};

#ifdef MEMORY_LEAKS_MONITOR

#define NEW MemLeakMonitor::Set(true, __LINE__, __FILE__) && 0 ? NULL : new
#define NEW_ARR MemLeakMonitor::Set(true, __LINE__, __FILE__) && 0 ? NULL : new
#define DEL                                                                    \
  MemLeakMonitor::Set(false, __LINE__, __FILE__);                              \
  delete
#define DEL_ARR                                                                \
  MemLeakMonitor::Set(false, __LINE__, __FILE__);                              \
  delete

void *operator new(size_t size) {
  void *ptr = malloc(size);
  MemLeakMonitor::OnMemAlloc(ptr, size);
  return ptr;
}
void operator delete(void *ptr, size_t size) {
  MemLeakMonitor::OnMemFreed(ptr, size);
  free(ptr);
}

#endif // MEMORY_LEAKS_MONITOR
