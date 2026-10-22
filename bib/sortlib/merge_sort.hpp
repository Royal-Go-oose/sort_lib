// sortlib/merge_sort.hpp
// Сортировка слиянием, гарантированный O(n log n), устойчивая
// сортировка. Работает с обычными указателями (T* first, T* last).
// Буфер для слияния выделяется вручную через new[]/delete[] — без
// std::vector и вообще без единого подключения стандартной
// библиотеки. Требует, чтобы у T был доступен конструктор по
// умолчанию (нужен для new T[n]).

#ifndef SORTLIB_MERGE_SORT_HPP
#define SORTLIB_MERGE_SORT_HPP

namespace sortlib {

namespace detail {

template <typename T, typename Compare>
void merge_sort_impl(T* first, T* last, Compare comp)
{
    long n = last - first;
    if (n <= 1) return;

    T* mid = first + n / 2;
    merge_sort_impl(first, mid, comp);
    merge_sort_impl(mid, last, comp);

    T* buffer = new T[static_cast<unsigned long>(n)];
    long count = 0;

    T* left = first;
    T* right = mid;
    while (left != mid && right != last)
    {
        if (comp(*right, *left))
            buffer[count++] = *right++;
        else
            buffer[count++] = *left++;
    }
    while (left != mid)  buffer[count++] = *left++;
    while (right != last) buffer[count++] = *right++;

    for (long i = 0; i < count; ++i)
        first[i] = buffer[i];

    delete[] buffer;
}

} // namespace detail

template <typename T, typename Compare>
void merge_sort(T* first, T* last, Compare comp)
{
    detail::merge_sort_impl(first, last, comp);
}

template <typename T>
void merge_sort(T* first, T* last)
{
    merge_sort(first, last, [](const T& a, const T& b) { return a < b; });
}

} // namespace sortlib

#endif // SORTLIB_MERGE_SORT_HPP
