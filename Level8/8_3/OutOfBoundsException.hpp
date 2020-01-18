/*  OutOfBoundsException.hpp
 *  ------------------------------------------
 *  @description: header file of OutOfBoundsException class
 *  @author: Jiayuan Li
 *  @version: 3.6.2 Dec 30th 2019
 */

#ifndef OUTOFBOUNDEXCEPTION_HPP
#define OUTOFBOUNDEXCEPTION_HPP

#include <iostream>
#include <sstream>
#include "ArrayException.hpp"

namespace JIAYUAN
{
    namespace Exception
    {
        class OutOfBoundsException: public ArrayException
        {
        public:
            OutOfBoundsException();     // constructor
            OutOfBoundsException(int index);    // constructor with index
            ~OutOfBoundsException();    // destructor

            std::string GetMessage() const; // out of bounds index

        private:
            int m_index;

        };

        inline OutOfBoundsException::OutOfBoundsException() 
            : ArrayException(), m_index(0)
        {
            // default constructor
        }

        inline OutOfBoundsException::OutOfBoundsException(int index)
            : ArrayException(), m_index(index) 
        {
            // constructor with parameters
        }

        inline OutOfBoundsException::~OutOfBoundsException() {}

        inline std::string OutOfBoundsException::GetMessage() const
        {
            std::stringstream res;
            res << "OutOfBoundsException: The given index (" << m_index << ") is out of bound!";
            return res.str();
        }
    }
}

#endif