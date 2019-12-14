/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a)  printf("%d", (a) )
#define NL      printf("\n");
// Print decimal
// Print new line
// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main()
{
    int i;
    int* p;
    for (i=0; i<=4; i++) PRD(a[i]);
    NL; 
    /* Solution: 01234 
     * Reason: a[i] is the ith element of array a, since i
     * is from 0 to 4, the loop will print a[0] to a[4] 
     * sequentially */

    for (p=&a[0]; p<=&a[4]; p++) PRD(*p);
    NL;
    NL; 
    /* Solution: 01234 
     * Reason: p is a int type pointer pointing to the starting address
     * of a (a[0]). When executing p++, p will point to the address
     * p + sizeof(int). Therefore, the loop will print a[0] to a[4] 
     * sequentially  */

    for (p=&a[0], i=0; i<=4; i++) PRD(p[i]);
    NL; 
    /* Solution: 01234 
     * Reason: p is a int type pointer pointing to the starting address
     * of a (a[0]). When executing p[i], p will point to the address
     * p + i * sizeof(int). Therefore, the loop will print a[0] to a[4] 
     * sequentially  */

    for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i));
    NL;
    NL; 
    /* Solution: 024 
     * Reason: p is a int type pointer pointing to the starting address
     * of a (a[0]). When executing *(p+i), p + i will point to the address
     * p + i * sizeof(int). Therefore, the loop will print a[0] to a[4] 
     * sequentially  */

    for (p=a+4; p>=a; p--) PRD(*p);
    NL; 
    /* Solution: 43210 
     * Reason: same as the second question  */

    for (p=a+4, i=0; i<=4; i++) PRD(p[-i]);
    NL; 
    /* Solution: 43210 
     * Reason: p is a int type pointer pointing to a[4]
     * (a + 4 * sizeof(int)). When executing p[-i], p will point to the address
     * p - i * sizeof(int). Therefore, the loop will print a[4] to a[0] 
     * sequentially  */

    for (p=a+4; p>=a; p--) PRD(a[p-a]);
    NL; 
    /* Solution: 43210 
     * Reason: p - a will output the value how many sizeof(int) is between 
     * pointer a and pointer p, which will be 4,3,2,1,0 in this situation */

    return 0;
}