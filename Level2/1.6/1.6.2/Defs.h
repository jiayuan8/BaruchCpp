/* FileName: Defs.h
 * ---------------------------------------------
 * 
 * @description: Define MAX3 and MAX2 Macros
 * @author: Jiayuan Li
 * 
 */

// definition of MAX2
#ifndef MAX2
#define MAX2(x, y) (x > y) ? x : y
#endif

// definition of MAX3
#ifndef MAX3
#define MAX3(x, y, z) MAX2(MAX2(x, y), z)
#endif