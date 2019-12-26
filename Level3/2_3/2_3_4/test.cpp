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
    const Point cp(1.5, 3.9); 
    // 1. compiler error: try to change a const object
    // cp.X(0.3);

    // after change to const function
    cout << "The x coordinate of the const point is: " << cp.X() << endl;
    cout << "The y coordinate of the const point is: " << cp.Y() << endl;
    cout << "The dist to (0, 0) is: " << cp.Distance() << endl;
    cout << "The dist to (1, 1) is: " << cp.Distance(Point(1,1)) << endl;

    return 0;
}