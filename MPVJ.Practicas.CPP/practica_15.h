#pragma once

#include <iostream>

namespace p15 {

class stream {
protected:
  stream() { std::cout << "stream constructor" << std::endl; }
  ~stream() { std::cout << "stream destructor" << std::endl; }
  virtual void Open() = 0;
  virtual void Close() = 0;
  virtual void Read(unsigned char *buffer) = 0;
  virtual void Write(const unsigned char &buffer) = 0;
};

class stream_file : stream {
public:
  virtual void Open() override { std::cout << "stream_file open" << std::endl; }
  virtual void Close() override {
    std::cout << "stream_file close" << std::endl;
  }
  virtual void Read(unsigned char *buffer) override {
    std::cout << "stream_file read" << std::endl;
  }
  virtual void Write(const unsigned char &buffer) override {
    std::cout << "stream_file open" << std::endl;
  }
};

class stream_com : stream {
public:
  virtual void Open() override { std::cout << "stream_com open" << std::endl; }
  virtual void Close() override {
    std::cout << "stream_com close" << std::endl;
  }
  virtual void Read(unsigned char *buffer) override {
    std::cout << "stream_com read" << std::endl;
  }
  virtual void Write(const unsigned char &buffer) override {
    std::cout << "stream_com open" << std::endl;
  }
};

class stream_tcp : private stream {
public:
  virtual void Open() override { std::cout << "stream_tcp open" << std::endl; }
  virtual void Close() override {
    std::cout << "stream_tcp close" << std::endl;
  }
  virtual void Read(unsigned char *buffer) override {
    std::cout << "stream_tcp read" << std::endl;
  }
  virtual void Write(const unsigned char &buffer) override {
    std::cout << "stream_tcp open" << std::endl;
  }
};

} // namespace p15

void run_practica_15() {
  unsigned char buffer[64];

  p15::stream_tcp stream_tcp;

  stream_tcp.Open();
  stream_tcp.Close();
  stream_tcp.Read(buffer);
  stream_tcp.Write(*buffer);
}
