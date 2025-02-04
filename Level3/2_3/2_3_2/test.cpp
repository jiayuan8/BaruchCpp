/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    /* 
     * Before adding the copy constructor:
     * one constructor has been called!
     * one copy constructor has been called!
     * two destructor has been called!
     * The number of calls for constructors has been reduced by 1
     */

    double x_input;     // the input value for x
    double y_input;     // the input value for y

    // get user input
    cout << "Please input x and y coordinate as '<x> <y>':";
    if (!(cin >> x_input >> y_input))
    {
        cout << "Input Error: Please check your input format.\n";
        return 0;
    }

    // construct point using the new constructor
    Point test_point = Point(x_input, y_input);

    // print the description
    cout << test_point.ToString() << endl;

    // print by getter funtion
    cout << "the x coordinate of the point is: " << test_point.GetX() << endl;
    cout << "the y coordinate of the point is: " << test_point.GetY() << endl;

    // print the distance to origin
    cout << "the distance to origin is: " << test_point.DistanceOrigin() << endl;

    // print the distance to another point
    Point test_point_2 = Point();
    test_point_2.SetX(2);
    test_point_2.SetY(3);
    double dist = test_point.Distance(test_point_2);
    cout << "the distance to (2,3) is: " << dist << endl;
    
    return 0;
}