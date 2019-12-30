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
    Shape* shapes[3]; 
    shapes[0] = new Shape; 
    shapes[1] = new Point; 
    shapes[2] = new Line;
    
    for (int i=0; i!=3; i++) 
        delete shapes[i];
    /* A: Now, the ID is printed with every point, line and circle :) */

    return 0;
}