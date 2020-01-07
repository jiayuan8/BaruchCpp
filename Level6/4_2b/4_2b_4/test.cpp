/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "PointArray.hpp"
#include "Point.hpp"
#include "ArrayException.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;
using namespace JIAYUAN::Exception;

int main()
{
    // test constructors
    PointArray point_arr_0;
    PointArray point_arr_1(3);
    PointArray point_arr_2(point_arr_1);
    point_arr_1[0] = Point(0, 0);
    point_arr_1[1] = Point(0, 1);
    point_arr_1[2] = Point(0, 2);

    point_arr_1.PrintArray();
    point_arr_2.PrintArray();

    // test assign operator
    point_arr_2 = point_arr_1;

    point_arr_1.PrintArray();
    point_arr_2.PrintArray();

    // test Length()
    cout << "Length: " << point_arr_1.Length() << endl;

    return 0;
}