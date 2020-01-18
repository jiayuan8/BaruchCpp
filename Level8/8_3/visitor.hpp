/* visitor.hpp
 * ----------------------------------------------
 * @description: header file of visitor class
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */

#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <boost/variant/static_visitor.hpp>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

class visitor: public boost::static_visitor<void>
{
public:
    // constructors
    visitor();      // default constructor
    visitor(double x_offset, double y_offset);      // constructor with paramenters
    visitor(const visitor& other);      // copy constructor

    ~visitor();     // destructor

    visitor& operator = (const visitor& other); // overloading assign operator

    // function overloading for () operator
    void operator () (JIAYUAN::CAD::Point& p) const;
    void operator () (JIAYUAN::CAD::Line& p) const;
    void operator () (JIAYUAN::CAD::Circle& p) const;

private:
    // private members
    double m_dx;  // offset for x
    double m_dy;  // offset for y

};

#endif