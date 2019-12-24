/* PrintTemp.cpp
 * -----------------------------
 * @author: Jiayuan Li
 * @description: implementation of exercise 1.4.4
 * @version: 1.0
 */

#include <stdio.h>

int main()
{
    int start_temp = 0;         // start point
    int end_temp = 300;         // end point
    int step_temp = 20;         // step size
    int cur_temp = start_temp;  // current temprature

    printf("Fahrenheit     Celsius\n");

    while (cur_temp <= end_temp)
    {
        printf("%10d, %10.1f\n", cur_temp, ((double)5 / 9) * ((double)cur_temp - 32));
        cur_temp += step_temp;
    }

    return 0;
}