/*  Circle.cpp
 *  ------------------------------------------
 *  @description: source file of Circle class
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#define _USE_MATH_DEFINES

#include "Circle.hpp"
#include <sstream>
#include <cmath>

using std::endl;
using std::stringstream;
using std::string;

namespace JIAYUAN
{
    namespace CAD
    {
        Circle::Circle()
            : Shape(), p_center(Point(0, 0)), m_radius(1)
        {
            // default constructor, initialize with point (0,0) and radius 1
        }

        Circle::Circle(const Point& center, double radius)
            : Shape(), p_center(center), m_radius(radius)
        {
            // constructor with parameters
        }

        Circle::Circle(const Circle& other)
            : Shape(other), p_center(other.p_center), m_radius(other.m_radius)
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
            string s = Shape::ToString();
            res << "[Center Point: " << p_center.ToString();
            res << ", Radius: " << m_radius << ", " << s << "]";
            return res.str();
        }

        void Circle::Draw() const
        {
            std::cout << "*** Drawing ***" << ToString() << std::endl;
        }

        Circle& Circle::operator = (const Circle& source)
        {
            // avoid self copying
            if (this == &source)
            {
                return *this;
            }

            // call base class assign operator
            Shape::operator = (source);

            p_center = source.CenterPoint();
            m_radius = source.Radius();
            return *this;
        }

        ostream& operator << (ostream& os, const Circle& c)
        {
            os << "[Center Point: " << c.p_center;
            os << ", Radius: " << c.m_radius << "]";
            return os;
        }
    }
}