/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;

int main()
{
    Point p(10, 20);

    Shape* sp;
    sp=&p; 
    cout<<sp->ToString()<<endl;
    /* Q: What is printed? */
    /* A: "Point(10, 20)" is printed. It calls the ToString() in Point class */

    return 0;
}