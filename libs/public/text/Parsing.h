#pragma once

#include <cstddef>
#include <string_view>

template <class T> struct SphereUINamedValue
{
    std::string_view name;
    T value;
};

struct SferaParserRange;

struct SferaParserRange
{
    std::ptrdiff_t begin;
    std::ptrdiff_t end;
};
