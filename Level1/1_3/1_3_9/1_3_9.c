/* 1_3_9.cpp
 *
 * @Author: Jiayuan Li
 * @Description: solution of 1.3.9
 * @version 1.0
 */

/* Conditional expressions */
#include <stdio.h>
int main()
{
    int x=1;
    int y=1; 
    int z=1;

    x+=y+=x;
    // The program will first compute y, which is y = y (1) + x (1)
    // Therefore, the value of y is 2
    // Then, it will compute x = x (1) + y (2)
    // Therefore, the value of x is 3
    
    printf("%d\n\n", (x<y)?y:x);    // This line will print 3
    // Since x == 3, y == 2 and x > y. This line will print x, which is 3
    
    printf("%d\n", (x<y)?x++:y++);  // This line will print 2
    // Since x == 3, y == 2 and x > y. This line will print y++, which is 2
    // y will be incremented by 1. Therefore, y is 3 now
    
    printf("%d\n", x);              // This line will print 3
    // We have justified x is 3 now (see line 17 - 20)
    
    printf("%d\n", y);              // This line will print 3
    // We have justified y is 3 now (see line 26 - 27)

    return 0; 
}