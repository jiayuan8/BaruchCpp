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

    /* 
     * Q: Can you explain the result?
     * A: template classes are not actual classes but template of classes.
     * Therefore, they are not compiled until they have been used (which is
     * Instantiation). Thus, Array<int> and Array<double> are different 
     * classes although they are created from the same template. Due to 
     * the reason, Array<int> and Array<double> will have two distinct 
     * static value. As a result, when you change the static value of
     * Array<int> through intArray1, the static value of Array<double> will
     * remain unchanged. However, since the static value are shared by all 
     * instances of the same class, intArray2.DefaultSize()'s output is 
     * changed to 15.
     * That explains why the output of intArray1.DefaultSize() and
     * intArray2.DefaultSize() are 15 whereas the  output of
     * doubleArray.DefaultSize() is 10.
     * 
     */

    cout<<intArray1.DefaultSize()<<endl; // this line will print 10
    cout<<intArray2.DefaultSize()<<endl; // this line will print 10
    cout<<doubleArray.DefaultSize()<<endl;// this line will print 10
    
    intArray1.DefaultSize(15);

    cout<<intArray1.DefaultSize()<<endl; // this line will print 15
    cout<<intArray2.DefaultSize()<<endl; // this line will print 15
    cout<<doubleArray.DefaultSize()<<endl;// this line will print 10

    return 0;
}