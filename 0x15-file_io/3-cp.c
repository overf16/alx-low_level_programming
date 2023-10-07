#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_fd(int fd);

/**
 * create_buffer - Allocates a 1024-byte buffer for file content.
 *
 * Return: A pointer to the newly allocated buffer
 */
char *create_buffer(void)
{
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_fd - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with specific error codes on failure:
 * - 97: Incorrect number of arguments.
 * - 98: Cannot read from the source file or it doesn't exist.
 * - 99: Cannot write to the destination file.
 * - 100: Cannot close file descriptors.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		bytes_read = read(source_fd, buffer, 1024);

		if (source_fd == -1 || bytes_read == -1)
		{
			fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(dest_fd, buffer, bytes_read);
		if (dest_fd == -1 || bytes_written == -1)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

	} while (bytes_read > 0);

	free(buffer);
	close_fd(source_fd);
	close_fd(dest_fd);

	return (0);
}
