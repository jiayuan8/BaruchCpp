/*  test.cpp
 *  ------------------------------------------
 *  @description: test file for class Point
 *  @author: Jiayuan Li
 *  @version: 3.4.1 Dec 29, 2019
 */

#include <iostream>
#include "Stack.hpp"
#include "StackException.hpp"

using std::cout;
using std::cin;
using std::endl;
using namespace JIAYUAN::Containers;
using namespace JIAYUAN::Exception;

int main()
{
    Stack<int, 3> test_stack_2;     // test constructor with parameters

    test_stack_2.Push(1);           // test push

    Stack<int, 3> test_stack_3(test_stack_2);      // test copy constructor
    Stack<int, 3> test_stack_4 = test_stack_3;     // test assign operator

    test_stack_4.Push(2);
    test_stack_4.Push(3);

    try
    {
        test_stack_4.Push(4);       // shoud throw exception
    }
    catch(const StackException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    
    cout << test_stack_4.Pop() << endl;     // test pop
    cout << test_stack_4.Pop() << endl;
    cout << test_stack_4.Pop() << endl;

    try
    {
        cout << test_stack_4.Pop() << endl;     // should throw exception
    }
    catch(const StackException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    return 0;
}