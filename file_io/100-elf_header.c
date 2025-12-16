#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

static void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

static void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i + 1 < EI_NIDENT ? " " : "");
	printf("\n");
}

static void print_class(unsigned char c)
{
	printf("  Class:                             ");
	if (c == ELFCLASS32)
		printf("ELF32\n");
	else if (c == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", c);
}

static void print_data(unsigned char d)
{
	printf("  Data:                              ");
	if (d == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (d == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", d);
}

static void print_version(unsigned char v)
{
	printf("  Version:                           %d", v);
	if (v == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

static void print_osabi(unsigned char o)
{
	printf("  OS/ABI:                            ");
	switch (o)
	{
	case ELFOSABI_SYSV:     printf("UNIX - System V\n"); break;
	case ELFOSABI_NETBSD:   printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_SOLARIS:  printf("UNIX - Solaris\n"); break;
	default:                printf("<unknown: %x>\n", o);
	}
}

static void print_abiversion(unsigned char v)
{
	printf("  ABI Version:                       %d\n", v);
}

static void print_type(unsigned short t, int le)
{
	if (!le)
		t = (t >> 8) | (t << 8);

	printf("  Type:                              ");
	if (t == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (t == ET_DYN)
		printf("DYN (Shared object file)\n");
	else
		printf("<unknown: %x>\n", t);
}

static void print_entry(unsigned long e)
{
	printf("  Entry point address:               %#lx\n", e);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr h;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file");

	if (read(fd, &h, sizeof(h)) != sizeof(h))
		error_exit("Error: Cannot read ELF header");

	if (h.e_ident[EI_MAG0] != ELFMAG0 ||
	    h.e_ident[EI_MAG1] != ELFMAG1 ||
	    h.e_ident[EI_MAG2] != ELFMAG2 ||
	    h.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");

	printf("ELF Header:\n");
	print_magic(h.e_ident);
	print_class(h.e_ident[EI_CLASS]);
	print_data(h.e_ident[EI_DATA]);
	print_version(h.e_ident[EI_VERSION]);
	print_osabi(h.e_ident[EI_OSABI]);
	print_abiversion(h.e_ident[EI_ABIVERSION]);
	print_type(h.e_type, h.e_ident[EI_DATA] == ELFDATA2LSB);

	if (h.e_ident[EI_CLASS] == ELFCLASS32)
		print_entry(((Elf32_Ehdr *)&h)->e_entry);
	else
		print_entry(h.e_entry);

	close(fd);
	return (0);
}
