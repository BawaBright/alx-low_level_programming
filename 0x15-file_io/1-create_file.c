#include "main.h"
/**
 * create_file - Creates a file.
 * @filename: name of the file to create and text_content is a NULL
 * terminated string to write to the file
 * @text_content: A pointer to the string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int ab, d, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	ab = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	d = write(ab, text_content, len);
	if (ab == -1 || d == -1)
		return (-1);
	close(ab);
	return (1);
}
