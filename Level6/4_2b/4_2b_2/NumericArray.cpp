/*  NumericArray.cpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include "NumericArray.hpp"
#include "DifferentSizeException.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T>
        NumericArray<T>::NumericArray(): Array<T>()
        {
            // default constructor
        }

        template <typename T>
        NumericArray<T>::NumericArray(size_t size): Array<T>(size)
        {
            // constructor with parameters
        }

        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray<T>& other)
        : Array<T>(other)
        {
            // copy constructor
        }

        template <typename T>
        NumericArray<T>::~NumericArray()
        {
            // destructor
        }

        template <typename T>
        NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T> other)
        {
            // preclude self copying
            if (this == &other)
            {
                return *this;
            }
            // call base class
            Array<T>::operator = (other);
            return *this;
        }

        template <typename T>
        NumericArray<T> NumericArray<T>::operator * (const T& factor) const
        {
            NumericArray<T> res(*this);
            for (int i = 0; i < this->Size(); i++)
            {
                res[i] *= factor;
            }
            return res;
        }
        template <typename T>
        NumericArray<T> NumericArray<T>::operator + (const NumericArray<T> other) const
        {
            if(this->Size() != other.Size())
            {
                throw DifferentSizeException(this->Size(), other.Size());
            }
            
            NumericArray<T> res(*this);
            for (int i = 0; i < this->Size(); i++)
            {
                res[i] += other[i];
            }
            return res;
        }

        template <typename T>
        const T NumericArray<T>::DotProduct(const NumericArray<T> other) const
        {
            if(this->Size() != other.Size())
            {
                throw DifferentSizeException(this->Size(), other.Size());
            }
            
            T res(0);   // initialize to 0
            for (int i = 0; i < this->Size(); i++)
            {
                res += ((*this)[i] * other[i]);
            }
            return res;
        }
    }
}

#endif