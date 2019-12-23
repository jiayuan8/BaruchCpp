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
    // The compiler will read this line as x = x * (3 + 2)
    // x now is 10

    x*=y=z=4; 
    printf("x=%d\n", x); // This line will print 40
    // y = z = 4 will assign y and z with value 4
    // x *= y will be read as x = x (10) * y (4) which is 40
    // x now is 40, y and z are 4
    

    x=y==z; 
    printf("x=%d\n", x); // This line will print 1
    // the == operator has higher priority than =
    // Therefore, the line will be read as x = (y == z)
    // by compiler. Since y equals to z, we have x = 1

    return 0; 
}