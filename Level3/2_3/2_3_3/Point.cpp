/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class, implement function overloading
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include "Point.hpp"
#include <string.h>
#include <cmath>

using std::cout;
using std::endl;
using std::to_string;
using std::sqrt;

Point::Point(): m_x(0), m_y(0)
{
    // default constructor
    cout << "***The default constructor has been called***" << endl;
}

Point::~Point()
{
    // default destructor
    cout << "***The default destructor has been called***" << endl;
}

double Point::X()
{
    return m_x;
}

double Point::Y()
{
    return m_y;
}

void Point::X(double new_x)
{
    m_x = new_x;
}

void Point::Y(double new_y)
{
    m_y = new_y;
}

string Point::ToString()
{
    return "Point(" + to_string(m_x) + ", " + to_string(m_y) + ")";
}

double Point::Distance()
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p)
{
    double x_rel = m_x - p.m_x; // relative distance of x
    double y_rel = m_y - p.m_y; // relative distance of y
    return sqrt(y_rel * y_rel + x_rel * x_rel);
}

Point::Point(double x, double y)
{
    cout << "***The new constructor has been called!***" << endl;
    m_x = x;
    m_y = y;
}

Point::Point(const Point& other)
{
    cout << "***The copy constructor has been called!***" << endl;
    m_x = other.m_x;
    m_y = other.m_y;
}