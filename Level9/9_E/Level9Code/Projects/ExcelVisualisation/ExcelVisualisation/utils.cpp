#include "utils.h"

vector<double> generate_array(double start, double end, double mesh_size)
{
    unsigned size = int((end - start) / mesh_size) + 1;
    auto res = vector<double>(size);
    for (auto& it : res)
    {
        it = start;
        start += mesh_size;
    }
    return res;
}

vector<double> pricing_array(const vector<double>& mesh_arr, double* para_arr, bool call) 
{
    auto res_arr = vector<double>(mesh_arr.size());
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        European tmp_european(para_arr[0], para_arr[1], para_arr[2], para_arr[3], mesh_arr[i]);
        if (call)
        {
            res_arr[i] = tmp_european.C();
        }
        else
        {
            res_arr[i] = tmp_european.P();
        }
    }
    return res_arr;
}