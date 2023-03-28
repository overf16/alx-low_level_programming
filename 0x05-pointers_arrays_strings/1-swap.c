#include "main.h"

/**
 * swap_int - Function
 *
 * Description: swaps the values of two integer
 *
 * @a: pointer parameter of type int, a to be swaped
 * @b: pointer parameter of type int, b to be swaped
 *
 */
void swap_int(int *a, int *b)
{
	    int c;

	    c =  *a;
	    *a = *b;
	    *b = c;
}
