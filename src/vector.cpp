#include "vector.h"
#include "algorithm.h"
#include <climits>
#include <vector>

namespace stdalt {

// Constructors
template <typename T>
vector<T>::vector() : m_size(0), m_reserved(0), m_data(nullptr) {}

template <typename T>
vector<T>::vector(vector::size_type count, const T &value) : m_size(count), m_reserved(count), m_data(new T[count]) {
    for (size_type i = 0; i < count; ++i) {
        m_data[i] = value;
    }
}

template <typename T>
vector<T>::vector(vector::size_type count) : m_size(count), m_reserved(count), m_data(new T[count]) {}

template <typename T>
vector<T>::vector(const vector &other) : m_size(other.m_size), m_reserved(other.m_reserved), m_data(new T[other.m_reserved]) {
    for (size_type i = 0; i < other.m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

template <typename T>
vector<T>::vector(vector &&other) noexcept : m_size(other.m_size), m_reserved(other.m_reserved), m_data(other.m_data) {
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_reserved = 0;
}

template <typename T>
vector<T>::~vector() {
    delete[] m_data;
    m_size = 0;
    m_reserved = 0;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&other) noexcept {
    swap(m_size, other.m_size);
    swap(m_reserved, other.m_reserved);
    swap(m_data, other.m_data);
    return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &other) {
    swap(this, other);
    return *this;
}

template <typename T>
void vector<T>::assign(vector::size_type count, const T &value) {
    if (count > m_reserved) {
        swap(this, vector(count, value));
    } else {
        m_size = count;
        for (size_type i = 0; i < count; ++i) {
            m_data[i] = value;
        }
    }
}

template <typename T>
typename vector<T>::reference vector<T>::at(vector::size_type pos) {
    if (pos < 0 or pos > m_size)
        throw "EXCEPTION";
    return m_data[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(vector::size_type pos) const {
    if (pos < 0 or pos > m_size)
        throw "EXCEPTION";
    return m_data[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](vector::size_type pos) {
    return m_data[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](vector::size_type pos) const {
    return m_data[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::front() {
    if (m_size == 0)
        return nullptr;
    return m_data[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
    if (m_size == 0)
        return nullptr;
    return m_data[0];
}

template <typename T>
typename vector<T>::reference vector<T>::back() {
    if (m_size == 0)
        return nullptr;
    return m_data[m_size - 1];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
    if (m_size == 0)
        return nullptr;
    return m_data[m_size - 1];
}

template <typename T>
typename vector<T>::pointer vector<T>::data() noexcept {
    return m_data;
}

template <typename T>
typename vector<T>::pointer const vector<T>::data() const noexcept {
    return m_data;
}

template <typename T>
bool vector<T>::empty() const noexcept {
    return m_size == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept {
    return m_size;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
    return ULONG_MAX;
}

template <typename T>
void vector<T>::reserve(vector::size_type new_cap) {
    if (new_cap > max_size())
        throw "LENGTH ERROR";
    if (new_cap <= m_reserved)
        return;

    auto new_mem = new T[new_cap];
    for (size_type i = 0; i < m_size; i++) {
        new_mem[i] = m_data;
    }
    swap(m_data, new_mem);
    m_reserved = new_cap;
    delete[] new_mem;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
    return m_reserved;
}

template <typename T>
void vector<T>::shrink_to_fit() {
    if (m_size == m_reserved)
        return;

    auto new_mem = new T[m_size];
    for (size_type i = 0; i < m_size; i++) {
        new_mem[i] = m_data;
    }
    swap(m_data, new_mem);
    m_reserved = m_size;
    delete[] new_mem;
}

template <typename T>
void vector<T>::clear() noexcept {
    
}

} // namespace stdalt