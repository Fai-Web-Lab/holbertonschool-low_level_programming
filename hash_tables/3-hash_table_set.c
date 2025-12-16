#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: hash table
 * @key: key (cannot be empty)
 * @value: value associated with the key (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	char *value_dup, *key_dup;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_dup = value ? strdup(value) : strdup("");
			if (value_dup == NULL)
				return (0);

			free(node->value);
			node->value = value_dup;
			return (1);
		}
		node = node->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	key_dup = strdup(key);
	if (key_dup == NULL)
	{
		free(node);
		return (0);
	}

	value_dup = value ? strdup(value) : strdup("");
	if (value_dup == NULL)
	{
		free(key_dup);
		free(node);
		return (0);
	}

	node->key = key_dup;
	node->value = value_dup;
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}

