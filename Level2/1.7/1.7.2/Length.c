/* FileName: Length.c
 * ---------------------------------------------
 * 
 * @description: Implement Length() function
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ Length.c -o test && ./test
 * 
 */

/* Calculate the length of a string */
#include <stdio.h>
#include <string.h>
#define MAXLINE 30
// String lenght declaration
int Length(char str[]);

// main function
int main()
{
    char string[MAXLINE+1];
    int c;
    int i=0;
    // Line of maxium 30 chars + \0
    // The input character
    // The counter

    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
    // Get the characters
    while ((c=getchar())!=EOF && i<MAXLINE)
    {
        // Append entered character to string
        string[i++]=(char)c;
    }
    string[i]='\0';
    // String must be closed with \0
    printf("\nString length (My Length Implemetation) is %d\n", Length(string));
    printf("String length (strlen in standard lib)  is %lu\n", strlen(string));
    return 0;
}

/* Implement the Length() function here */
int Length(char str[]) 
{
    // loop through the array until '\0'
    for(int i = 0; i <= MAXLINE; i++)
    {
        if (str[i] == '\0') {
            return i;
        }
    }

    // The '\0' character doesn't exist in the array. The array is not a valid string
    return -1;
}