/* 1_3_3.cpp
 *
 * @Author: Jiayuan Li
 * @Description: Solution for exercise 1.3.3
 * @version 1.0
 */

/* Operators */
#include <stdio.h>
int main()
{
    int x;
    
    x=-3+4*5-6;
    printf("x=%d\n", x); // This line will print 11, 
    // the equation is equivalent to -3 + (4 * 5) - 6
    
    x=3+4%5-6;
    printf("x=%d\n", x); // This line will print 1
    // the equation is equivalent to 3 + (4 % 5) - 6
    
    x=-3*4%-6/5;
    printf("x=%d\n", x); // This line will print 0
    // the formula is equivalent to ((-3 * 4) % (-6)) / 5
    
    x=(7+6)%5/2;
    printf("x=%d\n", x); // This line will print 1
    // the formula is equivalent to 13 % 5 / 2 = 3 / 2 = 1
    
    return 0;
}
