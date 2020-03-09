#include "European.h"
#include <cmath>
#include <boost/math/distributions/normal.hpp>

using boost::math::normal;

European::European()
    :Options(), m_d1(0), m_d2(0), m_parity_helper(0), isfuture(false)
{
    // default constructor
    calculate_b();
    calculate_d();
    calculate_C();
    calculate_P();
    calculate_delta();
    calculate_gamma();
}

European::European(double T, double K, double sig, double r, double S, bool future)
    :Options(T, K, sig, r, S), m_d1(0), m_d2(0), m_parity_helper(K* exp(0 - r * T) - S), isfuture(future)
{
    // constructor with parameters
    calculate_b();
    calculate_d();
    calculate_C();
    calculate_P();
    calculate_delta();
    calculate_gamma();
}

European::European(const European& other)
    :Options(other), m_d1(0), m_d2(0), m_parity_helper(other.m_parity_helper), isfuture(other.isfuture)
{
    // copy constructor
    calculate_b();
    calculate_d();
    calculate_C();
    calculate_P();
    calculate_delta();
    calculate_gamma();
}

European::~European()
{
    // destructor
}

European& European::operator + (const European& source)
{
    if (this == &source)
    {
        return *this;
    }
    Options::operator = (source);
    isfuture = source.isfuture;
    m_d1 = source.m_d1;
    m_d2 = source.m_d2;
    m_parity_helper = source.m_parity_helper;
    return *this;
}

void European::calculate_b()
{
    if (!isfuture)
    {
        m_b = m_r;
    }
    else
    {
        m_b = 0;
    }
    return;
}

void European::calculate_d()
{   // this function updates d1 and d2
    m_d1 = log(m_S / m_K) + (m_b + pow(m_sig, 2) / 2) * m_T;
    m_d1 = m_d1 / (m_sig * sqrt(m_T));
    m_d2 = m_d1 - (m_sig * sqrt(m_T));
    return;
}

void European::calculate_C()
{   // this function updates C
    normal N(0, 1);
    double N_d1 = cdf(N, m_d1);
    double N_d2 = cdf(N, m_d2);
    m_C = m_S * exp((m_b - m_r) * m_T) * N_d1 - m_K * exp(0 - m_r * m_T) * N_d2;
    return;
}

void European::calculate_P()
{   // this function updates P
    normal N(0, 1);
    double N_d1 = cdf(N, 0 - m_d1);
    double N_d2 = cdf(N, 0 - m_d2);
    m_P = m_K * exp(0 - m_r * m_T) * N_d2 - m_S * exp((m_b - m_r) * m_T) * N_d1;
    return;
}

double European::C(double P)
{   // this function updates C using the parity rule
    m_C = P - m_parity_helper;
    return m_C;
}

double European::P(double C)
{   // this function updats using the parity rule
    m_P = C + m_parity_helper;
    return m_P;
}

bool European::is_parity(double P, double C)
{   // this function checks if the put price and call price satisfies the parity
    return (P - C) == m_parity_helper;
}

void European::calculate_delta() 
{
    normal N(0, 1);
    double N_d1 = cdf(N, m_d1);
    double N_d2 = cdf(N, 0 - m_d2);
    m_delta_c = exp((m_b - m_r) * m_T) * N_d1;
    m_delta_p = m_delta_c  - exp((m_b - m_r) * m_T);
    return;
}

void European::calculate_gamma()
{
    normal N(0, 1);
    double n_d1 = pdf(N, m_d1);
    m_gamma_c = n_d1 * exp((m_b - m_r) * m_T) / (m_S * m_sig * sqrt(m_T));
    m_gamma_p = m_gamma_c;
    return;
}

double European::Numeric_Delta(double h, bool put) 
{
    double d11 = log((m_S + h) / m_K) + (m_b + pow(m_sig, 2) / 2) * m_T;
    d11 = d11 / (m_sig * sqrt(m_T));
    double d12 = log((m_S - h) / m_K) + (m_b + pow(m_sig, 2) / 2) * m_T;
    d12 = d12 / (m_sig * sqrt(m_T));
    double d21 = d11 - (m_sig * sqrt(m_T));
    double d22 = d12 - (m_sig * sqrt(m_T));

    normal N(0, 1);

    if (!put) 
    {
        double N_d11 = cdf(N, d11);
        double N_d12 = cdf(N, d12);
        double N_d21 = cdf(N, d21);
        double N_d22 = cdf(N, d22);
        double C1 = (m_S + h) * exp((m_b - m_r) * m_T) * N_d11 - m_K * exp(0 - m_r * m_T) * N_d21;
        double C2 = (m_S - h) * exp((m_b - m_r) * m_T) * N_d12 - m_K * exp(0 - m_r * m_T) * N_d22;
        return (C1 - C2) / (2 * h);
    } 
    else
    {
        double N_d11 = cdf(N, 0 - d11);
        double N_d12 = cdf(N, 0 - d12);
        double N_d21 = cdf(N, 0 - d21);
        double N_d22 = cdf(N, 0 - d22);
        double P1 = m_K * exp(0 - m_r * m_T) * N_d21 - (m_S + h) * exp((m_b - m_r) * m_T) * N_d11;
        double P2 = m_K * exp(0 - m_r * m_T) * N_d22 - (m_S - h) * exp((m_b - m_r) * m_T) * N_d12;
        return (P1 - P2) / (2 * h);
    }
}
double European::Numeric_Gamma(double h, bool put) 
{
    double d11 = log((m_S + h) / m_K) + (m_b + pow(m_sig, 2) / 2) * m_T;
    d11 = d11 / (m_sig * sqrt(m_T));
    double d12 = log((m_S - h) / m_K) + (m_b + pow(m_sig, 2) / 2) * m_T;
    d12 = d12 / (m_sig * sqrt(m_T));
    double d21 = d11 - (m_sig * sqrt(m_T));
    double d22 = d12 - (m_sig * sqrt(m_T));

    normal N(0, 1);

    if (!put)
    {
        double N_d11 = cdf(N, d11);
        double N_d12 = cdf(N, d12);
        double N_d21 = cdf(N, d21);
        double N_d22 = cdf(N, d22);
        double C1 = (m_S + h) * exp((m_b - m_r) * m_T) * N_d11 - m_K * exp(0 - m_r * m_T) * N_d21;
        double C2 = (m_S - h) * exp((m_b - m_r) * m_T) * N_d12 - m_K * exp(0 - m_r * m_T) * N_d22;
        return (C1 - 2 * m_C + C2) / (h * h);
    }
    else
    {
        double N_d11 = cdf(N, 0 - d11);
        double N_d12 = cdf(N, 0 - d12);
        double N_d21 = cdf(N, 0 - d21);
        double N_d22 = cdf(N, 0 - d22);
        double P1 = m_K * exp(0 - m_r * m_T) * N_d21 - (m_S + h) * exp((m_b - m_r) * m_T) * N_d11;
        double P2 = m_K * exp(0 - m_r * m_T) * N_d22 - (m_S - h) * exp((m_b - m_r) * m_T) * N_d12;
        return (P1 - 2 * m_P + P2) / (h * h);
    }

}
