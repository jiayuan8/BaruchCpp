/* main.cpp
 * ----------------------------------------------
 * @description: test functionality of shared_ptr
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */


#include <iostream>
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "visitor.hpp"

using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

typedef boost::variant<Point, Line, Circle> ShapeType;

// helper function declaration
ShapeType return_shape();   // function that receives input and retuuns cooresponding shape

int main()
{
    ShapeType test_variant = return_shape();
    // print the varint
    std::cout << test_variant << std::endl;

    try
    {
        Line test_line = boost::get<Line>(test_variant);
    }
    catch(const boost::bad_get & e)
    {
        std::cerr << e.what() << '\n';
    }

    // test visitor
    visitor test_visitor(1, 3);                         // create visitor
    boost::apply_visitor(test_visitor, test_variant);   // using the apply_visitor
    std::cout << test_variant << std::endl;             // print the result
    
    return 0;
}

// function implementation
ShapeType return_shape()
{
    std::cout << "Input the type of shape you want (1 for point, 2 for line, 3 for circle, default for point):" << std::endl;
    int input_type;
    if (std::cin >> input_type)
    {
        if (input_type == 1)
        {
            return ShapeType(Point());
        }
        else if (input_type == 2)
        {
            return ShapeType(Line());
        }
        else if (input_type == 3)
        {
            return ShapeType(Circle());
        }
        else
        {
            return ShapeType(Point());
        }
    }
    else
    {
        return ShapeType(Point());
    }
}