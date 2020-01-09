/* CheckObj.cpp
 * ----------------------------------------
 * @description: source file for the checker class
 * @author: Jiayuan Li
 * @version: 1.0 Jan, 8th 2020
 */

#ifndef CHECKOBJ_CPP
#define CHECKOBJ_CPP

#include "checkObj.hpp"

template <typename T>
CheckObj<T>::CheckObj(): m_bound(0)
{
    // default constructor
}

template <typename T>
CheckObj<T>::CheckObj(double bound): m_bound(bound)
{
    // constructor with parameter
}

template <typename T>
CheckObj<T>::CheckObj(const CheckObj<T>& other): m_bound(other.m_bound)
{
    // copy constructor
}

template <typename T>
CheckObj<T>::~CheckObj()
{
    // destructor
}

template <typename T>
bool CheckObj<T>::operator () (double input)
{   // check if the input is smaller then the bound
    return input < m_bound;
}

#endif