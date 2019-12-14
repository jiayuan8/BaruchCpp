/* FileName: FindMax.c
 * ---------------------------------------------
 * 
 * @description: demo MAX2 and MAX3 Macors
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ FindMax.c -o FindMax && ./FindMax
 * 
 */

#include <stdio.h>
#include "Defs.h"

// main function
int main() {
    double x, y, z;     // 3 input values
    printf("Please input the value of x, y and z\n as '<x> <y> <z>' (double type): ");

    if(scanf("%lf %lf %lf", &x, &y, &z))
    {
        printf("Your input is: x = %lf; y = %lf; z = %lf\n", x, y, z);

        // Call MAX2
        printf("\n***Call for MAX2\n");
        printf("The bigger value of x and y is: %lf\n", MAX2(x, y));

        // Call MAX3
        printf("\n***Call for MAX3\n");
        printf("The biggest value of x, y and z is: %lf\n", MAX3(x, y, z));
    }
    else
    {
        printf("\n***INPUT ERROR! Please Check Your Input Format\n");
    }
    
    return 0;
}
