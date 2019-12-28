/*  Array.cpp
 *  ------------------------------------------
 *  @description: source file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 27, 2019
 */

#include "Array.hpp"

using std::cout;
using std::endl;

Array::Array(): m_data(new Point[10]), arr_size(10)
{
    // default constructor, the arr size will be 10
}

Array::Array(size_t size)
: m_data(new Point[size >= 1 ? size : 1]), arr_size(size >= 1 ? size : 1)
{
    // constructor with size parameter, the size need to be at least 1
    // will be cast to 1 if a 0 is given    
}

Array::Array(const Array& other): m_data(new Point[other.Size()]), arr_size(other.Size())
{
    // copy constructor
    for (size_t i = 0; i < other.Size(); i++)
    {
        m_data[i] = other.m_data[i];
    }
}

Array::~Array()
{
    // destructor
    delete[] m_data;
}

size_t Array::Size() const
{
    return arr_size;
}

void Array::SetElement(size_t index, const Point& element) const
{
    // check if the index is out of bound
    if (index >= arr_size)
    {
        return;
    }
    m_data[index] = element;
}

const Point& Array::GetElement(size_t index) const
{
    // if the index is out of bound, return the first element
    if (index >= arr_size)
    {
        return m_data[0];
    }
    return m_data[index];
}

Array& Array::operator = (const Array& source)
{
    // preclude assigning to itself
    if (this == &source)
    {
        return *this;
    }

    // free the original memory
    delete [] m_data;

    // copy the elements
    arr_size = source.Size();
    m_data = new Point[arr_size];
    for (size_t i = 0; i < arr_size; i++)
    {
        m_data[i] = source.m_data[i];
    }
    return *this;
}

Point& Array::operator [] (int index)
{
    if (index >= arr_size)
    {
        return m_data[0];
    }
    return m_data[index];
}

const Point& Array::operator [] (int index) const
{
    // this allows us to call for [] for a const object in a const function
    // read only, cannot write
    if (index >= arr_size)
    {
        return m_data[0];
    }
    return m_data[index];
}