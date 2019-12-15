/* PrintNumber.c
 * @description: implementing PrintNumber()
 * @author: Jiayuan Li 
 * @date: Dec 14, 2019
 */

#include <stdio.h>

// function declaration
/* a helper function given a number 'abcdef' (stored in p[0])
 * calculate 'a' and 'bcdef' and store these two number in
 * p[0] and p[1]. For example, given 12345 in p[0], the function
 * will store 1 in p[0] and 2345 in p[1] and return p[3] will store
 * how many zeros are following the first digit on n*/
void splitnumber(int* p);
/* recursive function that print a number */
void printnumber(int n);

// main function
int main(int argc, char *argv[]) 
{
    //variables
    int test_0 = 0;
    int test_1 = 1;
    int test_2 = -1;
    int test_3 = 12345678;
    int test_4 = -87654321;
    int test_5 = 93000003;
    int test_6 = -11110111;
    int test_7 = -11111110;
    
    // unit tests
    printf("\n %d shoud be printed: ", test_0);
    printnumber(test_0);
    printf("\n %d shoud be printed: ", test_1);
    printnumber(test_1);
    printf("\n %d shoud be printed: ", test_2);
    printnumber(test_2);
    printf("\n %d shoud be printed: ", test_3);
    printnumber(test_3);
    printf("\n %d shoud be printed: ", test_4);
    printnumber(test_4);
    printf("\n %d shoud be printed: ", test_5);
    printnumber(test_5);
    printf("\n %d shoud be printed: ", test_6);
    printnumber(test_6);
    printf("\n %d shoud be printed: ", test_7);
    printnumber(test_7);
    printf("\n");

    
}

// function implementation
void printnumber(int n)
{    
    int i;
    int split_num[3];
    
    if (n < 0)
    {   // if n < 0, print the minus sign first
        putchar('-');
        // make a recursive call for the opposite number
        printnumber(0 - n);
    }
    else if (n < 10)
    {   // base case: if only one digit left
        putchar(n + '0');
        return;
    }
    else 
    {
        /* split the number into most significant digit, number after removal of the most significant digit
         * and the number of zeros after the most significant digit */
        split_num[0] = n;
        splitnumber(split_num);
        
        // print the most significant digit
        putchar(split_num[0] + '0');
        
        // print 0s after the most significant digit
        if(split_num[2] != 0)
        {
            for(i = 0; i < split_num[2]; i++){
                putchar('0');
            }
        }
        
        if (split_num[1] == 0)
        {
            return;
        }
        
        // recursive call
        printnumber(split_num[1]);
    }
}

void splitnumber(int* p)
{
    int n = p[0];           // get the number n
    int sig_part = 1;       // will be equal to 10 ^ (number_of_digit(n) - 1)
    int sig_digit = n;      // variable to store the most significant digit of n 
    int num_digit_n = 1;    // number of digit of n
    int num_digit_re = 0;   // number of digit of n - sig_digit * sig_part
    int tmp;                // a variable for temporary value
    
    // find most significant digit, number after removal of the most significant digit
    while(sig_digit >= 10)
    {
        sig_digit /= 10;
        sig_part *= 10;
        num_digit_n += 1;
    }
    
    // store them in p
    p[0] = sig_digit;
    p[1] = n - sig_digit * sig_part;

    if (p[1] == 0)
    {
        num_digit_re = 0;
    }
    else 
    {
        // find number of zeros after most significant digit
        num_digit_re = 1;
        tmp = p[1];
        while(tmp >= 10)
        {
            num_digit_re += 1;
            tmp /= 10;
        }
    }
    
    // store the value to p[2]
    p[2] = num_digit_n - num_digit_re - 1;
    return;
}