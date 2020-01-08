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
        template <typename T>
        Stack<T>::Stack(): m_arr(Array<T>()), m_current(0)
        {
            // default constructor
        }

        template <typename T>
        Stack<T>::Stack(size_t size): m_arr(Array<T>(size)), m_current(0)
        {
            // constructor with parameters
        }

        template <typename T>
        Stack<T>::Stack(const Stack<T>& other)
        : m_arr(Array<T>(other.m_arr)), m_current(other.m_current)
        {
            // copy constructor
        }

        template <typename T>
        Stack<T>::~Stack()
        {
            // destructor
        }

        template <typename T>
        Stack<T>& Stack<T>::operator = (const Stack<T>& other)
        {
            if (this == &other)
            {
                return *this;
            }
            m_arr = other.m_arr;
            m_current = other.m_current;
            return *this;
        }

        template <typename T>
        void Stack<T>::Push(const T& new_element)
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

        template <typename T>
        const T& Stack<T>::Pop()
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