/*  Shape.cpp
 *  ------------------------------------------
 *  @description: source file of Shape class
 *  @author: Jiayuan Li
 *  @version: 3.4.2 Dec 29, 2019
 *      3.4.2: implementing shape class
 */


#include "Shape.hpp"
#include "sstream"

namespace JIAYUAN
{
    namespace CAD
    {
        Shape::Shape()
            : m_id(rand())
        {
            // default constructor   
        }

        Shape::Shape(const Shape& other)
            : m_id(other.m_id)
        {
            // copy constructor
        }

        Shape::~Shape()
        {
            // destructor
        }

        Shape& Shape::operator = (const Shape& other)
        {
            // avoid self copying
            if (this == &other)
            {
                return *this;
            }
            m_id = other.m_id;
            return *this;
        }

        std::string Shape::ToString() const
        {
            std::stringstream res;
            res << "ID: " << m_id;
            return res.str();
        }

        int Shape::ID() const
        {
            return m_id;
        }
    }
}