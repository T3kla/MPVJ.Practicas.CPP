#pragma once

#include <string>
#include <vector>

static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

static inline std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

static inline std::vector<std::string> split(const std::string &text,
                                             char sep) {
  std::vector<std::string> tokens;
  size_t start = 0, end = 0;

  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.emplace_back(ltrim_copy(text.substr(start, end - start)));
    start = end + 1;
  }
  tokens.emplace_back(text.substr(start));

  return tokens;
}

// Esta es la unica manera que he encontrado de hacer enums de tamaño dinamico
// que puedan contener las funciones de as_cstr y as_enum
//
// Podría mantener la estaticidad haciendo un singletone pero llegados a este
// punto yo creo que mejor parar y replantearse la vida y las cosas
#define ENUM_CLASS_DYN(name, ...)                                              \
  struct name {                                                                \
    ENUM(e, __VA_ARGS__);                                                      \
                                                                               \
    std::vector<std::string> vec = split(#__VA_ARGS__, ',');                   \
                                                                               \
    const char *as_cstr(e _enum) const {                                       \
      if (_enum >= -1 && _enum < count)                                        \
        return vec.at(_enum).c_str();                                          \
      return "";                                                               \
    }                                                                          \
                                                                               \
    e as_enum(const char *_cstr) const {                                       \
      auto it = std::find(vec.begin(), vec.end(), _cstr);                      \
      auto result = -1;                                                        \
      if (it != vec.end())                                                     \
        result = it - vec.begin();                                             \
      return (e)result;                                                        \
    }                                                                          \
  };

#define ENUM(name, ...) enum name { none = -1, __VA_ARGS__, count }
