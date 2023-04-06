#include "main.h"
/**
 * _puts_recursion - Function
 *
 * Description: prints a string, followed by a new line
 *
 * @s: pointer parameter of type char, string to print
 *
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
