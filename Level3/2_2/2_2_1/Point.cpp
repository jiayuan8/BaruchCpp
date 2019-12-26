/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 24, 2019
 */

#include "Point.hpp"
#include <sstream>

using std::stringstream;

Point::Point(): m_x(0), m_y(0)
{
    // default constructor
}

Point::~Point()
{
    // default destructor
}

double Point::GetX()
{
    return m_x;
}

double Point::GetY()
{
    return m_y;
}

void Point::SetX(double new_x)
{
    m_x = new_x;
}

void Point::SetY(double new_y)
{
    m_y = new_y;
}

string Point::ToString()
{
    stringstream res;
    res << "Point(" << m_x << ", " << m_y << ")";
    return res.str();
}