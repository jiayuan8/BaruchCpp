#include<iostream>
#include <vector>
#include <list>
#include <string>
#include "European.h"
#include "utils.h"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/ExcelDriver/Utilities.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

int main()
{
    double Batch1[] = { 0.25, 65, 0.3, 0.08 };
    double Batch2[] = { 1.0, 100, 0.2, 0.0 };
    double Batch3[] = { 1.0, 10, 0.50, 0.12 };
    double Batch4[] = { 30.0, 100, 0.3, 0.08 };

    auto mesh_arr = generate_array(10, 50, 1);  // generated an array of size 41 that contains 10 to 50
    auto call_price_arr_b1 = pricing_array(mesh_arr, Batch1, true);
    auto put_price_arr_b1 = pricing_array(mesh_arr, Batch1, false);
    auto call_price_arr_b2 = pricing_array(mesh_arr, Batch2, true);
    auto put_price_arr_b2 = pricing_array(mesh_arr, Batch2, false);
    auto call_price_arr_b3 = pricing_array(mesh_arr, Batch3, true);
    auto put_price_arr_b3 = pricing_array(mesh_arr, Batch3, false);
    auto call_price_arr_b4 = pricing_array(mesh_arr, Batch4, true);
    auto put_price_arr_b4 = pricing_array(mesh_arr, Batch4, false);

    list<string> label;
    label.push_back("Batch 1: Call Price");
    label.push_back("Batch 1: Put Price");
    label.push_back("Batch 2: Call Price");
    label.push_back("Batch 2: Put Price");
    label.push_back("Batch 3: Call Price");
    label.push_back("Batch 3: Put Price");
    label.push_back("Batch 4: Call Price");
    label.push_back("Batch 4: Put Price");

    list<vector<double>> curves;
    curves.push_back(call_price_arr_b1);
    curves.push_back(put_price_arr_b1);
    curves.push_back(call_price_arr_b2);
    curves.push_back(put_price_arr_b2);
    curves.push_back(call_price_arr_b3);
    curves.push_back(put_price_arr_b3);
    curves.push_back(call_price_arr_b4);
    curves.push_back(put_price_arr_b4);

    ExcelDriver xl; xl.MakeVisible(true);
    xl.CreateChart(mesh_arr, label, curves, "Comparing Batchs", "S", "Price");

    return 0;
}