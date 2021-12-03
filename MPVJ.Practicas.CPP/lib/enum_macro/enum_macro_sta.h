#pragma once

#define ENUM_CLASS_STA(name, p1, p2, p3, p4)                                                                           \
    struct name                                                                                                        \
    {                                                                                                                  \
        enum class e##_name{p1, p2, p3, p4};                                                                           \
                                                                                                                       \
        static const char *as_cstr(e##_name _enum)                                                                     \
        {                                                                                                              \
            AS_STR_IF(e##_name, p1);                                                                                   \
            AS_STR_IF(e##_name, p2);                                                                                   \
            AS_STR_IF(e##_name, p3);                                                                                   \
            AS_STR_IF(e##_name, p4);                                                                                   \
            return "error";                                                                                            \
        };                                                                                                             \
                                                                                                                       \
        static e##_name as_enum(const char *_str)                                                                      \
        {                                                                                                              \
            AS_ENUM_IF(e##_name, p1);                                                                                  \
            AS_ENUM_IF(e##_name, p2);                                                                                  \
            AS_ENUM_IF(e##_name, p3);                                                                                  \
            AS_ENUM_IF(e##_name, p4);                                                                                  \
            return e##_name::p1;                                                                                       \
        }                                                                                                              \
    }

#define AS_STR_IF(name, case)                                                                                          \
    if (_enum == name::case)                                                                                           \
    return #case

#define AS_ENUM_IF(name, case)                                                                                         \
    if (_str == "case")                                                                                                \
    return name::case
