/*  Array.hpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T>
        class Array 
        {
        public:
            Array();                // default constructor
            Array(size_t size);     // constructor with size argument
            Array(const Array<T>& other);  // copy constructor
            ~Array();               // destructor

            T& operator [] (int index);                 // overloading assign operator, allow write
            const T& operator [] (int index) const;     // overloding the [] operator
            Array<T>& operator = (const Array<T>& source);        // overloading assign operator

            size_t Size() const;    // return the size of the arr
            void SetElement(size_t index, const T& element) const;  // set the element of the array
            const T& GetElement(size_t index) const;    // return the element of the array given the index
            
        private:
            T* m_data;          // pointer pointing to the data
            size_t m_size;        // size of array
        };
    }
}

#ifndef ARRAY_CPP
#include "Array.cpp"
#endif

#endif
