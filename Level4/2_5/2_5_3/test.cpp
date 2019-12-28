/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 25, 2019
 */

#include <iostream>
#include "Array.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    // test for constructors and Size()
    Array test_array_1;
    Array test_array_2(20);
    Array test_array_3(test_array_1);
    cout << "array 1: " << test_array_1.Size() << endl;
    cout << "array 2: " << test_array_2.Size() << endl;
    cout << "array 3: " << test_array_3.Size() << endl;

    // test for [] overloading
    for (size_t i = 0; i < 10; i++)
    {
        test_array_1[i] = Point(i);
    }
    cout << "array 1: ";
    for (size_t i = 0; i < 10; i++)
    {
        cout << test_array_1[i] << " ";
    }
    cout << endl;

    // test for = overloading and GetElement()
    test_array_2 = test_array_1;
    cout << "array 2: ";
    for (size_t i = 0; i < 10; i++)
    {
        cout << test_array_2.GetElement(i) << " ";
    }
    cout << endl;

    // test for SetElement()
    test_array_3.SetElement(0, Point(1.1, 1.1));
    test_array_3.SetElement(1, Point(2.2, 2.2));
    cout << endl;
    for (size_t i = 0; i < 2; i++)
    {
        cout << test_array_3.GetElement(i) << " ";
    }
    cout << endl;
    
    return 0;
}