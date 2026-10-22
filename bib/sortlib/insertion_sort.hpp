// sortlib/insertion_sort.hpp
// Сортировка вставками, O(n^2), эффективна на почти отсортированных
// данных. Работает с обычными указателями (T* first, T* last).
// Не подключает ни одного стандартного заголовка — все операции
// сводятся к копированию через operator= и сравнению через comp.

#ifndef SORTLIB_INSERTION_SORT_HPP
#define SORTLIB_INSERTION_SORT_HPP

namespace sortlib {

template <typename T, typename Compare>
void insertion_sort(T* first, T* last, Compare comp)
{
    if (first == last) return;

    for (T* it = first + 1; it != last; ++it)
    {
        T key = *it;
        T* j = it;
        while (j != first && comp(key, *(j - 1)))
        {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

template <typename T>
void insertion_sort(T* first, T* last)
{
    insertion_sort(first, last, [](const T& a, const T& b) { return a < b; });
}

} // namespace sortlib

#endif // SORTLIB_INSERTION_SORT_HPP
