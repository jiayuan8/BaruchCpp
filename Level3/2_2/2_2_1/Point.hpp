/*  Point.h
 *  ------------------------------------------
 *  @description: header file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 24, 2019
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
using std::string;

class Point
{
public:
    Point();            // constructor
    ~Point();           // destruntor
    double GetX();      // function returns x coordinate of the point
    double GetY();      // function returns y coordinate of the point
    void SetX(double new_x);    // function set x coordinate of the point
    void SetY(double new_y);    // function set y coordinate of the point
    string ToString();  // function that return a description of the point

private:
    double m_x;         // the x coordinate of the point
    double m_y;         // the y coordinate of the point
    
};

#endif