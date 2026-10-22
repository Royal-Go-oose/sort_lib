// sortlib/selection_sort.hpp
// Сортировка выбором, O(n^2), минимальное число перестановок.
// Работает с обычными указателями (T* first, T* last), без единого
// подключения стандартной библиотеки.

#ifndef SORTLIB_SELECTION_SORT_HPP
#define SORTLIB_SELECTION_SORT_HPP

#include "detail/swap.hpp"

namespace sortlib {

template <typename T, typename Compare>
void selection_sort(T* first, T* last, Compare comp)
{
    if (first == last) return;

    for (T* it = first; it != last; ++it)
    {
        T* min_it = it;
        for (T* jt = it + 1; jt != last; ++jt)
        {
            if (comp(*jt, *min_it))
                min_it = jt;
        }
        if (min_it != it)
            detail::swap_values(*it, *min_it);
    }
}

template <typename T>
void selection_sort(T* first, T* last)
{
    selection_sort(first, last, [](const T& a, const T& b) { return a < b; });
}

} // namespace sortlib

#endif // SORTLIB_SELECTION_SORT_HPP
