/* FileName: PrintStruct.c
 * ---------------------------------------------
 * 
 * @description: Implement PrintStruct() function
 * @author: Jiayuan Li
 * 
 * @To run this program under linux environment:
 *      g++ PrintStruct.c -o test && ./test
 * 
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN  20

// structure
struct Article
{
    int number;             // article number
    int quantity;           // quantity
    char description[MAXLEN + 1];   // description less than 20 characters
};

// function declarations
void Print(struct Article * article_pointer);

// main function
int main()
{
    // declare and initialize the struct
    struct Article test;    // struct for test;
    test.number = 1024;
    test.quantity = 512;
    strcpy(test.description, "This is a test!!");

    // print the struct
    Print(&test);
    
    return 0;
}

// function implementations
void Print(struct Article * article_pointer)
{
    // check if the pointer is valid
    if (article_pointer == NULL) 
    {
        printf("The pointer is NULL! return ...");
        return;
    }

    // if the pointer is valid, print the content of the structure
    printf("The number of the article is:      %d\n", article_pointer->number);
    printf("The quantity of the article is:    %d\n", article_pointer->quantity);
    printf("The description of the article is: %s\n", article_pointer->description);

    return;
}