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

    // construct point using the new constructor
    Point test_point = Point(x_input, y_input);
    Point test_point_2 = Point();
    cout << "*** test inline setter functions ***" << endl;
    test_point_2.X(2);
    test_point_2.Y(3);

    // print the description
    cout << test_point.ToString() << endl;

    // print by getter funtion
    cout << "*** test inline getter functions ***" << endl;
    cout << "the x coordinate of the point is: " << test_point.X() << endl;
    cout << "the y coordinate of the point is: " << test_point.Y() << endl;
    
    return 0;
}