/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Array.cpp"
// #include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::CAD;
using namespace JIAYUAN::Containers;

int main()
{
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    cout<<intArray1.DefaultSize()<<endl; // this line will print 10
    cout<<intArray2.DefaultSize()<<endl; // this line will print 10
    cout<<doubleArray.DefaultSize()<<endl;// this line will print 10
    
    intArray1.DefaultSize(15);

    cout<<intArray1.DefaultSize()<<endl; // this line will print 15
    cout<<intArray2.DefaultSize()<<endl; // this line will print 15
    cout<<doubleArray.DefaultSize()<<endl;// this line will print 10

    return 0;
}