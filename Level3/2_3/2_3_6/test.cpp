/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Circle.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{   
    cout << "*** test default constructor***\n";
    Circle new_circle;

    cout << "*** test getter functions***\n";
    cout << "center point : " << new_circle.CenterPoint().ToString() << endl;
    cout << "radius       : " << new_circle.Radius() << endl;
    cout << "diameter     : " << new_circle.Diameter() << endl;
    cout << "area         : " << new_circle.Area() << endl;
    cout << "circumference: " << new_circle.Circumference() << endl;

    cout << "\n*** test setter functions***\n";
    new_circle.CenterPoint(Point(1, 2));
    new_circle.Radius(6);

    cout << "*** test ToString()***\n";
    cout << new_circle.ToString() << endl;

    cout << "\n*** test copy constructor***\n";
    Circle new_circle2 = Circle(new_circle);
    cout << new_circle2.ToString() << endl;

    cout << "\n*** test constructor by point***\n";
    Circle new_circle3 = Circle(Point(5, 5), 99);
    cout << new_circle3.ToString() << endl;

    return 0;
}