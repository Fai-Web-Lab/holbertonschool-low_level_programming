#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stddef.h>
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique)
 * @value: The value corresponding to the key
 * @next: Pointer to the next node in the list (for collisions)
 *
 * Description: Node structure for a hash table using chaining.
*/
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: Size of the array
 * @array: Array of size @size, each cell points to a linked list head
 *
 * Description: Hash table structure using chaining collision handling.
*/
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

#endif
