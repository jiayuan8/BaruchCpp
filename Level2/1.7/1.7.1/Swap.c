/* FileName: Swap.c
 * ---------------------------------------------
 * 
 * @description: Implement and test of Swap function
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ Swap.c -o Swap && ./Swap
 * 
 */

#include <stdio.h>

// function declaration:
void Swap(int * pointer_1, int * pointer_2);

// main function
int main() {
    int x, y;   // input values
    printf("Please input 2 int value x and y as '<x> <y>':\n");
    
    // test functionality of swap
    if (scanf("%d %d", &x, &y)) {
        printf("Your input is:              x = %d; y = %d\n", x, y);
        Swap(&x, &y);
        printf("After Swap, the values are: x = %d; y = %d\n", x, y);
    } else {
        printf("\n***INPUT ERROR! Please Check Your Input Format\n");
    }

    return 0;
}

// function implementaion:
void Swap(int * pointer_1, int * pointer_2) 
{
    // Check if the pointer is valid
    if (pointer_1 == NULL || pointer_2 == NULL)
    {
        return;
    }

    // swap the value
    int tmp_val = *pointer_1;   // a variable stores the value pointer_1 is pointing to
    *pointer_1 = *pointer_2;
    *pointer_2 = tmp_val;

    return; 
}