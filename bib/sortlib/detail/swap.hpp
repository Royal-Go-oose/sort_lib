// sortlib/detail/swap.hpp
// Собственная реализация обмена значений — замена std::swap /
// std::iter_swap. Не подключает ни одного стандартного заголовка,
// использует только базовые возможности языка (шаблоны, ссылки,
// копирование через оператор присваивания).

#ifndef SORTLIB_DETAIL_SWAP_HPP
#define SORTLIB_DETAIL_SWAP_HPP

namespace sortlib {
namespace detail {

template <typename T>
inline void swap_values(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

} // namespace detail
} // namespace sortlib

#endif // SORTLIB_DETAIL_SWAP_HPP
