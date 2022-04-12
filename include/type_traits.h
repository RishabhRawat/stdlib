//
// Created by Rishabh on 31-03-2022.
//

#ifndef STDLIB_IMPLEMENTATION_TYPE_TRAITS_H
#define STDLIB_IMPLEMENTATION_TYPE_TRAITS_H

namespace stdalt {
/// remove_reference
template <typename T>
struct remove_reference {
    typedef T type;
};

template <typename T>
struct remove_reference<T &> {
    typedef T type;
};

template <typename T>
struct remove_reference<T &&> {
    typedef T type;
};
} // namespace stdalt

#endif // STDLIB_IMPLEMENTATION_TYPE_TRAITS_H
