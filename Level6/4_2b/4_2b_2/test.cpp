/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "NumericArray.hpp"
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
    /* 
     * Answer: The assuption is that its okay to pass any type to the
     * numeric array as template argument to just create an array. 
     * But you cannot use any functions that the type not supported, 
     * such as DotProduct() for a circle.
     * 
     * Answer: Actually, we can create a NumericArray of Point type.
     * However, we need to make sure that we will not use any member 
     * function (operators) that Point doesn't support, such as
     * DotProduct. This is because template functions are not
     * going to be compiled until they are used.
     * (see the three lines below for example)
     */

    NumericArray<Point> test_arr_p(10);     // this line will have no error
    test_arr_p.PrintArray();                // this line will print the array of point
    // test_arr_p.DotProduct(test_arr_p);   // this line will produce error

    NumericArray<double> test_arr_1(10);
    NumericArray<double> test_arr_2(10);
    for (int i = 0; i < 10; i++)
    {
        test_arr_1[i] = i + 1;
        test_arr_2[i] = i + 1;
    }

    test_arr_1.PrintArray();
    NumericArray<double> test_arr_3 = test_arr_1 + test_arr_2;
    test_arr_3.PrintArray();
    test_arr_3 = test_arr_2 * 3;
    test_arr_3.PrintArray();
    cout << "Dot Product: " << test_arr_1.DotProduct(test_arr_2) << endl;

    NumericArray<double> test_arr_4(5);
    try
    {
        test_arr_1.DotProduct(test_arr_4);
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    return 0;
}