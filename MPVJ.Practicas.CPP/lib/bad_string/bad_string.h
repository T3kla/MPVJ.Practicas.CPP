#pragma once

namespace bs
{

struct bad_string
{
  private:
    const unsigned char chunk_size = 64;
    char *data = nullptr;
    size_t size = 0;

    void resize(size_t value)
    {
        auto old = data;
        data = new char[value];
        std::memcpy(old, data, size);
        delete (data);
    }

  public:
    bad_string()
    {
        data = new char[64];
    }

    bad_string(const char *value)
    {
        auto size = strlen(value);
        auto bytes = (unsigned int)(static_cast<float>(size) / chunk_size + 0.5f);

        data = new char[bytes];
        std::memcpy(data, value, size);
    }

    const char *operator+(bad_string &&)
    {
    }
};

} // namespace bs
