#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_elf(unsigned char *i_ident);
void print_magic(unsigned char *i_ident);
void print_class(unsigned char *i_ident);
void print_data(unsigned char *i_ident);
void print_version(unsigned char *i_ident);
void print_abi(unsigned char *i_ident);
void print_osabi(unsigned char *i_ident);
void print_type(unsigned int i_type, unsigned char *i_ident);
void print_entry(unsigned long int i_entry, unsigned char *i_ident);
void close_elf(int elf);
/**
 * check_elf - displays the information contained in the ELF header at the
 * start of an ELF file.
 * @i_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit code 98.
 */
void check_elf(unsigned char *i_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (i_ident[index] != 127 &&
		    i_ident[index] != 'E' &&
		    i_ident[index] != 'L' &&
		    i_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Print the magic numbers of an ELF header file
 * @i_ident: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are always separated by spaces.
 */
void print_magic(unsigned char *i_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", i_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header file.
 * @i_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *i_ident)
{
	printf("  Class:                             ");

	switch (i_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", i_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header file.
 * @i_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *i_ident)
{
	printf("  Data:                              ");

	switch (i_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", i_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header files.
 * @i_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *i_ident)
{
	printf("  Version:                           %d",
	       i_ident[EI_VERSION]);
	switch (i_ident[EI_VERSION])
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
 * print_osabi - Prints the OS/ABI of an ELF header file.
 * @i_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *i_ident)
{
	printf("  OS/ABI:                            ");

	switch (i_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", i_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header file.
 * @i_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *i_ident)
{
	printf("  ABI Version: %d\n"
			i_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header file.
 * @i_type: The ELF type.
 * @i_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int i_type, unsigned char *i_ident)
{
	if (i_ident[EI_DATA] == ELFDATA2MSB)
		i_type >>= 8;

	printf("  Type:                              ");

	switch (i_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", i_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @i_entry: The address of the ELF entry point.
 * @i_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int i_entry, unsigned char *i_ident)
{
	printf("  Entry point address:               ");

	if (i_ident[EI_DATA] == ELFDATA2MSB)
	{
		i_entry = ((i_entry << 8) & 0xFF00FF00) |
			  ((i_entry >> 8) & 0xFF00FF);
		i_entry = (i_entry << 16) | (i_entry >> 16);
	}

	if (i_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)i_entry);

	else
		printf("%#lx\n", i_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
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
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 when or on success.
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int x, y;

	x = open(argv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	y = read(x, header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(header);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->i_ident);
	printf("ELF Header:\n");
	print_magic(header->i_ident);
	print_class(header->i_ident);
	print_data(header->i_ident);
	print_version(header->i_ident);
	print_osabi(header->i_ident);
	print_abi(header->i_ident);
	print_type(header->i_type, header->i_ident);
	print_entry(header->i_entry, header->i_ident);
	free(header);
	close_elf(x);
	return (0);
}
