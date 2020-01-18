/* main.cpp
 * ----------------------------------------------
 * @description: test functionality of random
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */

#include <iostream>
#include <boost/random.hpp>
#include <map>

using std::cout;
using std::endl;
using std::map;

int main()
{
    // Throwing dice.
    // Mersenne Twister. 
    boost::random::mt19937 myRng;
    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (std::time(0))); 
    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);

    map<int, long> statistics; // Structure to hold outcome + frequencies 
    int outcome; // Current outcome

    // set all freq to 0
    for (int i = 1; i <= 6; i++)
    {
        statistics[i] = 0;
    }

    // perform 1000000 simulations
    for (int i = 0; i < 1000000; i++)
    {
        outcome = six(myRng);
        statistics[outcome] += 1;
    }

    cout << endl << "How many trials? 1000000" << endl << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << "Trial " << i << " has " << (double)statistics[i] / 10000 << "% outcomes" << endl;
    }


    return 0;
}