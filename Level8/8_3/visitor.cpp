/* visitor.cpp
 * ----------------------------------------------
 * @description: source file of visitor class
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */

#include "visitor.hpp"

using namespace JIAYUAN::CAD;

visitor::visitor()
: boost::static_visitor<void>(), m_dx(0), m_dy(0)
{
    // default constructor
}

visitor::visitor(double x_offset, double y_offset)
: boost::static_visitor<void>(), m_dx(x_offset), m_dy(y_offset)
{
    // constructor with parameter
}

visitor::visitor(const visitor& other)
: boost::static_visitor<void>(), m_dx(other.m_dx), m_dy(other.m_dy)
{
    // copy constructor
}

visitor::~visitor()
{
    // destructor
}

visitor& visitor::operator = (const visitor& other)
{
    // preclude self copying
    if (this == &other)
    {
        return *this;
    }

    m_dx = other.m_dx;
    m_dy = other.m_dy;
    return *this;
}

void visitor::operator () (JIAYUAN::CAD::Point& p) const
{
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void visitor::operator () (JIAYUAN::CAD::Line& l) const
{
    l.P1(Point(l.P1().X() + m_dx, l.P1().Y() + m_dy));
    l.P2(Point(l.P2().X() + m_dx, l.P2().Y() + m_dy));
}

void visitor::operator () (JIAYUAN::CAD::Circle& c) const
{
    const Point& pc = c.CenterPoint();
    c.CenterPoint(Point(pc.X() + m_dx, pc.Y() + m_dy));
}