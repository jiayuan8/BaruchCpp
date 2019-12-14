/* FileName: DayName.c
 * ---------------------------------------------
 * 
 * @description: Implement DayName() function
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ DayName.c -o test && ./test
 * 
 */

#include <stdio.h>

// functions declaration
void DayName(int day_num);

// main function
int main() 
{
    int day_num;    // the number of the week, shoud be 1 to 7

    printf("Please input a number between 1 to 7: ");
    if (scanf("%d", &day_num)) {
        if (day_num < 1 || day_num > 7) 
        {
            printf("\n***INPUT ERROR! The input value can only be 1 to 7\n");
        }
        
        // call Daytime() to print the name of the day
        DayName(day_num);
    } 
    else 
    {
        printf("\n***INPUT ERROR! Please Check Your Input Format\n");
    }

    return 0;
}

// functions implementation
void DayName(int day_num)
{
    // a 2d array stores all the name of everyday in a week
    char num_to_name[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
                        "Thursday", "Friday", "Saturday"};

    // print the name of the day
    printf("The %dth day of a week is called %s\n", day_num, num_to_name[day_num - 1]);

    return;
}
