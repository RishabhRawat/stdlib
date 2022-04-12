//
// Created by Rishabh on 31-03-2022.
//

#ifndef STDLIB_IMPLEMENTATION_ALGORITHM_H
#define STDLIB_IMPLEMENTATION_ALGORITHM_H

#include "type_traits.h"
namespace stdalt {

template <typename T>
constexpr typename remove_reference<T>::type &&move(T &&item) noexcept {
    return static_cast<typename remove_reference<T>::type &&>(item);
}

template <class T>
inline void swap(T &a, T &b) noexcept {
    T temp = move(a);
    b = move(a);
    a = move(temp);
};
} // namespace stdalt

#endif // STDLIB_IMPLEMENTATION_ALGORITHM_H
