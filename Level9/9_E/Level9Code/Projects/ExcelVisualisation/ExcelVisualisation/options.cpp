#include "options.h"
#include <cmath>
#include <boost/math/distributions/normal.hpp>
using boost::math::normal;

Options::Options()
    :m_T(0), m_K(1), m_sig(0), m_r(0), m_S(1), m_C(0), m_P(0), m_b(0),
    m_delta_c(0),m_delta_p(0), m_gamma_c(0), m_gamma_p(0)
{
    // default constructor
}

Options::Options(double T, double K, double sig, double r, double S)
    :m_T(T), m_K(K), m_sig(sig), m_r(r), m_S(S), m_C(0), m_P(0), m_b(0),
    m_delta_c(0), m_delta_p(0), m_gamma_c(0), m_gamma_p(0)
{
    // constructor with parameters
}

Options::Options(const Options& other)
    : m_T(other.m_T), m_K(other.m_K), m_sig(other.m_sig), m_r(other.m_r), m_S(other.m_S), 
    m_C(0), m_P(0), m_b(0), m_delta_c(0), m_delta_p(0), m_gamma_c(0), m_gamma_p(0)
{
    // constructor with parameters
}

Options::~Options()
{
    // destructor
}

double Options::C()
{   // getter for call price
    return m_C;
}

double Options::P()
{   // getter for put price
    return m_P;
}

double Options::Delta_C()
{
    return m_delta_c;
}

double Options::Gamma_C()
{
    return m_gamma_c;
}

double Options::Delta_P()
{
    return m_delta_p;
}

double Options::Gamma_P()
{
    return m_gamma_p;
}

Options& Options::operator = (const Options& source)
{
    // avoid doing assign to itself
    if (this == &source)
    {
        return *this;
    }
    m_T = source.m_T;         // maturity
    m_K = source.m_K;         // strike price
    m_sig = source.m_sig;       // volatility
    m_r = source.m_r;         // risk free interest rate
    m_S = source.m_S;         // current stock price
    m_C = source.m_C;         // call price
    m_P = source.m_P;         // put price
    m_b = source.m_b;         // cost of carry

    m_delta_c = source.m_delta_c;
    m_gamma_c = source.m_gamma_c;
    m_delta_p = source.m_delta_p;
    m_gamma_p = source.m_gamma_p;
    return *this;
}