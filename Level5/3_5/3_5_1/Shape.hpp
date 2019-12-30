/*  Shape.hpp
 *  ------------------------------------------
 *  @description: header file of Shape class
 *  @author: Jiayuan Li
 *  @version: 3.4.2 Dec 29, 2019
 *      3.4.2: implementing shape class
 */

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <stdlib.h>

namespace JIAYUAN
{
    namespace CAD
    {
        class Shape
        {
        public:
            Shape();                    // default constructor
            Shape(const Shape& other);  // copy constructor
            virtual ~Shape();           // destructor

            Shape& operator = (const Shape& other); // overloading assign operator

            std::string ToString() const;   // return the description of the class
            int ID() const;             // return the id of the class

        private:
            int m_id;       // data member for id
        };
    }
}

#endif