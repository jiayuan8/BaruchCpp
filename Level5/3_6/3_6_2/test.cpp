/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

int main()
{
    // create an array
    Array test_array(3);

    // test for operator []
    try
    {
        cout << test_array[3] << endl;
    }
    catch(OutOfBoundsException& error)
    {
        cout << error.GetMessage() << endl;
    }

    // test for getelement
    try
    {
        cout << test_array.GetElement(-1) << endl;
    }
    catch(OutOfBoundsException& error)
    {
        cout << error.GetMessage() << endl;
    }

    // test for set element
    try
    {
        test_array[-1] = Point(8, 8);
    }
    catch(OutOfBoundsException& error)
    {
        cout << error.GetMessage() << endl;
    }
    

    return 0;
}