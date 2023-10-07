#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to append to the end of the file.
 *
 * Return: On failure or if filename is NULL, return -1.
 *   If the file does not exist or the user lacks write permissions, return -1.
 *   On success, return 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	write_status = write(file_descriptor, text_content, len);

	if (file_descriptor == -1 || write_status == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);

	return (1);
}
