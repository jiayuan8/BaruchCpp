/*  Point.hpp
 *  ------------------------------------------
 *  @description: header file of Point class, implement const function
 *  @author: Jiayuan Li
 *  @version: 3.4.2 Dec 29, 2019
 *      3.4.1: colon syntex
 *      3.4.2: add inheritence
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Shape.hpp"
using std::string;
using std::ostream;

namespace JIAYUAN
{
    namespace CAD
    {
        class Point: public Shape
        {
        public:

            // constructors and destructors
            Point();            // constructor
            Point(double x, double y);  // new constructor
            explicit Point(double x);   // explicit constructor
            Point(const Point& other);  // copy constructor
            ~Point();           // destruntor

            // getter and setter functions
            double X() const { return m_x; }   // function returns x coordinate of the point
            double Y() const { return m_y; }   // function returns y coordinate of the point
            void X(double new_x) { m_x = new_x; }   // inline function setting x
            void Y(double new_y) { m_y = new_y; }   // inline function setting y
            
            // other member functions
            string ToString() const; // function that return a description of the point
            double Distance() const; // calculate the distance to origin
            double Distance(const Point& p) const;  // calculate the distance between two points

            // operator overloading
            Point operator - () const;                  // Negate the coordinates.
            Point operator * (double factor) const;     // Scale the coordinates.
            Point operator + (const Point& p) const;    // Add coordinates.
            bool operator == (const Point& p) const;    // Equally compare operator.
            Point& operator = (const Point& source);    // Assignment operator.
            Point& operator *= (double factor);         // Scale the coordinates & assign.
            void Draw() const;

            // friend functions
            friend ostream& operator << (ostream& os, const Point& p);

        private:
            double m_x;         // the x coordinate of the point
            double m_y;         // the y coordinate of the point
            
        };
    }
}

#endif