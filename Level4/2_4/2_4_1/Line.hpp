/*  Line.hpp
 *  ------------------------------------------
 *  @description: header file of Line class
 *  @author: Jiayuan Li
 *  @version: 1.1 Dec 27, 2019
 *      1.1 getter function returning const reference, add assign operator
 */

#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include "Point.hpp"

using std::string;

class Line
{
public:
    // constructors and destructor
    Line();                         // default constructor
    Line(const Point& start, const Point & end);    // constructor with two point
    Line(const Line& other);        // copy constructor
    ~Line();                        // destructor

    // getter and setter functions
    const Point& P1() const;               // getter function for start point
    const Point& P2() const;               // getter function for end point
    void P1(const Point& other);    // setter function for start point
    void P2(const Point& other);    // setter function for end point

    // functions return the properties of the line
    string ToString() const;        // returns description of the line
    double Length() const;          // returns the length of the line

    Line& operator = (const Line& source);

private:
    // start point and end point
    Point p_start;
    Point p_end;
};

#endif