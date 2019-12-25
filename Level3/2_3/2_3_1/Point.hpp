/*  Point.h
 *  ------------------------------------------
 *  @description: header file of Point class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
using std::string;

class Point
{
public:
    // for 2.2.1
    Point();            // constructor
    ~Point();           // destruntor
    double GetX();      // function returns x coordinate of the point
    double GetY();      // function returns y coordinate of the point
    void SetX(double new_x);    // function set x coordinate of the point
    void SetY(double new_y);    // function set y coordinate of the point
    string ToString();  // function that return a description of the point

    // for 2.2.2
    double DistanceOrigin();    // calculate the distance to origin
    double Distance(Point p);   // calculate the distance between two points

    // for 2.3.1
    Point(double x, double y);  // new constructor
    Point(const Point& other);  // copy constructor

private:
    double m_x;         // the x coordinate of the point
    double m_y;         // the y coordinate of the point
    
};

#endif