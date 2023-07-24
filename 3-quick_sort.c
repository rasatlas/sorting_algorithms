#include "sort.h"
void swap(int*, int*);

/**
 * quick_sort - A function that sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
}

/**
 * swap - A function that swaps two variables' value.
 *
 * @x: first variable.
 * @y: second variable.
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
