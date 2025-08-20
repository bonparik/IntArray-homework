#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <algorithm> // for std::copy_n
#include <cstddef> // for std::size_t
#include <cstdlib>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray() {delete[] m_data;}
    IntArray(const IntArray& a);
    IntArray& operator=(const IntArray& a)
    {
        if (&a == this)
            return *this;
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data);

        return *this;
    }
    void erase();
    int& operator[](int index);
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
    int getLength() const { return m_length; }
};

#endif
