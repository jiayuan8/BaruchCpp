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

    /* Before adding the "virtual" to the destructor, 
     * only the destructor of Shape class will be called
     * calls for destructors of Line and Point are missing
     */

    /* After adding the "virtual" to the destructor, 
     * all the proper dectructors will be called 
     * (include the destructor for Point, Line and Shape)
     */

    return 0;
}