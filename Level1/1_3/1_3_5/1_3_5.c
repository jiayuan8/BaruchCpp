/* 1_3_5.cpp
 *
 * @Author: Jiayuan Li
 * @Description: Difference between i++ and ++i
 * @version 1.0
 */
#include <stdio.h>

/**
 * @interface: int main()
 * @description: This function will receive a input integer
 * and show the difference between i++ and ++i. (i++ first assigns the
 * value and then increase itself by 1 whereas ++i first increases itself
 * by 1 and then assigns the value)
 * @return: 0 if success
 */
int main() {
    
    int value_input; // the value to be input
    int i; // variable i for i++ and ++i
    
    printf("Please input an integer: ");

    if (scanf("%d", &value_input)) 
    {
        printf("The value you input is:      %d\n\n", value_input);

        // print the value of i++ and value of i after i++
        i = value_input;
        printf("The value of i++ is:         %d\n", i++);
        printf("The value of i after i++ is: %d\n\n", i);

        // print the value of ++i and value of i after i++
        i = value_input;
        printf("The value of ++i is:         %d\n", ++i);
        printf("The value of i after ++i is: %d\n\n", i);
    } 
    else
    {
        printf("ERROR! The value you input is not an integer!");
    }

    return 0;
}