/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 27, 2019
 */

#include "Point.hpp"
#include <sstream>
#include <cmath>

using std::endl;
using std::stringstream;
using std::sqrt;

Point::Point(): m_x(0), m_y(0)
{
    // default constructor
    // cout << "***The default constructor has been called***" << endl;
}

Point::~Point()
{
    // default destructor
    // cout << "***The default destructor has been called***" << endl;
}

string Point::ToString() const
{
    stringstream res;
    res << "Point(" << m_x << ", " << m_y << + ")";
    return res.str();
}

double Point::Distance() const
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p) const
{
    double x_rel = m_x - p.m_x; // relative distance of x
    double y_rel = m_y - p.m_y; // relative distance of y
    return sqrt(y_rel * y_rel + x_rel * x_rel);
}

Point::Point(double x, double y)
{
    // cout << "***The new constructor has been called!***" << endl;
    m_x = x;
    m_y = y;
}

Point::Point(const Point& other)
{
    // cout << "***The copy constructor has been called!***" << endl;
    m_x = other.m_x;
    m_y = other.m_y;
}

Point Point::operator - () const
{   // inverse both the coordinates
    return Point( - m_x, - m_y);
}

Point Point::operator * (double factor) const
{
    return Point( factor * m_x, factor * m_y);
}

Point Point::operator + (const Point& p) const
{
    return Point( m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator == (const Point& p) const
{
    return (m_x == p.m_x) && (m_y == p.m_y);
}

Point& Point::operator = (const Point& source)
{
    // avoid doing assign to itself
    if (this == &source)
    {
        return *this;
    }

    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

Point& Point::operator *= (double factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

ostream& operator << (ostream& os, const Point& p)
{
    os << "Point(" << p.m_x << ", " << p.m_y << + ")";
    return os;
}
