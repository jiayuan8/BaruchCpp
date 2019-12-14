/* FileName: PrintToFile.c
 * ---------------------------------------------
 * 
 * @description: implement 1.9.2 functionality
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ PrintToFile.c -o test && ./test
 * 
 */

#include <stdio.h>

// macros
#define ARR_SIZE    1000
#define FM_SIZE     50
#define CTRL_A      1
#define ENTER       10


// main function
int main() 
{
    char input_val;                         // the newly input value
    char input_buffer[ARR_SIZE + 1];        // the buffer that stores the input
    char file_name[FM_SIZE + 1];            // the buffer that stores the filename
    int num_char = 0;                       // number of characters stored in the buffer
    // FILE * fp;                           // the file descripter to use

    // clear the filename buffer to pervant any garbage
    for (int i = 0; i <= FM_SIZE; i++)
    {
        file_name[i] = '\0';
    } 


    printf("Num of characters each line: 1000\n");
    printf("Please Input the FileName: ");

    // reveice a filename and open the file
    if (scanf("%s", file_name)) 
    {
        printf("The filename you input is %s\n", file_name);
    }

    FILE* fp = fopen(file_name, "w+");

    while (input_val = getchar())
    {
        /* 
         * if the value is ctrl + A, write the content in the buffer 
         * to the file, close the file, and break the loop
         */
        if (input_val == CTRL_A) 
        {
            for (int i = 0; i < num_char; i++)
            {
                fputc(input_buffer[i], fp);
            }
            fputc('\n', fp);
            fclose(fp);
            printf("CTRL+A is a corrent ending\n");
            break;
        }
        // if the value is enter, write the content in the buffer to the file
        else if (input_val == ENTER)
        {
            for (int i = 0; i < num_char; i++)
            {
                fputc(input_buffer[i], fp);
                input_buffer[i] = '\0';
            }
            num_char = 0;
            fputc('\n', fp);
            continue;
        } 
        else
        {
            // else, buffer the new character into the buffer
            input_buffer[num_char++] = input_val;
        } 
    }

    return 0;
}