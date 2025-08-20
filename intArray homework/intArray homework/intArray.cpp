#include "intArray.h"

IntArray :: IntArray(int length) : m_length{ length }
{
    if (length <= 0)
    {
        throw "Lenght cant be <= 0";
    }
    if (length > 0)
    {
        m_data = new int[static_cast<std::size_t>(length)] {};
    }
}
IntArray :: IntArray(const IntArray& a) : IntArray(a.getLength())
{
    std::copy_n(a.m_data, m_length, m_data);
}
void IntArray :: erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}
int& IntArray :: operator[](int index)
{
    if (index < 0 || index >= m_length)
    {
        throw "Index out of bounds";
    }
    return m_data[index];
}
void IntArray ::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;
    m_data = new int[static_cast<std::size_t>(newLength)];
    m_length = newLength;
}
void IntArray :: resize(int newLength)
{
    if (newLength == m_length)
        return;
    if (newLength <= 0)
    {
        erase();
        return;
    }
    int* data{ new int[static_cast<std::size_t>(newLength)] };
    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        std::copy_n(m_data, elementsToCopy, data);
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}
void IntArray :: insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
    {
        throw "Index out of range";
    }
    int* data{ new int[static_cast<std::size_t>(m_length + 1)] };
    std::copy_n(m_data, index, data);
    data[index] = value;
    std::copy_n(m_data + index, m_length - index, data + index + 1);
    delete[] m_data;
    m_data = data;
    ++m_length;
}
void IntArray :: remove(int index)
{
    if (index < 0 || index >= m_length)
    {
        throw "Index out of bounds";
    }
    if (m_length == 1)
    {
        erase();
        return;
    }
    int* data{ new int[static_cast<std::size_t>(m_length - 1)] };
    std::copy_n(m_data, index, data);
    std::copy_n(m_data + index + 1, m_length - index - 1, data + index);
    delete[] m_data;
    m_data = data;
    --m_length;
}
