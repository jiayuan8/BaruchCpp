/*  Array.hpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "Point.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        class Array 
        {
        public:
            Array();                // default constructor
            Array(size_t size);     // constructor with size argument
            Array(const Array& other);  // copy constructor
            ~Array();               // destructor

            CAD::Point& operator [] (int index);                 // overloading assign operator, allow write
            const CAD::Point& operator [] (int index) const;     // overloding the [] operator
            Array& operator = (const Array& source);        // overloading assign operator

            size_t Size() const;    // return the size of the arr
            void SetElement(size_t index, const CAD::Point& element) const;  // set the element of the array
            const CAD::Point& GetElement(size_t index) const;    // return the element of the array given the index
            
        private:
            CAD::Point* m_data;          // pointer pointing to the data
            size_t arr_size;        // size of array
        };
    }
}

#endif
