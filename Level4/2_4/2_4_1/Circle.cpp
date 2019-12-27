/*  Circle.cpp
 *  ------------------------------------------
 *  @description: source file of Circle class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#define _USE_MATH_DEFINES

#include "Circle.hpp"
#include <sstream>
#include <cmath>

using std::stringstream;

Circle::Circle(): p_center(Point(0, 0)), m_radius(1)
{
    // default constructor, initialize with point (0,0) and radius 1
}

Circle::Circle(const Point& center, double radius)
:p_center(center), m_radius(radius)
{
    // constructor with parameters
}

Circle::Circle(const Circle& other)
:p_center(other.p_center), m_radius(other.m_radius)
{
    // copy constructor
}

Circle::~Circle()
{
    // destructor
}

void Circle::CenterPoint(const Point& other)
{
    // setter for center point
    p_center = other;
}

void Circle::Radius(double radius)
{
    // setter for center point
    m_radius = radius;
}

const Point& Circle::CenterPoint() const
{
    // return center point
    return p_center;
}

double Circle::Radius() const
{
    // return radius
    return m_radius;
}

double Circle::Diameter() const
{
    // return the diameter
    return 2 * m_radius;
}

double Circle::Area() const
{
    // return the area
    return M_PI * m_radius * m_radius;
}

double Circle::Circumference() const
{
    // return the Circumference
    return M_PI * m_radius * 2;
}

string Circle::ToString() const
{
    // return the description
    stringstream res;
    res << "Circle info: \n";
    res << "center point: " << p_center.ToString() << "\n";
    res << "radius: " << m_radius << "\n";
    return res.str();
}