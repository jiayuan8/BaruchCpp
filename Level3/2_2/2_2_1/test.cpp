/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 24, 2019
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
    
    return 0;
}