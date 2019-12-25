/*  Point.h
 *  ------------------------------------------
 *  @description: header file of Point class, implement function overloading
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

    Point();            // constructor
    ~Point();           // destruntor
    double X();         // function returns x coordinate of the point
    double Y();         // function returns y coordinate of the point
    void X(double new_x);    // function set x coordinate of the point
    void Y(double new_y);    // function set y coordinate of the point
    string ToString();  // function that return a description of the point

    double Distance();    // calculate the distance to origin
    double Distance(const Point& p);   // calculate the distance between two points

    Point(double x, double y);  // new constructor
    Point(const Point& other);  // copy constructor

private:
    double m_x;         // the x coordinate of the point
    double m_y;         // the y coordinate of the point
    
};

#endif