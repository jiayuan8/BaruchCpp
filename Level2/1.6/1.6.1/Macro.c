/* FileName: Macro.c
 * ---------------------------------------------
 * 
 * @description: demo PRINT_1 and PRINT_2 Macors
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ Macro.c -o Macro && ./Macro
 * 
 */

#include <stdio.h>
#include "Defs.h"

// main function
int main() 
{
    double a, b;   // two input value
    printf("Please input the value of a and b\n as '<a> <b>' (double type): ");
    
    if(scanf("%lf %lf", &a, &b)) 
    {
        // call print_1 macro
        printf("\n***Call for PRINT_1\n");
        PRINT_1(a);
        // call print_2 macro
        printf("\n***Call for PRINT_2\n");
        PRINT_2(a, b);
    }
    else
    {
        printf("\n***INPUT ERROR! Please Check Your Input Format\n");
    }

    return 0;
}

