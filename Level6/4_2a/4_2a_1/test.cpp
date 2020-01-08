/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Array.cpp"
// #include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

int main()
{

    /* Q: Can you explain how this works?:
     * A: template classes are not actual classes but template of classes.
     * Therefore, they are not compiled until they have been used (which is
     * Instantiation). Therefore, when these function are used in main.cpp, 
     * the compiler need to find the implementation of these functions (which
     * is located in the source file (cpp file)). Thus, if you only include the 
     * header file in the main.cpp, the compiler cannot find where the implement
     * of these template are located. That's why we need to include either the
     * source file or inlcude the source file in the header file to let the 
     * compiler know where the definition of the functions are located.
     */

    // test default constructor and constructor with parameters
    Array<Point> points(3);
    Array<Point> points_2;

    // test [] operator
    points[0] = Point(3, 3);
    points[1] = Point(0.09, 0.09);
    points[2] = Point(0.71, 0.89);

    // test assign operator
    points_2 = points;
    cout << points_2[0] << endl;
    cout << points_2[1] << endl;
    cout << points_2[2] << endl;

    // test copy constructor
    Array<Point> points_3(points);

    // test Size, SetElement, GetElement
    cout << points_3.Size() << endl;
    points_3.SetElement(0, Point(9, 9));
    cout << points_3.GetElement(0) << endl;

    // test [] for const object
    const Array<Point> points_const(points_3);
    cout << points_const[0] << endl;
    cout << points_const[1] << endl;
    cout << points_const[2] << endl;

    return 0;
}