#include "main.h"
#include <stdio.h>

/**
 * read_textfile - Read text from a file and print it to the standard output.
 * @filename: The name of the file to be read.
 * @letters: The maximum number of letters to read and print.
 * Return: The actual number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buf;
	ssize_t w = 0;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		(file);
		return (0);
	}

	w = fread(buf, 1, letters, file);
	if (w > 0)
	{
		w = fwrite(buf, 1, w, stdout);
	}

	free(buf);
	fclose(file);

	return (w);
}
