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
    Point test_point_2 = Point(0, 0);

    cout << "----------------test for Point----------------\n";
    cout << "point a: " << test_point_1.ToString() << endl;
    cout << "point b: " << test_point_2.ToString() << endl;
    cout << "test case 1 -- -a    : " << (- test_point_1).ToString() << endl;
    cout << "test case 2 -- a * 2 : " << (test_point_1 * 2.).ToString() << endl;
    cout << "test case 3 -- a + b : " << (test_point_1 + test_point_2).ToString() << endl;
    cout << "test case 4 -- a == b: " << ((test_point_1 == test_point_2) ? "true" : "false") << endl;
    cout << "test case 5 -- a == a: " << ((test_point_1 == test_point_1) ? "true" : "false") << endl;
    test_point_2 = test_point_1;
    cout << "test case 6 -- b = a : " << test_point_2.ToString() << endl;
    cout << "test case 7 -- a *= 2: " << (test_point_1 *= 2).ToString() << endl;

    Circle test_circle_1 = Circle();
    Circle test_circle_2 = Circle(Point(2,5), 7);
    cout << "----------------test for Circle----------------\n";
    cout << "***circle a: \n" << test_circle_1.ToString() << endl;
    cout << "***circle b: \n" << test_circle_2.ToString() << endl;
    test_circle_1 = test_circle_2;
    cout << "***circle a (after assign): \n" << test_circle_1.ToString() << endl;
    cout << "***circle b (after assign): \n" << test_circle_2.ToString() << endl;

    Line test_line_1 = Line();
    Line test_line_2 = Line(Point(2.33, 2.33), Point(6.66, 6.66));
    cout << "----------------test for Circle----------------\n";
    cout << "***line a: \n" << test_line_1.ToString() << endl;
    cout << "***line b: \n" << test_line_2.ToString() << endl;
    test_line_1 = test_line_2;
    cout << "***line a (after assign): \n" << test_line_1.ToString() << endl;
    cout << "***line b (after assign): \n" << test_line_2.ToString() << endl;

    return 0;
}