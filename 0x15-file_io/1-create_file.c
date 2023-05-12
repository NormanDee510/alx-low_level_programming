#include "main.h"

/**
 * create_file - it creates a a file.
 * @filename: the name of the file to create.
 * @text_content: is a NULL terminated string to write to the file.
 *
 * Return: 1 its a success else -1 if its a fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wte, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wte = write(fd, text_content, l);

	if (fd == -1 || wte == -1)
		return (-1);

	close(fd);

	return (1);
}
