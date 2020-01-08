/* main.cpp
 * ----------------------------------------
 * @description: exercise of STL iterators
 * @author: Jiayuan Li
 * @version: 1.0 Jan, 8th 2020
 */

#include <iostream>
#include <list>
#include <vector>
#include <map>

using std::list;
using std::vector;
using std::map;
using std::cout;
using std::endl;

// template sum funtion for list and vector given containers
template<typename T> 
double Sum(const T& container);
// template sum funtion for list and vector given iterators
template<typename T> 
double Sum(const typename T::const_iterator& it1, const typename T::const_iterator& it2);
// template sum funtion for map given containers
template<typename K, typename V> 
double Sum(const map<K, V>& container);
// template sum funtion for map given iterators
template<typename K, typename V> 
double Sum(const typename map<K, V>::const_iterator& it1, const typename map<K, V>::const_iterator& it2);

int main()
{
    std::list<double> test_list;    // create a list
    for (int i = 0; i < 3; i++)
    {   // add data to the list
        test_list.push_back(i + 1);
    }

    std::vector<double> test_vector(3); // create a vector
    test_vector[0] = -1;
    test_vector[1] = -2;
    test_vector[2] = -3;
    for (int i = 0; i < 2; i++)
    {   
        test_vector.push_back(i + 1);
    }

    std::map<std::string, double> test_map; // create a map
    test_map["One"] = 1;
    test_map["Two"] = 2;
    test_map["Ten"] = 10;

    // test Sum() by receving reference of containers
    cout << "Sum of the list: " << Sum(test_list) << endl;
    cout << "Sum of the vector: " << Sum(test_vector) << endl;
    cout << "Sum of the map: " << Sum(test_map) << endl;

    // test Sum() by receving reference of iterators
    cout << "Sum of the list: " << Sum<list<double> >(test_list.begin(), test_list.end()) << endl;
    cout << "Sum of the vector: " << Sum<vector<double> >(test_vector.begin(), test_vector.end()) << endl;
    cout << "Sum of the vector: " << Sum<std::string, double>(test_map.begin(), test_map.end()) << endl;
}

template<typename T>
double Sum(const T& container)
{
    typename T::const_iterator it;
    double res = 0;
    for (it = container.begin(); it != container.end(); it++)
    {
        res += *it;
    }
    return res;
}

template<typename T> 
double Sum(const typename T::const_iterator& it1, const typename T::const_iterator& it2)
{
    double res = 0;
    for (typename T::const_iterator it = it1; it != it2; it++)
    {
        res += *it;
    }
    return res;
}

template<typename K, typename V> 
double Sum(const map<K, V>& container)
{
    typename map<K, V>::const_iterator it;
    double res = 0;
    for (it = container.begin(); it != container.end(); it++)
    {
        res += it->second;
    }
    return res;
}

template<typename K, typename V> 
double Sum(const typename map<K, V>::const_iterator& it1, const typename map<K, V>::const_iterator& it2)
{
    double res = 0;
    for (typename map<K, V>::const_iterator it = it1; it != it2; it++)
    {
        res += it->second;
    }
    return res;
}