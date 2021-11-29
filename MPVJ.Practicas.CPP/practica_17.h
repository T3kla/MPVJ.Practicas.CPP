#pragma once

#include <iostream>

#define DECLARE_ENUM_VALUE_ACTION(_ENUM) _ENUM,

#define ENUM_TO_STRING_ACTION(_ENUM)                                                                                   \
    if (_eState == Enum::_ENUM)                                                                                        \
    {                                                                                                                  \
        return #_ENUM;                                                                                                 \
    }

#define STRING_TO_ENUM_ACTION(_STRING)                                                                                 \
    if (strcmp(_sEnum, #_STRING) == 0)                                                                                 \
    {                                                                                                                  \
        return Enum::_STRING;                                                                                          \
    }

#define DECLARE_ENUM(_NAME, _LIST)                                                                                     \
    struct _NAME                                                                                                       \
    {                                                                                                                  \
        enum Enum                                                                                                      \
        {                                                                                                              \
            Invalid = -1,                                                                                              \
            _LIST(DECLARE_ENUM_VALUE_ACTION) Count                                                                     \
        };                                                                                                             \
        static const char *ToString(Enum _eState)                                                                      \
        {                                                                                                              \
            _LIST(ENUM_TO_STRING_ACTION)                                                                               \
            assert(false);                                                                                             \
            return "Invalid";                                                                                          \
        }                                                                                                              \
        static Enum ToEnum(const char *_sEnum)                                                                         \
        {                                                                                                              \
            _LIST(STRING_TO_ENUM_ACTION)                                                                               \
            assert(false);                                                                                             \
            return Enum::Invalid;                                                                                      \
        }                                                                                                              \
    }

#define STATE_ENUM_DEFINITION_LIST(_CALL)                                                                              \
    _CALL(Idle)                                                                                                        \
    _CALL(Chase)                                                                                                       \
    _CALL(Attacking)                                                                                                   \
    _CALL(Cover)

DECLARE_ENUM(SState, STATE_ENUM_DEFINITION_LIST);

#define NEW_ENUM(structname, ename, p1, p2, p3, p4)                                                                    \
    struct structname                                                                                                  \
    {                                                                                                                  \
        enum class ename                                                                                               \
        {                                                                                                              \
            p1,                                                                                                        \
            p2,                                                                                                        \
            p3,                                                                                                        \
            p4                                                                                                         \
        };                                                                                                             \
                                                                                                                       \
        const char *as_str(ename _enum)                                                                                \
        {                                                                                                              \
            AS_STR_IF(ename, p1);                                                                                      \
            AS_STR_IF(ename, p2);                                                                                      \
            AS_STR_IF(ename, p3);                                                                                      \
            AS_STR_IF(ename, p4);                                                                                      \
            return "error";                                                                                            \
        };                                                                                                             \
                                                                                                                       \
        ename as_enum(const char *_str)                                                                                \
        {                                                                                                              \
            AS_ENUM_IF(ename, p1);                                                                                     \
            AS_ENUM_IF(ename, p2);                                                                                     \
            AS_ENUM_IF(ename, p3);                                                                                     \
            AS_ENUM_IF(ename, p4);                                                                                     \
            return ename::p1;                                                                                          \
        }                                                                                                              \
    }

#define AS_STR_IF(ename, case)                                                                                         \
    if (_enum == ename::case)                                                                                          \
    return #case

#define AS_ENUM_IF(ename, case)                                                                                        \
    if (_str == "case")                                                                                                \
    return ename::case

namespace p17
{

struct without_macro
{
    enum class e_some
    {
        none,
        one,
        two,
        three
    };
    const char *as_str(e_some _enum)
    {
        if (_enum == e_some::one)
            return "one";
        if (_enum == e_some::two)
            return "two";
        if (_enum == e_some::three)
            return "three";
        if (_enum == e_some::none)
            return "none";
    };
    e_some as_enum(const char *_str)
    {
        if (_str == "one")
            return e_some::one;
        if (_str == "two")
            return e_some::two;
        if (_str == "three")
            return e_some::three;
        if (_str == "none")
            return e_some::none;
    }
};

NEW_ENUM(with_macro, e_some, none, four, five, six);

} // namespace p17

void run_practica_17()
{
    auto with = p17::with_macro();
    auto without = p17::without_macro();

    std::cout << with.as_str(p17::with_macro::e_some::five) << std::endl;
    std::cout << without.as_str(p17::without_macro::e_some::one) << std::endl;

    std::cout << COUNT() << std::endl;
    std::cout << COUNT("A") << std::endl;
    std::cout << COUNT("A", "A") << std::endl;
    std::cout << COUNT("A", "A", "A") << std::endl;
    std::cout << COUNT("A", "A", "A", "A") << std::endl;
    std::cout << COUNT("A", "A", "A", "A", "A") << std::endl;
    std::cout << COUNT("A", "A", "A", "A", "A", "A") << std::endl;
    std::cout << COUNT("A", "A", "A", "A", "A", "A", "A") << std::endl;
}
