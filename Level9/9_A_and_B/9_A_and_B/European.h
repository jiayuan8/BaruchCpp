#ifndef EUROPEAN_H
#define EUROPEAN_H

#include "options.h"

class European : public Options
{
public:
    European();
    European(double T, double K, double sig, double r, double S, bool future = false);
    European(const European& other);
    ~European();
    European& operator + (const European& source);

    // calculate put price and call price with parity rule
    virtual double C() { return m_C; }
    virtual double P() { return m_P; }
    virtual double C(double P);
    virtual double P(double C);
    // check if the given price satisfies the parity
    virtual bool is_parity(double P, double C);
    virtual double Numeric_Delta(double h, bool put = false);
    virtual double Numeric_Gamma(double h, bool put = false);

private:
    bool isfuture = false;
    double m_d1;
    double m_d2;
    double m_parity_helper;     //equals to Ke^(irT)-P

    virtual void calculate_b();
    // calculate put price and call price without using the parity rule
    virtual void calculate_C();
    virtual void calculate_P();
    // calculate d1 and d2
    virtual void calculate_d();

    virtual void calculate_delta();
    virtual void calculate_gamma();
};



#endif