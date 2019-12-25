/* freq.cpp
 * -----------------------------
 * @author: Jiayuan Li
 * @description: implementation of exercise 1.4.6
 * @version: 1.0
 */

#include <stdio.h>

int main()
{
    int nums[5];        // the array to store freq of char from 0 to 4
    int num_other = 0;  // number of other characters
    char new_char;      // the character last read
    int i = 0;          // counter

    // initialize all entry of the freq array to 0
    for (i = 0; i < 5; i++)
    {
        nums[i] = 0;
    }

    printf("Please input:\n");

    while ((new_char = getchar()) != EOF && new_char != 26)
    {
        // if the new character is not EOF, determine which group the char belongs to
        switch (new_char)
        {
        case '0':
            nums[0]++;
            break;

        case '1':
            nums[1]++;
            break;

        case '2':
            nums[2]++;
            break;

        case '3':
            nums[3]++;
            break;

        case '4':
            nums[4]++;
            break;

        default:
            num_other++;
        }
    }

    // printout the summary
    printf("---------Frequency Summary----------\n");
    for (i = 0; i < 5; i++)
    {
        if (i == 3)
        {   // dealing with the special case of 3
            switch (nums[3])
            {
            case 0:
                printf("The number three appears zero times\n");
                break;

            case 1:
                printf("The number three appears one times\n"); 
                break;

            case 2:
                printf("The number three appears two times\n");
                break;

            default:
                printf("The number three appears more than two times\n");
            }
        }
        else
        {   // dealing with characters 0, 1, 2 and 4
            printf("Number %d appears %d times\n", i, nums[i]);
        }
    }
    printf("Other characters (except 0-4) appear %d times in total\n", num_other);
    printf("------------------------------------\n");

    return 0;
}