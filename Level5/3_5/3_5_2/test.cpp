/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;

int main()
{
    Shape s;
    Point p(10, 20);
    Line l(Point(1,2), Point(3, 4));
    Circle c;

    cout << s.ToString() << endl; 
    cout << p.ToString() << endl; 
    cout << l.ToString() << endl;
    cout << c.ToString() << endl;
    /* A: Now, the ID is printed with every point, line and circle :) */
    

    return 0;
}