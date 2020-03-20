#ifndef AMERICAN_H
#define AMERICAN_H

#include "options.h"

class American : public Options
{
public:
    American();
    American(double K, double sig, double r, double S,double b);
    American(const American& other);
    ~American();
    American& operator = (const American& source);

    // calculate put price and call price with parity rule
    virtual double C() { return m_C; }
    virtual double P() { return m_P; }

private:
    double m_y1;
    double m_y2;

    virtual void calculate_b();
    // calculate put price and call price without using the parity rule
    virtual void calculate_C();
    virtual void calculate_P();
    // calculate y1 and y2
    virtual void calculate_y();

    virtual void calculate_delta();
    virtual void calculate_gamma();
};

#endif
