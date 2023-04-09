#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *file);
void close_file(int fd);
/**
 * create_buffer - copies the content of a file to another file.
 * @file: The name of the file buffer is storing chars
 * Return: pointer to the new allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes files descriptor.
 * @ab: file descriptor to be closed.
 */
void close_file(int ab)
{
	int i;

	i = close(ab);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close ab %d\n", ab);
		exit(100);
	}
}

/**
 * main - Copies file contents to another file.
 * @argc: The number of arguments supplied to a program.
 * @argv: An array of pointers to an arguments.
 * Return: 0 when or on success.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int start, end, x, d;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	start = open(argv[1], O_RDONLY);
	x = read(start, buffer, 1024);
	end = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		d = write(end, buffer, x);
		if (end == -1 || d == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		x = read(start, buffer, 1024);
		end = open(argv[2], O_WRONLY | O_APPEND);
	} while (x > 0);
	free(buffer);
	close_file(start);
	close_file(end);
	return (0);
}
