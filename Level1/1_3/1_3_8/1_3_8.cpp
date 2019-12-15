/* 1_3_8.cpp
 *
 * @Author: Jiayuan Li
 * @Description: solution of 1.3.8
 * @version 1.0
 */

#include <stdio.h>

/* Assignment operators */

int main()
{
    int x=2;
    int y; 
    int z;

    x*=3+2; 
    printf("x=%d\n", x); // This line will print 10

    x*=y=z=4; 
    printf("x=%d\n", x); // This line will print 40

    x=y==z; 
    printf("x=%d\n", x); // This line will print 1

    return 0; 
}