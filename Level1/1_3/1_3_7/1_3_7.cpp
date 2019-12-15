/* 1_3_7.cpp
 *
 * @Author: Jiayuan Li
 * @Description: calculate x * 2 ^ n efficiently 
 * @version 1.0
 */

#include <stdio.h>

/**
 * @interface: int main()
 * @description: This function will take two input a and n and calculates 
 * the value of a * 2 ^ n
 * @return: 0 if success
 */
int main() {
    double value_a;  // the value of the first number
    int value_power;   // the value of power n
    int power_of_two;  // the value of 2 ^ n

    printf("Please input two numbers a (double) and n (int): ");
    if (scanf("%lf %d", &value_a, &value_power))
    {
        // compute and print the result
        power_of_two = 2 << (value_power - 1);
        printf("The result of %lf * 2 ^ %d is: %lf\n", value_a, value_power, value_a * power_of_two);
    }
    else
    {
        printf("ERROR! wrong type of input received!\n");
    }
    
    return 0;
}
