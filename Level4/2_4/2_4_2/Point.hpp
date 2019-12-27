/*  Point.hpp
 *  ------------------------------------------
 *  @description: header file of Point class, implement const function
 *  @author: Jiayuan Li
 *  @version: 1.1 Dec 25, 2019
 *      1.1: line getter return by reference, setter set the entire object
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
using std::string;
using std::ostream;

class Point
{
public:

    Point();            // constructor
    ~Point();           // destruntor
    double X() const;   // function returns x coordinate of the point
    double Y() const;   // function returns y coordinate of the point
    
    void X(double new_x) 
    { // function set x coordinate of the point
        m_x = new_x;
    }
    void Y(double new_y)
    { // function set y coordinate of the point
        m_y = new_y;
    }
    
    string ToString() const; // function that return a description of the point

    double Distance() const; // calculate the distance to origin
    double Distance(const Point& p) const;  // calculate the distance between two points

    Point(double x, double y);  // new constructor
    Point(const Point& other);  // copy constructor

    // operator overloading
    Point operator - () const;                  // Negate the coordinates.
    Point operator * (double factor) const;     // Scale the coordinates.
    Point operator + (const Point& p) const;    // Add coordinates.
    bool operator == (const Point& p) const;    // Equally compare operator.
    Point& operator = (const Point& source);    // Assignment operator.
    Point& operator *= (double factor);         // Scale the coordinates & assign.

private:
    double m_x;         // the x coordinate of the point
    double m_y;         // the y coordinate of the point
    
};

inline double Point::X() const
{
    return m_x;
}

inline double Point::Y() const
{
    return m_y;
}

ostream& operator << (ostream& os, const Point& p);

#endif