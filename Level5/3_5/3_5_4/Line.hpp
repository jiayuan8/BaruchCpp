/*  Line.hpp
 *  ------------------------------------------
 *  @description: header file of Line class
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include "Point.hpp"

using std::string;

namespace JIAYUAN
{
    namespace CAD
    {
        class Line: public Shape
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

            friend ostream& operator << (ostream & os, const Line& l);

        private:
            // start point and end point
            Point p_start;
            Point p_end;
        };
    }
}

#endif