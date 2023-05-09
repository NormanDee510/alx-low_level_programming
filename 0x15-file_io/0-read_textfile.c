#include "main.h"

/**
 * read_textfile - it reads a text file and prints the letters
 * @filename: text file
 * @letters: numbers of letters to be read and printed
 *
 * Return: the number of letters to be printed.0 if it fails or NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t rt, fn;
	ssize_t fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (!buf)
		return (0);
	rt = read(fd, buf, letters);
	fn = write(STDOUT_FILENO, buf, rt);

	free(buf);
	close(fd);

	return (fn);
}
