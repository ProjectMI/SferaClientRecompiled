#include "text/Text.h"

template <class Fold> int SferaText::compareText(std::string_view first, std::string_view second, Fold fold)
{
    const auto count = std::min(first.size(), second.size());
    for (std::size_t index = 0; index < count; ++index)
    {
        const auto difference = fold(SferaText::byteValue(first[index])) - fold(SferaText::byteValue(second[index]));
        if (difference != 0)
            return difference;
    }
    if (first.size() == second.size())
        return 0;
    return first.size() > count ? fold(SferaText::byteValue(first[count])) : -fold(SferaText::byteValue(second[count]));
}

int SferaText::compare(std::string_view first, std::string_view second)
{
    return compareText(first, second, &SferaText::unchangedByte);
}

int SferaText::compareInsensitive(std::string_view first, std::string_view second)
{
    return compareText(first, second, &SferaText::lowercaseByte);
}

