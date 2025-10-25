#include "main.h"
/**
 * _strncat - concatenates at most n bytes of src to the end of dest
 * @dest: destination string
 * @src: source string to append
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to the resulting string dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
