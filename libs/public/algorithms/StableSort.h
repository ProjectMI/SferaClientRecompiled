#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <type_traits>

class SferaAlgorithms;

class SferaAlgorithms
{
  public:
    // Preserve input order for equal keys; NaNs sort last and never violate strict weak ordering.
    template <class Range, class Projection> static void stableSort(Range &&values, Projection key)
    {
        std::stable_sort(values.begin(), values.end(), std::bind_front(&SferaAlgorithms::compareProjected<Projection, std::remove_cvref_t<decltype(*values.begin())>>, std::ref(key)));
    }

  private:
    template <class Projection, class Element> static bool compareProjected(Projection &key, const Element &left, const Element &right)
    {
        const auto a = key(left), b = key(right);
        if constexpr (std::is_floating_point_v<decltype(a)>)
        {
            if (std::isnan(a))
                return false;
            if (std::isnan(b))
                return true;
        }
        return a < b;
    }
};
