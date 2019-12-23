/* WordCount.c
 * ---------------------------------- 
 * @author: Jiayuan Li
 * @description: Count number of character, word, lines
 * @version: 1.0 Dec, 23, 2019
 */

#include <stdio.h>
#include <stdbool.h>

#define CTRLD    4
#define ENTER    13
#define SPACE    32

int main() {
    int num_character = 0;        // number of characters
    int num_words = 0;            // number of words
    int num_lines = 1;            // number of lines
    bool enter_words = false;     // indicate whether a word is entering
    char new_char;                // the lastest input character
    
    printf("Please begin to input: \n");
    
    while((new_char = getchar()) != CTRLD)
    {
        if (new_char == ENTER)
        {
            num_lines += 1;
            num_character += 1;
            if (enter_words)
            {
                enter_words = false;
                num_words += 1;
            }
        }
        else if (new_char == SPACE)
        {
            if (enter_words) 
            {
                enter_words = false;
                num_words += 1;
            }
            num_character += 1;
        }
        else 
        {
            enter_words = true;
            num_character += 1;
        }
    }
    
    printf("-----------Word Count Summary------------\n");
    printf("Number of Characters: %d\n", num_character);
    printf("Number of Words:      %d\n", num_words);
    printf("Number of Lines:      %d\n", num_lines);
    printf("-----------------------------------------\n");
    
    return 0;
}