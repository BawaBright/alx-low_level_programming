#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file and text_content is the NULL
 * terminated string to add at the end of the file
 * @text_content: The string to add at the end of the file.
 * Return: 1 on success and -1 on failure
 * Do not create the file if it does not exist
 * If filename is NULL return -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i, d, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	i = open(filename, O_WRONLY | O_APPEND);
	d = write(i, text_content, len);
	if (i == -1 || d == -1)
		return (-1);
	close(i);
	return (1);
}
