#include "main.h"

/**
 * apppend_text_to_file - it appends texts at the end of a file.
 * @filename: its the name of the file.
 * @text_content: is the string to add in a file
 *
 * Return: if filename is NULL or if the function fails --1.
 *if the the file does not exist --1 else -1..
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i;
	int n;
	int length;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	i = open(filename, O_WRONLY | O_APPEND);
	n = write(i, text_content, length);


	if (i == -1 || n == -1)
		return (-1);

	close(i);

	return (1);
}