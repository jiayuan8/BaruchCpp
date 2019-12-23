/* 1_3_4.cpp
 *
 * @Author: Jiayuan Li
 * @Description: Solution for exercise 1.3.4
 * @version 1.0
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int input = 0;     // value input
    
    printf("Please input a integer: ");
    if (scanf("%d", &input))
    {// if input is 0, print not married
        printf("This person is %s", (input == 0) ? "not married\n" : "married\n");
    } 
    else
    {
        printf("Input ERROR! Please check your format");
    } 
    
    return 0;
}