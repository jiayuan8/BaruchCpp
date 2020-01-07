/*  PointArray.hpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "Array.hpp"
#include "Point.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        class PointArray: public Array<CAD::Point>
        {
        public:
            // constructors
            PointArray();               // default constructor
            PointArray(size_t size);    // constructor with initial size
            PointArray(const PointArray& other);    // copy constructor

            // destructor
            ~PointArray();              // destructor

            // operator overload
            PointArray& operator = (const PointArray& other);
            double Length() const;

        private:
        
        };
    }
}

#endif