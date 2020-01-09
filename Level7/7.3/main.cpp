/* main.cpp
 * ----------------------------------------
 * @description: exercise of STL Algorithms
 * @author: Jiayuan Li
 * @version: 1.0 Jan, 8th 2020
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "checkObj.hpp"

using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::count_if;

//global function
bool lessThen(double input)
{
    return input < 3;
}

int main()
{
    // initialize vector and list
    double arr[10] = {1, 2, 2.9, 2.999, 2.9999, 3, 4, 5, 6, 7};
    list<double> test_list;
    vector<double> test_vector;
    for(int i = 0; i < 10; i++)
    {
        test_list.push_back(arr[i]);
        test_vector.push_back(arr[i]);
    }

    // test count_if by passing the global functor
    cout << "count_if for list  : " << count_if(test_list.begin(), test_list.end(), lessThen) << endl;
    cout << "count_if for vector: " << count_if(test_vector.begin(), test_vector.end(), lessThen) << endl;

    // test count_if by passing the function object
    cout << "count_if for list  : " << count_if(test_list.begin(), test_list.end(), CheckObj<double>(3)) << endl;
    cout << "count_if for vector: " << count_if(test_vector.begin(), test_vector.end(), CheckObj<double>(3)) << endl;

    return 0;
}