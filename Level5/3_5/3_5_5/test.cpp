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

    /* 
     * Yes, the Point() function in the Shape class prints the right 
     * output even when Point() and Line() do not have Point function
     */

    // create line and point object
    Line test_line;
    Point test_point;
    Circle test_circle;

    // test calling the print function
    test_line.Print();
    cout << endl;
    test_point.Print();
    cout << endl;
    test_circle.Print();
    cout << endl;

    return 0;
}