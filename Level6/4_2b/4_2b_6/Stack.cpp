/*  Stack.cpp
 *  ------------------------------------------
 *  @description: source file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        template <typename T, int size>
        Stack<T, size>::Stack(): m_arr(Array<T>(size)), m_current(0)
        {
            // default constructor
        }

        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& other)
        : m_arr(Array<T>(other.m_arr)), m_current(other.m_current)
        {
            // copy constructor
        }

        template <typename T, int size>
        Stack<T, size>::~Stack()
        {
            // destructor
        }

        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& other)
        {
            if (this == &other)
            {
                return *this;
            }
            m_arr = other.m_arr;
            m_current = other.m_current;
            return *this;
        }

        template <typename T, int size>
        void Stack<T, size>::Push(const T& new_element)
        {
            try
            {
                m_arr[m_current] = new_element;
            }
            catch(const ArrayException& ex)
            {
                throw Exception::StackFullException();
            }
            m_current += 1;
        }

        template <typename T, int size>
        const T& Stack<T, size>::Pop()
        {
            try
            {
                const T& res = m_arr[m_current - 1];
                m_current -= 1;
                return res;
            }
            catch(const ArrayException& ex)
            {
                throw Exception::StackEmptyException();
            }
        }
    }
}

#endif