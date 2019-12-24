/* PrintTemp.cpp
 * -----------------------------
 * @author: Jiayuan Li
 * @description: implementation of exercise 1.4.1
 * @version: 1.0
 */

#include <stdio.h>

int main()
{
    int start_temp = 0;         // start point
    int end_temp = 19;         // end point
    int cur_temp = start_temp;  // current temprature

    printf("Celsius     Fahrenheit\n");

    for (cur_temp = start_temp; cur_temp <= end_temp; cur_temp++)
    {
        printf("%7d, %10.1f\n", cur_temp, ((double)9 / 5) * (double)cur_temp + 32);
    }

    return 0;
}