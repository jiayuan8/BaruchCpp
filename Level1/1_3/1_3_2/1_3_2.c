/* 1_3_2.c
 *
 * @Author: Jiayuan Li
 * @Description: This program will calculate the area of a triangle
 * @version 1.0
 */

#include <stdio.h>

/**
 * @interface:int main() 
 * @description: the program will wait for 2 input (base and height) and calculate
 * the area of triangle
 * @return: 0 if success
 */
int main()
{
    double base = 0; // The base of the triangle
    double height = 0; // The height of the triangle
    
    printf("Please input the parameters as: \"<Base> <Height>\"\n");
    
    if (scanf("%lf %lf", &base, &height)) 
    {
        if (base > 0 && height > 0) 
        {
            // Calculate the area
            printf("The area of the triangle is: %lf\n", (base * height) / 2);
        } 
        else 
        {
            // If any of the parameters is less than or equal to 0
            printf("ERROR! Both base and height need to be greater than 0\n");
        }
    } 
    else 
    {
        // If any of the input parameters is not double type
        printf("ERROR! Wrong input format!\n");
    }
    
    return 0;
}
