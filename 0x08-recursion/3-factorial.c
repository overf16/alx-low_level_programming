#include "main.h"
/**
 * factorial - Function
 *
 * Description: returns the factorial of a given number
 *
 * @n: parameter of type int
 *
 * Return: returns int, if n is less than 0 returns -1
 *
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	} else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
