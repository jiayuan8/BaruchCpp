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
    Shape s;
    Point p(10, 20);

    cout<<s.ToString()<<endl; 
    cout<<p.ToString()<<endl; 

    cout<<"Shape ID: "<<s.ID()<<endl; 
    cout<<"Point ID: "<<p.ID()<<endl; 

    Shape* sp;
    sp=&p; 
    cout<<sp->ToString()<<endl;
    /* Q: What is printed? */
    /* A: "ID: 282475249" is printed. It calls the ToString() in Shape class */

    return 0;
}