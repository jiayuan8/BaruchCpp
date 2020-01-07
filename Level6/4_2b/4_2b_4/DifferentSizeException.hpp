/*  OutOfBoundsException.hpp
 *  ------------------------------------------
 *  @description: header file of OutOfBoundsException class
 *  @author: Jiayuan Li
 *  @version: 3.6.2 Dec 30th 2019
 */

#ifndef DIFFSIZEEXCEPTION_HPP
#define DIFFSIZEEXCEPTION_HPP

#include <iostream>
#include <sstream>
#include "ArrayException.hpp"

namespace JIAYUAN
{
    namespace Exception
    {

        class DifferentSizeException: public ArrayException
        {
        public:
            DifferentSizeException();     // constructor
            DifferentSizeException(int index1, int index2);    // constructor with index
            ~DifferentSizeException();    // destructor

            std::string GetMessage() const; // out of bounds index

        private:
            int m_index_1;
            int m_index_2;

        };

        inline DifferentSizeException::DifferentSizeException() 
            : ArrayException(), m_index_1(0), m_index_2(0)
        {
            // default constructor
        }

        inline DifferentSizeException::DifferentSizeException(int index1, int index2)
            : ArrayException(), m_index_1(index1), m_index_2(index2)
        {
            // constructor with parameters
        }

        inline DifferentSizeException::~DifferentSizeException() {}

        inline std::string DifferentSizeException::GetMessage() const
        {
            std::stringstream res;
            res << "DifferentSizeException: size1(" << m_index_1 << ") and size2(" << m_index_2 << ") are different!";
            return res.str();
        }
    }
}

#endif