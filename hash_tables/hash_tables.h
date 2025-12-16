#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

#endif
