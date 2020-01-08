/*  Stack.hpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef STACK_HPP
#define STACK_HPP

#include "Array.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T>
        class Stack
        {
        public:
            // constructors
            Stack();                    // default constructor
            Stack(size_t size);         // constructor with a given size
            Stack(const Stack<T>& other);  // copy constructor

            // destructor
            ~Stack();

            // overload assign operator
            Stack<T>& operator = (const Stack<T>& other);     // overload assign operator

            // other operations
            void Push(const T& new_element);        // push operation
            const T& Pop();                         // pop operation

        private:
            Array<T> m_arr;      // pointer to the array storing data
            size_t m_current;       // currint index
        };
    }
}

#ifndef STACK_CPP
#include "Stack.cpp"
#endif

#endif