#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- reads a text file and prints it to the POSIX standard output.
 * @filename: text file being read
 * @letters: number of letters it should read and printed
 * Return: e actual number of letters it could read and print
 * filename is NULL return 0 and file can not be opened or read, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bri;
	ssize_t ab;
	ssize_t c;
	ssize_t d;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	bri = malloc(sizeof(char) * letters);
	c = read(ab, bri, letters);
	d = write(STDOUT_FILENO, bri, c);
	free(bri);
	close(ab);
	return (d);
}
