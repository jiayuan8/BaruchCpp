/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 27, 2019
 */

#include <iostream>
#include "Point.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    // use new to create elements on heap
    Point* p1 = new Point();
    Point* p2 = new Point(*p1);
    Point* p3 = new Point(2, 4);

    // use pointers to call member function
    cout << "point p3      : " << *p3 << endl;
    cout << "dist to origin: " << p3->Distance() << endl;

    // use delete to clear the elements on the heap
    delete p1;
    delete p2;
    delete p3;

    // ask the user to enter the size of array
    int arr_size;       // size of array
    cout << "please input the size of array(>0): ";
    cin >> arr_size;
    
    // compiler error
    // Point a[arr_size];

    Point *p_arr = new Point[arr_size]; // the default constructor is the only option
    
    // use delete to delete arr on the heap
    delete[] p_arr;

    return 0;
}