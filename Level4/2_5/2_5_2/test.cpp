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

int main()
{
    // create an array of pointers to pointer to points
    Point** pointer_arr = new Point*[3];
    
    // iterate through array
    pointer_arr[0] = new Point();
    pointer_arr[1] = new Point(1, 1);
    pointer_arr[2] = new Point(*pointer_arr[1]);

    // print all the point
    for (int i = 0; i < 3; i++) 
    {
        cout << *pointer_arr[i] << endl;
    }

    // delete all the point
    for (int i = 0; i < 3; i++) 
    {
        delete pointer_arr[i];
    }

    // delete the array of pointers
    delete[] pointer_arr;

    return 0;
}