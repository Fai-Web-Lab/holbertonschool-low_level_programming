#include "function_pointers.h"
#include <stddef.h>
/**
 * array_iterator - excutes a function given as a parameter
 *
 * @array: pointer to the integer array
 * @size: size of the array
 * @action: pointer to the function to be used
 *
 * Return: Nothing
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
