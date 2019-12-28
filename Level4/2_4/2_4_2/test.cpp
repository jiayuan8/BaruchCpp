/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    Point test_point_1 = Point(1, 1);
    cout << "----------------test for Point----------------\n";
    cout << "point a: " << test_point_1 << endl;

    Circle test_circle_2 = Circle(Point(2,5), 7);
    cout << "----------------test for Circle----------------\n";
    cout << "circle a: " << test_circle_2 << endl;

    Line test_line_2 = Line(Point(2.33, 2.33), Point(6.66, 6.66));
    cout << "----------------test for Line----------------\n";
    cout << "line a: " << test_line_2 << endl;

    return 0;
}