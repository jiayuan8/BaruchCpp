/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Line.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{   
    cout << "*** test default constructor***\n";
    Line new_line;

    cout << "*** test getter functions***\n";
    cout << "start point: " << new_line.P1().ToString() << endl;
    cout << "end point: " << new_line.P2().ToString() << endl;

    cout << "\n*** test setter functions***\n";
    new_line.P1(Point(1, 2));
    new_line.P2(Point(4, 6));

    cout << "*** test Length() and ToString()***\n";
    cout << "length: " << new_line.Length() << endl;
    cout << new_line.ToString() << endl;

    cout << "\n*** test copy constructor***\n";
    Line new_line2 = Line(new_line);
    cout << new_line2.ToString() << endl;

    cout << "\n*** test constructor by point***\n";
    Line new_line3 = Line(Point(0, 0), Point(5, 12));
    cout << new_line3.ToString() << endl;

    return 0;
}