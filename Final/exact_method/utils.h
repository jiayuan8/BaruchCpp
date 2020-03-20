#pragma once

#include <vector>
#include <iostream>
#include "European.h"
#include "American.h"


using std::vector;
using std::cout;
using std::endl;

// helper function for Group A Part C
vector<double> generate_array(double start, double end, double mesh_size);

// helper function for Group A Part D: generate input matrix
vector<vector<double> > generate_matrix(vector<double> start, vector<double> end, vector<double> mesh_size);

// helper function for Group A Part D: given an matrix and calculate price
vector<vector<double> > pricing_matrix(vector<vector<double> > input, unsigned mode = 0);

// helper function for Group A Part D: print the result out
void print_matrix(vector<vector<double> > input, unsigned mode = 0);
