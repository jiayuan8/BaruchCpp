/* FileName: PrintOnScreen.c
 * ---------------------------------------------
 * 
 * @description: implement 1.9.1 functionality
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ PrintOnScreen.c -o test && ./test
 * 
 */

#include <stdio.h>

// macros
#define ARR_SIZE    1000
#define CTRL_A      1
#define ENTER       10


// main function
int main() 
{
    char input_val;                         // the newly input value
    char input_buffer[ARR_SIZE + 1];        // the buffer that stores the input
    int num_char = 0;                       // number of characters stored in the buffer

    printf("Num of characters each line: 1000\n");

    while (input_val = getchar())
    {
        // if the value is ctrl + A, print the content in the buffer and break the loop
        if (input_val == CTRL_A) 
        {
            for (int i = 0; i < num_char; i++)
            {
                putchar(input_buffer[i]);
            }
            putchar('\n');
            printf("CTRL+A is a corrent ending\n");
            break;
        }

        // if the value is enter, print on screen and clear the buffer
        if (input_val == ENTER)
        {
            for (int i = 0; i < num_char; i++)
            {
                putchar(input_buffer[i]);
                input_buffer[i] = '\0';
            }
            num_char = 0;
            putchar('\n');
            continue;
        }

        // else, buffer the new character into the buffer
        input_buffer[num_char++] = input_val;
    }

    return 0;
}