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

  static void Dump();  // Print leaks
  static void Flush(); // Print leaks, clear entries
};

#if defined MEMORY_LEAKS_MONITOR && defined _DEBUG

#define NEW MemLeakMonitor::Set(true, __LINE__, __FILE__) && 0 ? NULL : new
#define DEL                                                                    \
  MemLeakMonitor::Set(false, __LINE__, __FILE__);                              \
  delete

// #define NEW_ARR MLM::Set(true, __LINE__, __FILE__) && 0 ? NULL : new;
// #define DEL_ARR MLM::Set(false, __LINE__, __FILE__); delete

#else

#define NEW new
#define NEW_ARR new
#define DEL delete
#define DEL_ARR delete

#endif
