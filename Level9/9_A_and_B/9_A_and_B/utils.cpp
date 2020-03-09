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

vector<vector<double>> generate_matrix(vector<double> start, vector<double> end, vector<double> mesh_size)
{
    auto res_arr = vector<vector<double>>();
    auto step_arr = vector<int>(start.size());
    for (int i = 0; i < start.size(); i++)
    {
        step_arr[i] = int((end[i] - start[i]) / mesh_size[i]) + 1;
    }
    for (int i = 0; i < start.size(); i++)
    {
        double  tmp_val = start[i];
        for (int j = 0; j < step_arr[i]; j++) 
        {
            auto tmp_vec = start;
            tmp_vec[i] = tmp_val;
            res_arr.push_back(tmp_vec);
            tmp_val += mesh_size[i];
            // cout << tmp_vec[0] << " " << tmp_vec[1] << " " << tmp_vec[2] << " " << tmp_vec[3] << " " << tmp_vec[4] << endl;
        }
    }
    return res_arr;
}

vector<vector<double>> pricing_matrix(vector<vector<double>> input, unsigned mode)
{
    auto res_mat = vector<vector<double>>();
    for (auto& it : input) 
    {
        auto output = it;
        if (mode == 1) 
        {
            auto tmp_european = European(it[0], it[1], it[2], it[3], it[4], true);
            output.push_back(tmp_european.Delta_C());
            output.push_back(tmp_european.Delta_P());
            res_mat.push_back(output);
        }
        else if (mode == 2)
        {
            auto tmp_american = American(it[0], it[1], it[2], it[3], it[4]);
            output.push_back(tmp_american.C());
            output.push_back(tmp_american.P());
            res_mat.push_back(output);
        }
        else
        {
            auto tmp_european = European(it[0], it[1], it[2], it[3], it[4]);
            output.push_back(tmp_european.C());
            output.push_back(tmp_european.P());
            res_mat.push_back(output);
        }
    }
    return res_mat;
}

void print_matrix(vector<vector<double>>input, unsigned mode)
{
    for(auto&it_vec:input)
    {
        if (mode == 0) 
        {
            cout << "T:" << it_vec[0] << ",K:" << it_vec[1] << ",sig:" << it_vec[2] << ",R:" << it_vec[3] << ",S:" << it_vec[4] << endl;
            cout << "   Call Price:" << it_vec[5] << ", Put Price:" << it_vec[6] << endl;
        }
        else if (mode == 1)
        {
            cout << "T:" << it_vec[0] << ",K:" << it_vec[1] << ",sig:" << it_vec[2] << ",R:" << it_vec[3] << ",S:" << it_vec[4] << endl;
            cout << "   Call Delta:" << it_vec[5] << ", Put Delta:" << it_vec[6] << endl;
        }
        else if (mode == 2)
        {
            cout << "K:" << it_vec[0] << ",sig:" << it_vec[1] << ",r:" << it_vec[2] << ",S:" << it_vec[3] << ",b:" << it_vec[4] << endl;
            cout << "   Call Price:" << it_vec[5] << ", Put Price:" << it_vec[6] << endl;
        }
    }
}