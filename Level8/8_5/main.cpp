/* main.cpp
 * ----------------------------------------------
 * @description: test poisson and exponential dist.
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */

#include <iostream>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions.hpp>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using namespace boost::math;

int main()
{
	cout << "\n-------- Exponential distribution: --------\n";
	double scaleParameter = 0.5;
    exponential_distribution<> myExponential(scaleParameter); // Default type is 'double'
	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	double x = 1;

	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;

	// Choose another data type and now a exp(1) variate
	normal_distribution<float> myExponential2; 
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;
	
	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myExponential2) << endl;
	cout << "variance: " << variance(myExponential2) << endl;
	cout << "median: " << median(myExponential2) << endl;
	cout << "mode: " << mode(myExponential2) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential2) << endl;
	cout << "kurtosis: " << kurtosis(myExponential2) << endl;
	cout << "characteristic function: " << chf(myExponential2, x) << endl;
	cout << "hazard: " << hazard(myExponential2, x) << endl;


	cout << "\n-------- Poisson distribution: --------\n";
    double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);

	double val = 13.0;
	cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";
	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";
	}

	cout << endl;

    return 0;
}