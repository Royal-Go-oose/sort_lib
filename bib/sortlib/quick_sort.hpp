// sortlib/quick_sort.hpp
// Быстрая сортировка, среднее O(n log n). Работает с обычными
// указателями (T* first, T* last), без единого подключения
// стандартной библиотеки — только собственная detail::swap_values.
//
// Опорный элемент выбирается как медиана из (first, mid, last-1), и
// используется схема partition по Ломуто — это гарантирует, что обе
// получившиеся части строго меньше исходного диапазона (в отличие от
// "наивной" схемы Хоара, где двухэлементный диапазон может не
// разделиться и вызвать зацикливание), а заодно защищает от
// вырождения в худший случай на уже отсортированных данных.

#ifndef SORTLIB_QUICK_SORT_HPP
#define SORTLIB_QUICK_SORT_HPP

#include "detail/swap.hpp"

namespace sortlib {

namespace detail {

template <typename T, typename Compare>
T* quick_sort_partition(T* first, T* last, Compare comp)
{
    T* mid = first + (last - first) / 2;
    T* pivot_it = last - 1;

    if (comp(*mid, *first))      swap_values(*mid, *first);
    if (comp(*pivot_it, *first)) swap_values(*pivot_it, *first);
    if (comp(*pivot_it, *mid))   swap_values(*pivot_it, *mid);
    swap_values(*mid, *pivot_it); // опорный элемент теперь в pivot_it (last - 1)

    T pivot = *pivot_it;

    T* store = first;
    for (T* it = first; it != pivot_it; ++it)
    {
        if (comp(*it, pivot))
        {
            swap_values(*store, *it);
            ++store;
        }
    }
    swap_values(*store, *pivot_it);
    return store; // first <= store <= last - 1
}

} // namespace detail

template <typename T, typename Compare>
void quick_sort(T* first, T* last, Compare comp)
{
    while (last - first > 1)
    {
        T* mid = detail::quick_sort_partition(first, last, comp);
        // Элемент в позиции mid уже стоит на своём окончательном месте,
        // поэтому исключаем его из обеих частей. Рекурсивно сортируем
        // более короткую часть, а более длинную обрабатываем в цикле —
        // это гарантирует прогресс на каждой итерации (диапазон строго
        // уменьшается) и ограничивает глубину рекурсии O(log n).
        if (mid - first < last - (mid + 1))
        {
            quick_sort(first, mid, comp);
            first = mid + 1;
        }
        else
        {
            quick_sort(mid + 1, last, comp);
            last = mid;
        }
    }
}

template <typename T>
void quick_sort(T* first, T* last)
{
    quick_sort(first, last, [](const T& a, const T& b) { return a < b; });
}

} // namespace sortlib

#endif // SORTLIB_QUICK_SORT_HPP
