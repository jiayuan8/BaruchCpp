/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    // *** compiler error ***
    // Point p(1.0, 1.0);
    // if (p == 1.0) 
    //     cout<<"Equal!"<<endl; 
    // else 
    //     cout<<"Not equal"<<endl;

    Point p(1.0, 1.0);
    if (p == (Point)1.0) 
        cout<<"Equal!"<<endl; 
    else 
        cout<<"Not equal"<<endl;

    return 0;
}