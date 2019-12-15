/* minus.c
 * @description: implementing function minus()
 * @author: Jiayuan Li 
 * @date: Dec 14, 2019
 */

#include <stdio.h>

// function declaration
double minus(double a, double b);

int main() 
{    
    // variables used
    double input_a;    // input value for a
    double input_b;    // input value for b
    
    printf("Please input value a and b as '<a> <b>':");
    if (scanf("%lf %lf", &input_a, &input_b))
    {// print a, b and difference of a and b
        printf("Your input is: a = %lf, b = %lf\n", input_a, input_b);
        printf("The difference of a and b is %lf\n", minus(input_a, input_b));
    }
    else 
    {// cannot scan
        printf("INPUT ERROR: please check your input format!\n");
    }
    
    return 0;
}

// function implementation
double minus(double a, double b)
{// return the difference of a and b
    return a - b;
}