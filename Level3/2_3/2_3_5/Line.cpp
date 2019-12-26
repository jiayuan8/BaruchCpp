/*  Line.cpp
 *  ------------------------------------------
 *  @description: source file of Line class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include "Line.hpp"
#include <cstring>

using std::string;
using std::to_string;

Line::Line()
{
    // default constructor for Line:
    // set both point to 0
    p_start = Point(0, 0);
    p_end = Point(0, 0);
}

Line::Line(const Point& start, const Point & end)
{
    // constructor for Line
    p_start = Point(start);
    p_end = Point(end);
}

Line::Line(const Line& other)
{
    // copy constructor for Line
    p_start = Point(other.p_start);
    p_end = Point(other.p_end);
}

Line::~Line()
{
    // destructor for Line
}

Point Line::P1() const
{
    // return the start point
    return p_start;
}

Point Line::P2() const
{
    // return the end point
    return p_end;
}

void Line::P1(const Point& other)
{
    // setter function for start point
    p_start.X(other.X());
    p_start.Y(other.Y());
}

void Line::P2(const Point& other)
{
    // setter function for end point
    p_end.X(other.X());
    p_end.Y(other.Y());
}

string Line::ToString() const
{
    // print the start point, end point and the length of the line
    string res = "";
    res = "Start Point: " + p_start.ToString() + "\n";
    res += "End Point:   " + p_end.ToString() + "\n";
    res += "Line Length:  " + to_string(Length());
    return res;
}

double Line::Length() const
{
    // return the dist from start point to the end point
    return p_start.Distance(p_end);
}