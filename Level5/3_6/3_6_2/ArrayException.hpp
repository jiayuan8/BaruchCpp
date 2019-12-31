/*  ArrayException.hpp
 *  ------------------------------------------
 *  @description: header file of ArrayException class
 *  @author: Jiayuan Li
 *  @version: 3.6.2 Dec 30th 2019
 */

#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

#include <iostream>

class ArrayException
{
public:
    ArrayException();       // default constructor
    virtual ~ArrayException();      // virtual destructor

    virtual std::string GetMessage() const = 0;     // abstruct GetMessage Function

private:

};

inline ArrayException::ArrayException() {}
inline ArrayException::~ArrayException() {}

#endif