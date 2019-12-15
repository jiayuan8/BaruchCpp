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
    printf("%d\n\n", (x<y)?y:x);    // This line will print 3
    printf("%d\n", (x<y)?x++:y++);  // This line will print 2
    printf("%d\n", x);              // This line will print 3
    printf("%d\n", y);              // This line will print 3

    return 0; 
}