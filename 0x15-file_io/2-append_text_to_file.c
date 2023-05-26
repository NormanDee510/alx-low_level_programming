#include "main.h"

/**
 * append_text_to_file - it appends text at the end of the file.
 * @filename: its a pointer to the name of a file.
 * @text_content: its the string to add to the end of a file.
 *
 * Return: if a function fails or the  filename is NULL - -1.
 *         if a file does'nt exist a user lacks write permissions - -1.
 *         Or otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int q, x, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	q = open(filename, O_WRONLY | O_APPEND);
	x = write(q, text_content, len);

	if (q == -1 || x == -1)
		return (-1);

	close(q);

	return (1);
}
