/*  Point.cpp
 *  ------------------------------------------
 *  @description: source file of Point class
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include "Point.hpp"
#include <sstream>
#include <cmath>

using std::stringstream;
using std::sqrt;

namespace JIAYUAN
{
    namespace CAD
    {
        Point::Point()
            : Shape(), m_x(0), m_y(0)
        {
            // default constructor
        }

        Point::Point(double x, double y)
            : Shape(), m_x(x), m_y(y)
        {
            // constructor with 2 parameters
        }

        Point::Point(double x)
            : Shape(), m_x(x), m_y(x)
        {
            // constructor with 1 parameters
        }

        Point::Point(const Point& other)
            : Shape(other), m_x(other.m_x), m_y(other.m_y)
        {
            // copy constructor
        }

        Point::~Point()
        {
            // destructor
            // std::cout << "*** The destructor for point has been called ***" << std::endl;
            std::cout << "Point destructor called!" << std::endl;
        }

        string Point::ToString() const
        {
            stringstream res;
            string s = Shape::ToString();
            res << "[Point(" << m_x << ", " << m_y << + "), " << s << "]";
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

        void Point::Draw() const
        {
            std::cout << "*** Drawing ***" << ToString() << std::endl;
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

            // call base class assign operator
            Shape::operator = (source);

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
    }
}