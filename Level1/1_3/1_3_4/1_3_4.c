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