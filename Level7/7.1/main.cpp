/* main.cpp
 * ----------------------------------------
 * @description: exercise of STL containers
 * @author: Jiayuan Li
 * @version: 1.0 Jan, 8th 2020
 */

#include <iostream>
#include <list>
#include <vector>
#include <map>

int main()
{
    /********* list **********/
    std::list<double> test_list;    // create a list
    for (int i = 0; i < 3; i++)
    {   // add data to the list
        test_list.push_back(i + 1);
    }

    // print the first and the last element
    std::cout << "The first element is: " << test_list.front() << std::endl;
    std::cout << "The last element is:  " << test_list.back() << std::endl;


    /********* vector **********/
    std::vector<double> test_vector(3);    // create a vector with size 3
    
    // add data to the vector
    test_vector[0] = -1;
    test_vector[1] = -2;
    test_vector[2] = -3;
    
    // print the capacity and the size on the screen
    std::cout << "Capacity before growth: " << test_vector.capacity() << std::endl;
    std::cout << "Size before growth:     " << test_vector.size() << std::endl;

    // make the vector grow
    for (int i = 0; i < 2; i++)
    {   
        test_vector.push_back(i + 1);
    }

    // print the capacity and the size on the screen
    std::cout << "Capacity after growth:  " << test_vector.capacity() << std::endl;
    std::cout << "Size after growth:      " << test_vector.size() << std::endl;

    // use index operator to access elements
    for (int i = 0; i < test_vector.size(); i++)
    {  
        std::cout << "test_vector[" << i << "]: " << test_vector[i] << std::endl;
    }

    /********* map **********/
    std::map<std::string, double> test_map; // create a map
    
    // fill the map with [] operator
    test_map["One"] = 1;
    test_map["Two"] = 2;
    test_map["Ten"] = 10;

    // access the element in the map with [] operator
    std::cout << "test_map[\"One\"]: " << test_map["One"] << std::endl;
    std::cout << "test_map[\"Two\"]: " << test_map["Two"] << std::endl;
    std::cout << "test_map[\"Ten\"]: " << test_map["Ten"] << std::endl;

    return 0;
}