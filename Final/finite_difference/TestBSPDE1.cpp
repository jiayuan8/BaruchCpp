// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FDMDirector.hpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace BS // Black Scholes
{
	double T = 0.55;
	double K = 75;
	double sig = 0.25;
	double r = 0.06;
	double S = 59;
	double D = 0; // aka q

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		return K *exp(-r * t);
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return (K - x) > 0 ? (K - x) : 0;
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = static_cast<int>(5*BS::K); int N = 10000-1; // k = O(h^2) !!!!!!!!!

	double Smax = 5*BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();
	
	cout << "Finished\n";

	// printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	auto res = fdir.current();
	cout << "S: " << fdir.xarr[int(BS::S)] << ", Put Price: " << res[int(BS::S)] << endl;

	return 0;
}
