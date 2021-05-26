#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void do_swap(int (*array)[2], int pos1, int pos2);
ssize_t partition(int (*array)[2], ssize_t low, ssize_t high, size_t size);
void keep_sort(int (*array)[2], ssize_t low, ssize_t high, size_t size);
void print_array(int (*array)[2], size_t size);

/**
 * quick_sort -sorting algoritmh
 * @array: list array
 * @size: size array
 *
 * Return: none
 */
void quick_sort(int (*array)[2], size_t size)
{
	unsigned int low, high;

	if (size < 2 || !array)
		return;

	low = 0, high = size - 1;
	keep_sort(array, low, high, size);
}

/**
 * keep_sort - keep sorting the array
 * @array: list array
 * @low: low pont of the array
 * @high: high part of the array
 * @size: size array
 *
 * Return: none
 */
void keep_sort(int (*array)[2], ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		keep_sort(array, low, pivot - 1, size);
		keep_sort(array, pivot + 1, high, size);
	}
}

/**
 * partition - partition the array
 * @array: list array
 * @low: low part of the array
 * @high: high part of the array
 * @size: size array
 *
 * Return: pivot point in the partitioned array
 */
ssize_t partition(int (*array)[2], ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i, j;

	(void) size;
	pivot = array[high][0];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j][0] < pivot)
		{
			i++;
			if (i != j)
				do_swap(array, i, j);
		}
	}

	if (array[i + 1][0] > array[high][0])
	{
		do_swap(array, (i + 1), high);
		/*print_array(array, size);*/
	}
	return (i + 1);
}

/**
 * do_swap - change  positions in array
 * @array: array list
 * @pos1: position to change
 * @pos2: position to change
 *
 * Return: array pointer
 */
void do_swap(int (*array)[2], int pos1, int pos2)
{
	int temp[2];
	temp[0] = array[pos1][0];
	temp[1] = array[pos1][1];

	array[pos1][0] = array[pos2][0];
	array[pos1][1] = array[pos2][1];

	array[pos2][0] = temp[0];
	array[pos2][1] = temp[1];
}

void print_array(int (*array)[2], size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("{%d %d}, ", *(array[i]), array[i][1]);
		++i;
	}
	printf("\n");
}
