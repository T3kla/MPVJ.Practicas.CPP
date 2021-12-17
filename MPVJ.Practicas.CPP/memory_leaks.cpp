#include "memory_leaks.h"

MemLeakMonitor MemLeakMonitor::instance;
MemLeakMonitor::MemLeakMonitor() {}

static bool allowNew = false;
static bool allowDel = false;

void MemLeakMonitor::PrintUsage() {
  size_t total = 0;
  for (auto &entry : instance.entries)
    total += entry.second.alloc;
  std::cout << "Usage: " << total << std::endl;
}

int MemLeakMonitor::Set(bool isNew, const size_t &line, const char *type,
                        const char *filename) {
  instance.line = line;
  instance.type = type;
  instance.filename = filename;

  if (isNew)
    allowNew = true;
  else
    allowDel = true;

  return 1;
}

void MemLeakMonitor::OnMemAlloc(void *ptr, size_t size) {
  if (!allowNew)
    return;
  allowNew = false;

  snprintf(instance.buffer, BUFFER_LEN, "%s at ln: %llu > %s", instance.type,
           instance.line, instance.filename);

  size_t bffsize = strlen(instance.buffer);
  char *entry = new char[bffsize + 1];
  memcpy(entry, instance.buffer, bffsize + 1);
  instance.entries.insert({ptr, {size, entry}});
}

void MemLeakMonitor::OnMemFreed(void *ptr, size_t size) {
  if (!allowDel)
    return;
  allowDel = false;

  instance.entries.erase(ptr);
}
