#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - it allocates 1024 bytes for a buffer.
 * @file: its the name of  file buffer is storing chars .
 *
 * Return: The pointer to the new allocated buffer.
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
 * close_file - Closes file .
 * @fd: its the  file  to be closed.
 */
void close_file(int fd)
{
	int cls;

	cls = close(fd);

	if (cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file into another file.
 * @argc: its the  number of arguments  into the program.
 * @argv: Its an array of pointers to arguments.
 *
 * Return: 0 success.
 *
 * Description: If the count is incorrect - exit code 97.
 * If the file_from do not exist - exit code 98.
 * If file_into cannot be created or be written into - exit code 99.
 * If the file_into or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from;
	int into;
	int n;
	int wrt;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	n = read(from, buffer, 1024);
	into = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || n == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wrt = write(into, buffer, n);
		if (into == -1 || wrt == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		n = read(from, buffer, 1024);
		into = open(argv[2], O_WRONLY | O_APPEND);

	} while (n > 0);

	free(buffer);
	close_file(from);
	close_file(into);

	return (0);
}
