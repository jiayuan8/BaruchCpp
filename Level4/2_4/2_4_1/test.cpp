/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    Point test_point_1 = Point(1, 1);
    Point test_point_2 = Point(0, 0);

    cout << "----------------test for Point----------------\n";
    cout << "point a: " << test_point_1.ToString() << endl;
    cout << "point b: " << test_point_2.ToString() << endl;
    cout << "test case 1 -- -a    : " << (- test_point_1).ToString() << endl;
    cout << "test case 2 -- a * 2 : " << (test_point_1 * 2.).ToString() << endl;
    cout << "test case 3 -- a + b : " << (test_point_1 + test_point_2).ToString() << endl;
    cout << "test case 4 -- a == b: " << ((test_point_1 == test_point_2) ? "true" : "false") << endl;
    cout << "test case 5 -- a == a: " << ((test_point_1 == test_point_1) ? "true" : "false") << endl;
    test_point_2 = test_point_1;
    cout << "test case 6 -- b = a : " << test_point_2.ToString() << endl;
    cout << "test case 7 -- a *= 2: " << (test_point_1 *= 2).ToString() << endl;

    return 0;
}