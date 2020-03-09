#pragma once

#include <vector>
#include <iostream>
#include "European.h"


using std::vector;
using std::cout;
using std::endl;

// helper function for Group A Part C
vector<double> generate_array(double start, double end, double mesh_size);

// helper function for Group E Part B: return the price array directly
vector<double> pricing_array(const vector<double>& mesh_arr, double* para_arr, bool call = false);
