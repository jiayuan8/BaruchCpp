/*  StackException.hpp
 *  ------------------------------------------
 *  @description: header file of StackException class
 *  @author: Jiayuan Li
 *  @version: 3.6.2 Dec 30th 2019
 */

#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP

#include <iostream>

namespace JIAYUAN
{
    namespace Exception
    {
        // base class
        class StackException
        {
        public:
            StackException() {}     // constructor
            ~StackException() {}    // destructor
            virtual std::string GetMessage() const = 0;   // pure virtual get message function
        };

        class StackFullException: public StackException
        {
        public:
            StackFullException(): StackException() {}     // constructor
            ~StackFullException() {}    // destructor
            std::string GetMessage() const
            {
                return "StackFullException: new element cannot be pushed.";
            }
        };

        class StackEmptyException: public StackException
        {
        public:
            StackEmptyException(): StackException() {}     // constructor
            ~StackEmptyException() {}    // destructor
            std::string GetMessage() const
            {
                return "StackEmptyException: no element can be poped.";
            }
        };
    }
}

#endif
