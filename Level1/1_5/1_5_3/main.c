/* main.c
 * @description: call print function in Print.c
 * @author: Jiayuan Li 
 * @date: Dec 14, 2019
 */

#include <stdio.h>

void print(double i);

int main() 
{
    // unit tests for print
    double i = 1;
    
    // test case for i = 1
    printf("i = %lf, call print()...\n", i);
    print(i);
    
    // test case for i = 2
    i = 2;
    printf("i = %lf, call print()...\n", i);
    print(i);
    
    // test case for i = 5
    i = 5;
    printf("i = %lf, call print()...\n", i);
    print(i);
    
    return 0;
}