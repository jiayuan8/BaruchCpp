#ifndef OPTION_H
#define OPTION_H

class Options
{
public:
    // default constructor
    Options();
    // constructor with parameters
    Options(double T, double K, double sig, double r, double S);
    // copy constructor
    Options(const Options& other);
    // destructor
    ~Options();

    Options& operator = (const Options& source);

    // setters and getters
    virtual double C();
    virtual double P();
    virtual double Delta_C();
    virtual double Gamma_C();
    virtual double Delta_P();
    virtual double Gamma_P();


protected:
    // member variables
    double m_T;         // maturity
    double m_K;         // strike price
    double m_sig;       // volatility
    double m_r;         // risk free interest rate
    double m_S;         // current stock price
    double m_C;         // call price
    double m_P;         // put price
    double m_b;         // cost of carry

    double m_delta_c;
    double m_gamma_c;
    double m_delta_p;
    double m_gamma_p;
    

    // calculate put price and call price without using the parity rule
    virtual void calculate_C() = 0;
    virtual void calculate_P() = 0;

    // calculate b, pure virtual function, depends on derivative types
    virtual void calculate_b() = 0;

    // calculate greeks
    virtual void calculate_delta() = 0;
    virtual void calculate_gamma() = 0;

};


#endif