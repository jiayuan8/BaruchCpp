#include<iostream>
#include <vector>
#include <iomanip>
#include "European.h"
#include "American.h"
#include "utils.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Group A, part 1.A
    European Batch1(0.25, 65, 0.3, 0.08, 60);
    European Batch2(1.0, 100, 0.2, 0.0, 100);
    European Batch3(1.0, 10, 0.50, 0.12, 5);
    European Batch4(30.0, 100, 0.3, 0.08, 100);

    cout << "--------Group A ---- part 1.A--------" << endl;
    cout << "Batch 1: \n    " << "Call Price: " << Batch1.C() << ", Put Price: " << Batch1.P() << endl;
    cout << "Batch 2: \n    " << "Call Price: " << Batch2.C() << ", Put Price: " << Batch2.P() << endl;
    cout << "Batch 3: \n    " << "Call Price: " << Batch3.C() << ", Put Price: " << Batch3.P() << endl;
    cout << "Batch 4: \n    " << "Call Price: " << Batch4.C() << ", Put Price: " << Batch4.P() << endl;

    // Group A, Part 1.B
    cout << "--------Group A ---- part 1.B--------" << endl;
    cout << "Batch 1: \n    " << "Call Price: " << Batch1.C(Batch1.P()) << ", Put Price: " << Batch1.P(Batch1.C()) << endl;
    cout << "    Satisfy Parity? (correct data): " << Batch1.is_parity(Batch1.P(), Batch1.C()) << endl;
    cout << "    Satisfy Parity? (wrong data): " << Batch1.is_parity(Batch1.P(), Batch1.C() - 1) << endl;

    cout << "Batch 2: \n    " << "Call Price: " << Batch2.C(Batch2.P()) << ", Put Price: " << Batch2.P(Batch2.C()) << endl;
    cout << "    Satisfy Parity? (correct data): " << Batch2.is_parity(Batch2.P(), Batch2.C()) << endl;
    cout << "    Satisfy Parity? (wrong data): " << Batch2.is_parity(Batch1.P(), Batch1.C() - 1) << endl;

    cout << "Batch 3: \n    " << "Call Price: " << Batch3.C(Batch3.P()) << ", Put Price: " << Batch3.P(Batch3.C()) << endl;
    cout << "    Satisfy Parity? (correct data): " << Batch3.is_parity(Batch3.P(), Batch3.C()) << endl;
    cout << "    Satisfy Parity? (wrong data): " << Batch3.is_parity(Batch1.P(), Batch1.C() - 1) << endl;

    cout << "Batch 4: \n    " << "Call Price: " << Batch4.C(Batch4.P()) << ", Put Price: " << Batch4.P(Batch4.C()) << endl;
    cout << "    Satisfy Parity? (correct data): " << Batch4.is_parity(Batch4.P(), Batch4.C()) << endl;
    cout << "    Satisfy Parity? (wrong data): " << Batch4.is_parity(Batch1.P(), Batch1.C() - 1) << endl;

    // Group A, Part 1.C
    auto mesh_arr = generate_array(10, 50, 1);  // generated an array of size 41 that contains 10 to 50
    auto call_price_arr = vector<double>(mesh_arr.size());
    auto put_price_arr = vector<double>(mesh_arr.size());
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        European tmp_european(0.25, 65, 0.3, 0.08, mesh_arr[i]);
        call_price_arr[i] = tmp_european.C();
        put_price_arr[i] = tmp_european.P();
    }
    cout << "--------Group A ---- part C--------\n(T=0.25,K=65,sig=0.3,r=0.08)" << endl;
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        cout << "S = " << mesh_arr[i] << ", C = " << call_price_arr[i] << ", P = " << put_price_arr[i] << endl;
    }

    // Group A, Part 1.D
    cout << "--------Group A ---- part 1.D--------\n";
    double start_arr[] = {0.25, 10, 0.05, 0, 10};
    double end_arr[] = {5, 90, 1, 1, 100};
    double mesh_size_arr[] = {0.25, 4, 0.05, 0.05, 20};
    auto start_vec = vector<double>(start_arr, start_arr + 5);
    auto end_vec = vector<double>(end_arr, end_arr + 5);
    auto mesh_size_vec = vector<double>(mesh_size_arr, mesh_size_arr + 5);
    auto input_vec = generate_matrix(start_vec, end_vec, mesh_size_vec);
    auto output_vec = pricing_matrix(input_vec);
    print_matrix(output_vec);

    // Group A, Part 2.A
    cout << "--------Group A ---- part 2.A--------\n";
    European Batch(0.5, 100, 0.36, 0.1, 105, true);
    cout << "Gamma for Call: " << Batch.Gamma_C() << ",  Gamma for Put: " << Batch.Gamma_P() << endl;
    cout << "Delta for Call: " << Batch.Delta_C() << ",  Delta for Put: " << Batch.Delta_P() << endl;

    // Group A, Part 2.B
    auto call_delta_arr = vector<double>(mesh_arr.size());
    auto put_delta_arr = vector<double>(mesh_arr.size());
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        European tmp_european(0.5, 100, 0.36, 0.1, mesh_arr[i], true);
        call_delta_arr[i] = tmp_european.Delta_C();
        put_delta_arr[i] = tmp_european.Delta_P();
    }
    cout << "--------Group A ---- part 2.B--------\n(T=0.25,K=65,sig=0.3,r=0.08)" << endl;
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        cout << "S = " << mesh_arr[i] << ", Call Delta = " << call_delta_arr[i] << ", Put Delta = " << put_delta_arr[i] << endl;
    }

    // Group A, Part 2.C
    cout << "--------Group A ---- part 2.C--------\n";
    double start_arr_2[] = { 0.5, 100, 0.1, 0.1, 100 };
    double end_arr_2[] = { 10, 200, 1, 1, 200 };
    double mesh_size_arr_2[] = { 0.5, 5, 0.05, 0.05, 5 };
    auto start_vec_2 = vector<double>(start_arr_2, start_arr_2 + 5);
    auto end_vec_2 = vector<double>(end_arr_2, end_arr_2 + 5);
    auto mesh_size_vec_2 = vector<double>(mesh_size_arr_2, mesh_size_arr_2 + 5);
    auto input_vec_delta_2 = generate_matrix(start_vec_2, end_vec_2, mesh_size_vec_2);
    auto output_vec_delta_2 = pricing_matrix(input_vec_delta_2, 1);
    print_matrix(output_vec_delta_2, 1);

    // Group A, Part 2.D
    cout << "--------Group A ---- part 2.D--------\n";
    cout << "Gamma for Call: " << Batch.Numeric_Gamma(0.01) << ",  Gamma for Put: " << Batch.Numeric_Gamma(0.01, true) << endl;
    cout << "Delta for Call: " << Batch.Numeric_Delta(0.01) << ",  Delta for Put: " << Batch.Numeric_Delta(0.01, true) << endl;

    for (int i = 0; i < mesh_arr.size(); i++)
    {
        European tmp_european(0.5, 100, 0.36, 0.1, mesh_arr[i], true);
        call_delta_arr[i] = tmp_european.Numeric_Delta(0.01);
        put_delta_arr[i] = tmp_european.Numeric_Delta(0.01, true);
    }
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        cout << "S = " << mesh_arr[i] << ", Call Delta = " << call_delta_arr[i] << ", Put Delta = " << put_delta_arr[i] << endl;
    }
    
    double h = 100;
    for (int i = 0; i < 20; i++)
    {
        cout << "h: "<< h << ",  Gamma Call: " << Batch.Numeric_Gamma(h) << ",  Gamma Put: " << Batch.Numeric_Gamma(h, true) << endl;
        h /= 10;
    }
    h = 100;
    for (int i = 0; i < 20; i++)
    {
        cout << "h: " << h << ",  Delta Call: " << Batch.Numeric_Delta(h) << ",  Delta Put: " << Batch.Numeric_Delta(h, true) << endl;
        h /= 10;
    }

    // Group B, Part b
    cout << "--------Group B ---- part b--------\n";
    American batch_amer(100, 0.1, 0.1, 110, 0.02);
    cout << "Call Price: " << batch_amer.C() << ", Put Price: " << batch_amer.P() << endl;

    // Group B, Part c
    auto call_american_arr = vector<double>(mesh_arr.size());
    auto put_american_arr = vector<double>(mesh_arr.size());
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        American tmp_american(100, 0.1, 0.1, mesh_arr[i], 0.02);
        call_american_arr[i] = tmp_american.C();
        put_american_arr[i] = tmp_american.P();
    }
    cout << "--------Group B ---- part c--------\n(K=100,sig=0.1,r=0.1, b=0.02)" << endl;
    for (int i = 0; i < mesh_arr.size(); i++)
    {
        cout << "S = " << mesh_arr[i] << ", Call Price = " << call_american_arr[i] << ", Put Price = " << put_american_arr[i] << endl;
    }

    // Group B, part d
    cout << "--------Group B ---- part d--------" << endl;
    double start_arr_3[] = { 100, 0.1, 0.1, 110, 0.02 };
    double end_arr_3[] = { 200, 1, 1, 200, 0.2 };
    double mesh_size_arr_3[] = { 5, 0.05, 0.05, 5, 0.01 };
    auto start_vec_3 = vector<double>(start_arr_3, start_arr_3 + 5);
    auto end_vec_3 = vector<double>(end_arr_3, end_arr_3 + 5);
    auto mesh_size_vec_3 = vector<double>(mesh_size_arr_3, mesh_size_arr_3 + 5);
    auto input_vec_3 = generate_matrix(start_vec_3, end_vec_3, mesh_size_vec_3);
    auto output_vec_3 = pricing_matrix(input_vec_3, 2);
    print_matrix(output_vec_3, 2);

    return 0;
}