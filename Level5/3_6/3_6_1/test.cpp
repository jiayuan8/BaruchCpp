/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

int main()
{
    // create an array
    Array test_array(3);

    // cout << test_array[3] << endl;
    /* 
     * If we don't catch the error, the program will terminate when executing the above line
     * with message: libc++abi.dylib: terminating with uncaught exception of type int
     */

    // test for operator []
    try
    {
        cout << test_array[3] << endl;
    }
    catch(int err_code)
    {
        if (err_code == -1)
        {
            cout << "Array out of bound error!\n";
        }
    }

    // test for getelement
    try
    {
        cout << test_array.GetElement(-1) << endl;
    }
    catch(int err_code)
    {
        if (err_code == -1)
        {
            cout << "Array out of bound error!\n";
        }
    }

    // test for set element
    try
    {
        test_array[-1] = Point(8, 8);
    }
    catch(int err_code)
    {
        if (err_code == -1)
        {
            cout << "Array out of bound error!\n";
        }
    }
    

    return 0;
}