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

int main()
{
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

    return 0;
}