#pragma once

#include <iostream>

namespace p15
{

class stream
{
  protected:
    stream()
    {
        std::cout << "stram constructor" << std::endl;
    }
    ~stream()
    {
        std::cout << "stram destructor" << std::endl;
    }
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void read(unsigned char *buffer) = 0;
    virtual void write(const unsigned char &buffer) = 0;
};

class stream_file : stream
{
  public:
    virtual void open() override
    {
        std::cout << "stream_file open" << std::endl;
    }
    virtual void close() override
    {
        std::cout << "stream_file close" << std::endl;
    }
    virtual void read(unsigned char *buffer) override
    {
        std::cout << "stream_file read" << std::endl;
    }
    virtual void write(const unsigned char &buffer) override
    {
        std::cout << "stream_file open" << std::endl;
    }
};

class stream_com : stream
{
  public:
    virtual void open() override
    {
        std::cout << "stream_com open" << std::endl;
    }
    virtual void close() override
    {
        std::cout << "stream_com close" << std::endl;
    }
    virtual void read(unsigned char *buffer) override
    {
        std::cout << "stream_com read" << std::endl;
    }
    virtual void write(const unsigned char &buffer) override
    {
        std::cout << "stream_com open" << std::endl;
    }
};

class stream_tcp : private stream
{
  public:
    virtual void open() override
    {
        std::cout << "stream_tcp open" << std::endl;
    }
    virtual void close() override
    {
        std::cout << "stream_tcp close" << std::endl;
    }
    virtual void read(unsigned char *buffer) override
    {
        std::cout << "stream_tcp read" << std::endl;
    }
    virtual void write(const unsigned char &buffer) override
    {
        std::cout << "stream_tcp open" << std::endl;
    }
};

} // namespace p15

void run_practica_15()
{
    unsigned char buffer[64];

    // p15::stream stream; <- peta porque contiene virtuales, por tanto es abstract

    p15::stream_tcp stream_tcp;

    stream_tcp.open();
    stream_tcp.close();
    stream_tcp.read(buffer);
    stream_tcp.write(*buffer);
}
