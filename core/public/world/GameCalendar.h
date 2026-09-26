#pragma once

#include <array>
#include <cstdint>

class SferaGameCalendar;
struct SferaGameCalendarField;

struct SferaGameCalendarField
{
    unsigned shift;
    unsigned width;
    std::uint32_t bias;
    constexpr std::uint32_t mask() const
    {
        return (1u << width) - 1u;
    }
};
enum SferaGameCalendarComponent : int
{
    SferaGameCalendarComponentQuarter = 1,
    SferaGameCalendarComponentMinute,
    SferaGameCalendarComponentHour,
    SferaGameCalendarComponentDay,
    SferaGameCalendarComponentMonth,
    SferaGameCalendarComponentYear
};

class SferaGameCalendar
{
    static constexpr std::array<SferaGameCalendarField, 6> fields{{{0, 2, 0}, {2, 6, 0}, {8, 5, 0}, {13, 5, 0}, {18, 4, 0}, {22, 10, 7800}}};
    static constexpr const SferaGameCalendarField &field(int index)
    {
        return fields[index >= 1 && index <= 5 ? index - 1 : 5];
    }

  public:
    static constexpr std::uint32_t firstYear = 7800;
    static constexpr std::uint32_t quartersPerMinute = 4, minutesPerHour = 60, hoursPerDay = 24, daysPerYear = 365;
    static constexpr std::uint32_t quartersPerHour = quartersPerMinute * minutesPerHour, quartersPerDay = quartersPerHour * hoursPerDay, quartersPerYear = quartersPerDay * daysPerYear;
    static constexpr std::array<std::uint32_t, 13> monthStarts{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static constexpr std::uint32_t daysInMonth(std::uint32_t month)
    {
        return month >= 1 && month <= 12 ? monthStarts[month] - monthStarts[month - 1] : 0;
    }
    static constexpr std::uint32_t daysBeforeMonth(std::uint32_t month)
    {
        return month >= 1 && month <= 13 ? monthStarts[month - 1] : 0;
    }
    static constexpr std::uint32_t pack(std::uint32_t year, std::uint32_t month, std::uint32_t day, std::uint32_t hour, std::uint32_t minute, std::uint32_t quarter = 0)
    {
        return ((year - firstYear) << field(SferaGameCalendarComponentYear).shift) | (month << field(SferaGameCalendarComponentMonth).shift) |
               ((day & field(SferaGameCalendarComponentDay).mask()) << field(SferaGameCalendarComponentDay).shift) | (hour << field(SferaGameCalendarComponentHour).shift) |
               (minute << field(SferaGameCalendarComponentMinute).shift) | quarter;
    }
    static std::uint32_t fromUnixTime(std::int64_t timestamp);
    static std::uint32_t advance(std::uint32_t calendar);
    static std::uint32_t component(std::uint32_t calendar, int index);
    static std::uint32_t withComponent(std::uint32_t calendar, int index, std::uint32_t value);
    static std::uint32_t ticks(std::uint32_t calendar);
};
