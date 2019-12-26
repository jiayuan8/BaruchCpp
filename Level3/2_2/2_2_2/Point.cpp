/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include "Point.hpp"
#include <sstream>
#include <cmath>

using std::stringstream;
using std::sqrt;

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

double Point::DistanceOrigin()
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(Point p)
{
    double x_rel = m_x - p.m_x; // relative distance of x
    double y_rel = m_y - p.m_y; // relative distance of y
    return sqrt(y_rel * y_rel + x_rel * x_rel);
}