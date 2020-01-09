/* CheckObj.hpp
 * ----------------------------------------
 * @description: header file for the checker class
 * @author: Jiayuan Li
 * @version: 1.0 Jan, 8th 2020
 */

#ifndef CHECKOBJ_HPP
#define CHECKOBJ_HPP

template <typename T>
class CheckObj
{
public:
    // constructors
    CheckObj();             //default constructor
    CheckObj(double bound); // constructor by parameter
    CheckObj(const CheckObj<T>& other); // copy constructor

    // destructor
    ~CheckObj();

    // overloading () operator
    bool operator () (double input);

private:
    double m_bound;
};

#ifndef CHECKOBJ_CPP
#include "checkObj.cpp"
#endif

#endif