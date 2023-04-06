#include "main.h"

/**
 * _strlen_recursion - Function
 *
 * Description: returns the length of a string.
 *
 * @s: pointer paramenter of type char,
 *
 * Return: returns int
 */
int _strlen_recursion(char *s)
{
	if (*s)
	{
		return (1 + _strlen_recursion(s + 1));
	}

	return (0);
}
