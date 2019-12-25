/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 24, 2019
 */

#include "Point.hpp"
#include <string.h>

using std::to_string;

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
    return "Point(" + to_string(m_x) + ", " + to_string(m_y) + ")";
}