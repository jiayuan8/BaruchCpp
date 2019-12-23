/* 1_3_6.cpp
 *
 * @Author: Jiayuan Li
 * @Description: Difference between i++ and ++i
 * @version 1.0
 */

#include <stdio.h>

/**
 * @interface: int main() 
 * @description: given an integer, shift the integer by 2 digit and print both value
 * @return: 0 if success
 */
int main() 
{
    printf("Please input an integer:");
    
    int value_input = 0; // value of user input
    int shifted_value;  // the result of shift user input shifted right by 2
    
    if (scanf("%d", &value_input)) 
    {
        // shift the value by 2 digit and print both the original value and shifted value
        shifted_value = value_input >> 2;
        printf("The original value is: %d\n", value_input);
        printf("The shifted value is: %d\n", shifted_value);
        printf("Arithmatic shift is performed!\n");

    } 
    else 
    {
        printf("ERROR! vVlue input is not a integer");
    }
    
    return 0;
}