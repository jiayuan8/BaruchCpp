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
    /* The Draw() function in Shape needs to be pure virtual */
    
    // Shape test_shape;

    /* We cannot create an instance of Shape class, since
     * Shape is an abstract class. 
     * Doing so will result in compiler error
     */

    Shape* shapes[10];
    shapes[0] = new Line;
    shapes[1] = new Point;
    shapes[2] = new Circle;
    shapes[3] = new Line;
    shapes[4] = new Point;
    shapes[5] = new Circle;
    shapes[6] = new Line;
    shapes[7] = new Point;
    shapes[8] = new Circle;
    shapes[9] =new Line(Point(1.0, 2.5), Point(3.4, 5.2));

    for (int i=0; i!=10; i++) shapes[i]->Draw(); 
    for (int i=0; i!=10; i++) delete shapes[i];

    return 0;
}