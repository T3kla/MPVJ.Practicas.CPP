#include "txt_file.h"

namespace tkl::tf {

TextFile::TextFile(const char *_file_name) {
  this->filename = _file_name;
  StreamToBuffer();
}

void TextFile::StreamToBuffer() {
  if (!StreamOpen(OpenMode::Read))
    return;

  buffer.clear();
  buffer << fstream.rdbuf();

  StreamClose();
}

bool TextFile::StreamOpen(const OpenMode &_mode) {
  if (_mode == OpenMode::Read)
    fstream.open(filename, std::ios::in);

  if (_mode == OpenMode::Write)
    fstream.open(filename, std::ios::out | std::ios::app);

  if (_mode == OpenMode::Clear)
    fstream.open(filename, std::ios::out | std::ios::trunc);

  if (!fstream.is_open()) {
    std::cout << "    Unable to open file '" << filename << "'" << std::endl;
    return false;
  }

  return true;
}

void TextFile::StreamClose() {
  if (fstream.is_open())
    fstream.close();
}

void TextFile::BufferToStream() {
  if (!StreamOpen(OpenMode::Clear))
    return;

  StreamClose();

  if (!StreamOpen(OpenMode::Write))
    return;

  fstream << buffer.rdbuf();

  StreamClose();
}

unsigned long long TextFile::BufferLength() {
  buffer.seekg(0, std::ios::end);
  unsigned long long length = buffer.tellg();
  buffer.seekg(0, std::ios::beg);
  return length;
}

unsigned long long TextFile::StreamLength() {
  if (!fstream.is_open())
    return 0;
  fstream.seekg(0, std::ios::end);
  unsigned long long length = fstream.tellg();
  fstream.seekg(0, std::ios::beg);
  return length;
}

std::string TextFile::ToString() { return buffer.str(); }

unsigned long long TextFile::Read(const size_t &_index, const size_t &_length,
                                  char *buffer_) {
  if (_length == 0)
    return 0;

  if (_index + _length > BufferLength()) {
    std::cout << "    Unable to read file '" << filename
              << "' given that index and length" << std::endl;
    StreamClose();
    return 0;
  }

  buffer.seekg(0, (std::ios_base::seekdir)_index);
  buffer.get(buffer_, _length + 1, '\0');
  buffer.seekg(0, std::ios::beg);

  return strlen(buffer_);
}

unsigned long long TextFile::Write(const size_t &_index, const char *_buffer) {
  auto buff_length = BufferLength();
  auto in_buff_length = strlen(_buffer);

  if (_index > buff_length) {
    std::cout << "    Unable to write file '" << filename
              << "' given that index" << std::endl;
    return 0;
  }

  std::string arr[2];

  arr[0] = buffer.str().substr(0, _index);
  arr[1] = buffer.str().substr(_index, buff_length);

  buffer.str(std::string());

  buffer << arr[0];
  buffer.write(_buffer, in_buff_length);
  buffer << arr[1];

  BufferToStream();

  return in_buff_length;
}

} // namespace tkl::tf
