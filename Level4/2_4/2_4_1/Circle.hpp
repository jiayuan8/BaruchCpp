/*  Circle.hpp
 *  ------------------------------------------
 *  @description: header file of Circle class
 *  @author: Jiayuan Li
 *  @version: 1.1 Dec 27, 2019
 *      1.1: getter return by const reference, setter using operator = 
 */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include "Point.hpp"

using std::string;

class Circle{
public:
    Circle();                       // default constructor
    Circle(const Point& center, double radius);     // constructor with point the radius
    Circle(const Circle& other);    // copy constructor
    ~Circle();                      // destructor

    // setter functions
    void CenterPoint(const Point& other);   // set the center point
    void Radius(double radius);             // set the radius

    // getter functions
    const Point& CenterPoint() const;          // get the center point of the circle
    double Radius() const;              // get the radius of the circle

    // functions returns the properties of the class
    double Diameter() const;            // get the diameter of the circle
    double Area() const;                // get the area of the circle
    double Circumference() const;       // get the circumference of the circle
    
    // function returns the description of the circle
    string ToString() const;            // return the description of the circle

private:
    Point p_center;
    double m_radius;

};

#endif