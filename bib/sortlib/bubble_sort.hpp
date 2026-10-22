// sortlib/bubble_sort.hpp
// Пузырьковая сортировка, O(n^2). Работает с обычными указателями на
// массив (T* first, T* last), без единого подключения стандартной
// библиотеки — только собственная detail::swap_values и базовые
// возможности языка (шаблоны, лямбды).

#ifndef SORTLIB_BUBBLE_SORT_HPP
#define SORTLIB_BUBBLE_SORT_HPP

#include "detail/swap.hpp"

namespace sortlib {

// comp(a, b) должен возвращать true, если a должно стоять раньше b
// (как std::less: comp(a, b) == (a < b) для сортировки по возрастанию).
template <typename T, typename Compare>
void bubble_sort(T* first, T* last, Compare comp)
{
    if (first == last) return;

    bool swapped = true;
    T* end = last;
    while (swapped)
    {
        swapped = false;
        T* it = first;
        T* next = first + 1;
        for (; next != end; ++it, ++next)
        {
            if (comp(*next, *it))
            {
                detail::swap_values(*it, *next);
                swapped = true;
            }
        }
        --end; // последний элемент уже точно на своём месте
    }
}

// Перегрузка по умолчанию: сортировка по возрастанию через operator<.
template <typename T>
void bubble_sort(T* first, T* last)
{
    bubble_sort(first, last, [](const T& a, const T& b) { return a < b; });
}

} // namespace sortlib

#endif // SORTLIB_BUBBLE_SORT_HPP
