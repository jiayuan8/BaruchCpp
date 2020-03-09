#include "American.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

American::American()
    :Options(INT_MAX, 100, 0.1, 0.1, 110), m_y1(0), m_y2(0)
{
    // default constructor: initialize to the settings in B.a
    m_b = 0.02;
    calculate_y();
    calculate_P();
    calculate_C();
}

American::American(double K, double sig, double r, double S, double b)
    : Options(INT_MAX, K, sig, r, S), m_y1(0), m_y2(0)
{
    // constructor with parameters
    m_b = b;
    calculate_y();
    calculate_P();
    calculate_C();
}

American::American(const American& other)
    : Options(other), m_y1(other.m_y1), m_y2(other.m_y2)
{
    // copy constructor
    calculate_y();
    calculate_P();
    calculate_C();
}

American::~American()
{

}

American& American::operator = (const American& source)
{
    if (this == &source)
    {
        return *this;
    }
    Options::operator = (source);
    m_y1 = source.m_y1;
    m_y2 = source.m_y2;
    return *this;
}

void American::calculate_C()
{   // calculate call price
    m_C = m_K / (m_y1 - 1) * pow((m_y1 - 1) * m_S / (m_y1 * m_K), m_y1);
    return;
}

void American::calculate_P()
{   // calculate put price
    m_P = m_K / (1- m_y2) * pow((m_y2 - 1) * m_S / (m_y2 * m_K), m_y2);
}

void American::calculate_y()
{   // calculate y1 and y2
    double tmp1 = 0.5 - m_b / (m_sig * m_sig);
    double tmp2 = sqrt(tmp1 * tmp1 + 2 * m_r / (m_sig * m_sig));
    m_y1 = tmp1 + tmp2;
    m_y2 = tmp1 - tmp2;
    return;
}

void American::calculate_b() 
{
    // not implemented
    return;
}

void American::calculate_delta()
{
    //not implemented
    return;
}

void American::calculate_gamma()
{
    //not implemented
    return;
}