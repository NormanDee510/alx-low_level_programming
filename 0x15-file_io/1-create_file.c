#include "main.h"

/**
 * create_file - it creates a a file.
 * @filename: the name of the file to create.
 * @text_content: its the content written in the file.
 *
 * Return: 1 its a success else -1 if its a fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int length;
	int n;

	    if (filename == NULL)
		    return (-1);

	fd = open (filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);
	
	if (text_content != NULL)
	{
		for (length = 0 ; text_content[length];)
			length++;
	}

	close(fd);

	return (1);
}
