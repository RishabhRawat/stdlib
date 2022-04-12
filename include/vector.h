#ifndef STDLIB_IMPLEMENTATION_VECTOR_H
#define STDLIB_IMPLEMENTATION_VECTOR_H

#include <cstddef>

namespace stdalt {
template <typename T>
class vector {
  public:
    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using iterator = T *;
    using const_iterator = const T *;
    //        using reverse_iterator =
    //        using const_reverse_iterator

    // Constructors
    vector();
    vector(size_type count, const T &value);
    explicit vector(size_type count);
    //    template <class InputIt>
    //    vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());

    vector(const vector &other);
    vector(vector &&other) noexcept;
    //    vector(std::initializer_list<T> init, const Allocator &alloc = Allocator());

    // Destructor
    ~vector();

    // Copy assignment
    vector &operator=(const vector &other);
    vector &operator=(vector &&other) noexcept;
    //    vector &operator=(std::initializer_list<T> ilist);

    // Assign function
    void assign(size_type count, const T &value);

    //    template <class InputIt>
    //    void assign(InputIt first, InputIt last);
    //    void assign(std::initializer_list<T> ilist);

    // Element Access
    reference at(size_type pos);
    const_reference at(size_type pos) const;

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    pointer data() noexcept;
    const pointer data() const noexcept;

    // Iterator Access
    // Skipped

    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    void reserve( size_type new_cap );
    size_type capacity() const noexcept;
    void shrink_to_fit();

    // Modifiers
    void clear() noexcept;








    void push_back(T obj);

  private:
    size_type m_size, m_reserved;
    pointer m_data;
};
} // namespace stdalt

#endif // STDLIB_IMPLEMENTATION_VECTOR_H
