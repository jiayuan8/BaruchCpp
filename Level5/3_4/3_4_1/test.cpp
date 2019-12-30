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
    Line l;
    /* before implemeting colon syntax:
     * 4 constructor calls for Point class
     *      (2 default constructor, 2 constructor by parameters)
     * 2 assignment calls for Point class
     * 4 destructor calls for Point class
     */

    /* after implemeting colon syntax:
     * 2 constructor calls for Point class
     * 0 assignment calls for Point class
     * 2 destructor calls for Point class
     */

    /* Conclusion: the calls are less than before */

    return 0;
}