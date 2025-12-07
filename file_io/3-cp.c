#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1024
/**
 * error_exit - print error message and exit
 * @code: exit code
 * @message: message to print
 * @file: filename to include in error message
*/
void error_exit(int code, const char *msg, const char *file)
{
	if (file == NULL || file[0] == '\0')
		dprintf(STDERR_FILENO, "%s\n", msg);
	else
		dprintf(STDERR_FILENO, "%s %s\n", msg, file);
	exit(code);
}

/**
 * main - copy content of one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[BUF_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to", argv[2]);


	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
			error_exit(99, "error: can't write to %s\n", argv[2][0] ? argv[2] : " ");
		exit(99);
	}

	if (r == -1)
		error_exit(98, "Error: Can't read from file", argv[1]);

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "error: can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "error can't fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
