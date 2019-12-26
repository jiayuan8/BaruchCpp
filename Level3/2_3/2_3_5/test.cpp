/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Line
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

    double x_1, y_1, x_2, y_2;
    cout <<"please input x1, y1, x2, y2 as '<x1> <y1> <x2> <y2>': ";
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    cout << "\n*** test setter functions***\n";
    new_line.P1(Point(x_1, y_1));
    new_line.P2(Point(x_2, y_2));

    cout << "*** test Length() and ToString()***\n";
    cout << "length: " << new_line.Length() << endl;
    cout << new_line.ToString() << endl;

    cout << "\n*** test copy constructor***\n";
    Line new_line2 = Line(new_line);
    cout << new_line2.ToString() << endl;

    cout << "\n*** test constructor by point***\n";
    Line new_line3 = Line(Point(x_1, y_1), Point(x_2, y_2));
    cout << new_line3.ToString() << endl;

    return 0;
}