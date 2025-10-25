#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - generates and prints a random 6-character password
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	char password[7];
	const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	size_t i;

	srand((unsigned int) time(NULL));

	for (i = 0; i < 6; i++)
		password[i] = charset[rand() % 62];

	password[6] = '\0';
	printf("%s\n", password);

	return (0);
}
