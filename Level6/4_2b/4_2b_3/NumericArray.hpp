/*  NumericArray.hpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP

#include "Array.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T>
        class NumericArray: public Array<T>
        {
        public:
            // constructors
            NumericArray();
            NumericArray(size_t size);
            NumericArray(const NumericArray<T>& other);

            // destructor
            ~NumericArray();

            // overloading operators
            NumericArray<T>& operator = (const NumericArray<T> other);
            NumericArray<T> operator * (const T& factor) const;
            NumericArray<T> operator + (const NumericArray<T> other) const;

            // member functions
            T DotProduct(const NumericArray<T> other) const;

        private:

        };
    }
}

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif

#endif