/* factorial.c
 * @description: implementing function factorial()
 * @author: Jiayuan Li 
 * @date: Dec 14, 2019
 */

#include <stdio.h>

// function declaration:
unsigned factorial(unsigned n);

// main function
int main() 
{
    // few unit test for function factorial
    printf("The factorial of %d is: %d\n", 0, factorial(0));
    printf("The factorial of %d is: %d\n", 1, factorial(1));
    printf("The factorial of %d is: %d\n", 6, factorial(6));
    printf("The factorial of %d is: %d\n", 15, factorial(15));
    
    return 0;
}

// function implementation
unsigned factorial(unsigned n)
{
    if (n < 0)
    {// check if input is valid
        return -1;
    }
    else if (n == 1 || n == 0)
    {// base case
        return 1;
    }
    else 
    {// recurrsive call: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}