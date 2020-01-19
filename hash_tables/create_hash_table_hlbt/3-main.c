#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - create a table, and set a value in the table
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    printf("Creating a table\n\n");
    ht = hash_table_create(1024);

    printf("set a value in the hash table\n\n");
    hash_table_set(ht, "betty", "holberton");
    hash_table_set(ht, "hetairas", "holberton");
    hash_table_set(ht, "mentioner", "holberton");
    hash_table_set(ht, "heliotropes", "neurospora");
    hash_table_set(ht, "depravement", "serafins");
    hash_table_set(ht, "stylist", "holberton");
    hash_table_set(ht, "joyful", "holberton");
    hash_table_set(ht, "synaphea", "holberton");
    hash_table_set(ht, "redescribed", "urites");
    hash_table_set(ht, "dram", "holberton");
    hash_table_set(ht, "hetairas", "holberton");
    hash_table_set(ht, "mentioner", "holberton");
    hash_table_set(ht, "heliotropes", "neurospora");
    hash_table_set(ht, "depravement", "serafins");
    hash_table_set(ht, "stylist", "holberton");
    hash_table_set(ht, "joyful", "holberton");
    hash_table_set(ht, "synaphea", "holberton");
    hash_table_set(ht, "redescribed", "urites");
    hash_table_set(ht, "dram", "holberton");
    return (EXIT_SUCCESS);
}
