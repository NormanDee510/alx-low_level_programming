#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - it checks if the file is an ELF file.
 * @e_ident: its a pointer to an array containing a ELF numbers.
 *
 * Description: if a file is not a ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int idex;

	for (idex = 0; idex < 4; idex++)
	{
		if (e_ident[idex] != 127 &&
		    e_ident[idex] != 'E' &&
		    e_ident[idex] != 'L' &&
		    e_ident[idex] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - it prints  numbers of an ELF header.
 * @e_ident: its a pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int idex;

	printf(" Magic: ");

	for (idex = 0; idex < EI_NIDENT; idex++)
	{
		printf("%02x", e_ident[idex]);

		if (idex == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - it prints a class of an ELF header.
 * @e_ident: its a pointer to an array containing a ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("Class:\n");
		break;
	case ELFCLASS64:
		printf("Class:\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - it prints the data of an ELF header.
 * @e_ident: its a pointer to an array containing a ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("Data:\n");
		break;
	case ELFDATA2MSB:
		printf("Data:\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 *  * print_version - it prints the version of a ELF header.
 *   * @e_ident: its a pointer to an array containing the ELF version.
 *
 */
void print_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - it prints the OS/ABI of an ELF header.
 * @e_ident: its a pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_NETBSD:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_LINUX:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_IRIX:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_TRU64:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_ARM:
		printf("OS/ABI:\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("OS/ABI:\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - it prints the ABI version of a ELF header.
 * @e_ident: its a pointer to an array containing the ELF ABI version.
 */

void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - it prints the type of a ELF header.
 * @e_type: its the ELF type.
 * @e_ident: its a pointer to an array containing a ELF class.
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("Type:)\n");
		break;
	case ET_EXEC:
		printf("Type:)\n");
		break;
	case ET_DYN:
		printf("Type:)\n");
		break;
	case ET_CORE:
		printf("Type:)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - it prints the entry point of a ELF header.
 * @e_entry: its the address of the ELF entry point.
 * @e_ident: its a pointer to an array containing a ELF class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - it closes a ELF file.
 * @elf: its the file descriptor of the ELF file.
 *
 * Description: If a file can't be closed - exit code 98.
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - it displays the information contained in a
 * ELF header at the start of a ELF file.
 * @argc: its the number of arguments supplied to a program.
 * @argv: its an array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If a file is not a ELF File or
 * a function fails - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int d, k;

	d = open(argv[1], O_RDONLY);
	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(d);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	k = read(d, header, sizeof(Elf64_Ehdr));
	if (k == -1)
	{
		free(header);
		close_elf(d);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(d);
	return (0);
}
