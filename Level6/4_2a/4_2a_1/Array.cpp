/*  Array.cpp
 *  ------------------------------------------
 *  @description: source file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 27, 2019
 */

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

using std::cout;
using std::endl;

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T>
        Array<T>::Array(): m_data(new T[10]), m_size(10)
        {
            // default constructor, the arr size will be 10
        }

        template <typename T>
        Array<T>::Array(size_t size)
        : m_data(new T[size >= 1 ? size : 1]), m_size(size >= 1 ? size : 1)
        {
            // constructor with size parameter, the size need to be at least 1
            // will be cast to 1 if a 0 is given    
        }

        template <typename T>
        Array<T>::Array(const Array<T>& other)
        : m_data(new T[other.m_size]), m_size(other.m_size)
        {
            // copy constructor
            for (size_t i = 0; i < other.m_size; i++)
            {
                m_data[i] = other[i];
            }
        }
        
        template <typename T>
        Array<T>::~Array()
        {
            // destructor
            delete[] m_data;
        }

        template <typename T>
        size_t Array<T>::Size() const
        {
            return m_size;
        }

        template <typename T>
        T& Array<T>::operator [] (int index)
        {
            if (index >= m_size || index < 0)
            {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }

        template <typename T>
        const T& Array<T>::operator [] (int index) const
        {
            // this allows us to call for [] for a const object in a const function
            // read only, cannot write
            if (index >= m_size || index < 0)
            {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }

        template <typename T>
        Array<T>& Array<T>::operator = (const Array<T>& source)
        {
            // preclude assigning to itself
            if (this == &source)
            {
                return *this;
            }

            // free the original memory
            delete [] m_data;

            // copy the elements
            m_size = source.m_size;
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_data[i] = source[i];
            }
            return *this;
        }

        template <typename T>
        void Array<T>::SetElement(size_t index, const T& element) const
        {
            // check if the index is out of bound
            if (index >= m_size || index < 0)
            {
                throw OutOfBoundsException(index);
            }
            m_data[index] = element;
        }

        template <typename T>
        const T& Array<T>::GetElement(size_t index) const
        {
            // if the index is out of bound, return the first element
            if (index >= m_size || index < 0)
            {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }
    }
}

#endif
        
