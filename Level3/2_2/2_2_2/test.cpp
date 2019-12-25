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
    double x_input;     // the input value for x
    double y_input;     // the input value for y

    // get user input
    cout << "Please input x and y coordinate as '<x> <y>':";
    if (!(cin >> x_input >> y_input))
    {
        cout << "Input Error: Please check your input format.\n";
        return 0;
    }

    // construct point
    Point test_point = Point();

    // set the point coordinate
    test_point.SetX(x_input);
    test_point.SetY(y_input);

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
    cout << "the distance to (2,3) is: " << test_point.Distance(test_point_2) << endl;

    return 0;
}