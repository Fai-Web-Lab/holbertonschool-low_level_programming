#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_node - Creates a new hash node with key/value
 * @key: key string
 * @value: value string
 * Return: pointer to new node, or NULL if failed
 */
hash_node_t *create_node(const char *key, const char *value)
{

    hash_node_t *node = malloc(sizeof(hash_node_t));
    if (!node)
    return NULL;

    node->key = strdup(key);
    node->value = strdup(value);
    if (!node->key || !node->value)
    {
        free(node->key);
        free(node->value);
        free(node);
        return NULL;
    }

    node->next = NULL;
    return node;
}
/**
 * update_node - Updates the value of an existing node
 * @node: node to update
 * @value: new value
 * Return: 1 on success, 0 on failure
 */
int update_node(hash_node_t *node, const char *value)
{
    char *new_value = strdup(value);
    if (!new_value)
    return 0;

    free(node->value);
    node->value = new_value;
    return 1;
}

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: hash table pointer
 * @key: key string (cannot be empty)
 * @value: value string (duplicated, can be empty)
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int idx;
    hash_node_t *tmp, *new_node;

    if (!ht || !key || !*key || !value)
    return 0;

    idx = key_index((unsigned char *)key, ht->size);
    tmp = ht->array[idx];

    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        return update_node(tmp, value);
        tmp = tmp->next;
    }

    new_node = create_node(key, value);
    if (!new_node)
    return 0;

    new_node->next = ht->array[idx];
    ht->array[idx] = new_node;

    return 1;
}
