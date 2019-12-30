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

    cout<<s.ToString()<<endl; 
    cout<<p.ToString()<<endl; 
    cout<<l.ToString()<<endl;

    cout<<"Shape ID: "<<s.ID()<<endl; 
    cout<<"Point ID: "<<p.ID()<<endl; 
    /* Q: Does this work? */
    /* A: Yes, this works.*/
    cout<<"Line ID: "<<l.ID()<<endl;
    /* Q: Does this work? */
    /* A: Yes, this works.*/

    Shape* sp;
    sp=&p; 
    /* Q: Point in a shape variable. Possible? */
    /* A: Yes, it is possible. It compiles with no error. */
    cout<<sp->ToString()<<endl;
    /* Q: What is printed? */
    /* A: "ID: 282475249" is printed. It calls the ToString() in Shape class */

    Point p2;
    p2=p;
    cout<<p2<<", "<<p2.ID()<<endl;
    /* Q: Is the ID copied if you do not call the base class assignment in point? */
    /* A: Yes, since the assignment operator of Point class (derived) will call the 
     * assign operator in Shape class (base)
     */

    return 0;
}