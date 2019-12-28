/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    // the full namespace for Point class
    JIAYUAN::CAD::Point test_point1;
    JIAYUAN::CAD::Point test_point2(1.5, 9);
    JIAYUAN::CAD::Point test_point3(test_point1);

    // using declaration for using a single class
    using JIAYUAN::CAD::Line;
    Line test_line1;
    Line test_line2(test_point1, test_point2);
    Line test_line3(test_line1);

    // using declaration for a complete namespace
    using namespace JIAYUAN::Containers;
    Array test_arr1;
    Array test_arr2(25);
    Array test_arr3(test_arr1);

    // using the Circle class by creating a shorter alias for the YourName::CAD 
    namespace CADC = JIAYUAN::CAD;
    CADC::Circle test_circle1;
    CADC::Circle test_circle2(test_point1, 5);
    CADC::Circle test_circle3(test_circle1);

    return 0;
}