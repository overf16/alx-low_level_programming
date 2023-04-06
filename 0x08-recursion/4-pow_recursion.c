#include "main.h"
/**
 * _pow_recursion - Function
 *
 * Description: x to the power of y
 *
 * @x: parameter of type int
 * @y: parameter of type int
 *
 * Return: returns the multiple
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 1)
	{
		return (x);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
		return (x * _pow_recursion(x, y - 1));
}
