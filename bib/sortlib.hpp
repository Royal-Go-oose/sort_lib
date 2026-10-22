// sortlib.hpp
// Главный заголовок библиотеки sortlib — подключает реализацию каждой
// из пяти сортировок из отдельных файлов в подкаталоге sortlib/.
//
// Библиотека полностью реализована на чистом C++ без стандартной
// библиотеки: ни <algorithm>, ни <iterator>, ни <functional>, ни
// <vector>, ни <utility> нигде не используются. Сортировки работают
// с обычными указателями (T* first, T* last) вместо абстракции
// итераторов, обмен значений сделан вручную (sortlib::detail::swap_values
// вместо std::swap/std::iter_swap), а буфер для merge_sort выделяется
// через new[]/delete[] вместо std::vector.
//
// Единственное, что использует язык "из коробки" без всякого
// #include — это шаблоны, лямбды, new/delete и ссылки; всё это
// базовые возможности языка C++, а не библиотека.
//
// Если нужна только одна сортировка, можно подключить напрямую
// соответствующий файл из sortlib/, например:
//     #include "sortlib/quick_sort.hpp"

#ifndef SORTLIB_HPP
#define SORTLIB_HPP

#include "sortlib/bubble_sort.hpp"
#include "sortlib/insertion_sort.hpp"
#include "sortlib/selection_sort.hpp"
#include "sortlib/quick_sort.hpp"
#include "sortlib/merge_sort.hpp"

#endif // SORTLIB_HPP
