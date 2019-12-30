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
    Shape* shapes[10];
    shapes[0] = new Line;
    shapes[1] = new Point;
    shapes[2] = new Circle;
    shapes[9] =new Line(Point(1.0, 2.5), Point(3.4, 5.2));
    for (int i=0; i!=10; i++) shapes[i]->Draw(); 
    for (int i=0; i!=10; i++) delete shapes[i];

    return 0;
}