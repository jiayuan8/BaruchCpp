/*  PointArray.cpp
 *  ------------------------------------------
 *  @description: header file of Array class
 *  @author: Jiayuan Li
 *  @version: 1.0 Dec 28, 2019
 */

#include "PointArray.hpp"

namespace JIAYUAN
{
    namespace Containers
    {
        // constructors
        PointArray::PointArray(): Array<CAD::Point>()
        {
            // default constructor
        }
        
        PointArray::PointArray(size_t size): Array<CAD::Point>(size)
        {
            // constructor by parameters
        }

        PointArray::PointArray(const PointArray& other): Array<CAD::Point>(other)
        {
            //copy constructor
        }

        PointArray::~PointArray()
        {

        }

        PointArray& PointArray::operator = (const PointArray& other)
        {
            if (this == &other)
            {
                return *this;
            }
            Array<CAD::Point>::operator = (other);
            return *this;
        }

        double PointArray::Length() const
        {
            if (this->Size() == 1)
            {
                return 0;
            }
            double dist = 0;
            for(size_t i = 0; i < this->Size() - 1; i++)
            {
                dist += (this->GetElement(i)).Distance(this->GetElement(i + 1));
            }
            return dist;
        }
    }
}