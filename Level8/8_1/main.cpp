/* main.cpp
 * ----------------------------------------------
 * @description: test functionality of shared_ptr
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */


#include <iostream>
#include <boost/shared_ptr.hpp>
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Array.hpp"

using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{
    // create object for test
    ShapePtr test_point(new Point());
    ShapePtr test_line(new Line());
    ShapePtr test_circle(new Circle());

    {
        // create an array and fill it with the objects
        ShapeArray test_arr(3);
        test_arr[0] = test_point;
        test_arr[1] = test_line;
        test_arr[2] = test_circle;

        // print the shapes
        std::cout << test_arr[0]->ToString() << std::endl;
        std::cout << test_arr[1]->ToString() << std::endl;
        std::cout << test_arr[2]->ToString() << std::endl;

        // currently, there are 2 pointers pointing to each of the objects
        std::cout << "point users:  " << test_point.use_count() << std::endl;
        std::cout << "line users:   " << test_line.use_count() << std::endl;
        std::cout << "circle users: " << test_circle.use_count() << std::endl;

    }

    // currently, there are 1 pointers pointing to each of the objects
    std::cout << "point exists:  " << test_point.use_count() << std::endl;
    std::cout << "line exists:   " << test_line.use_count() << std::endl;
    std::cout << "circle exists: " << test_circle.use_count() << std::endl;

    /* if the shape are deleted, then there will be:
     * 1 line destructor calls
     * 1 circle destructor calls
     * 4 point destructor calls
     * 6 shape destructor calls
     * The output matches out assumption, therefore the shapes are deleted
     */
    std::cout << "*** destructor calls ***" << std::endl;

    return 0;

}