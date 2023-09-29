#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;
	int i = 0;

	if (!b)
		return (0);

	while (b[i])
	{
		if (b[i] == '0' || b[i] == '1')
		{
			dec_val = (dec_val << 1) | (b[i] - '0');
			i++;
		}
		else
		{
			return (0);
		}
	}

	return (dec_val);
}
