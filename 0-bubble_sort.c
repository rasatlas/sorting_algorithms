#include "sort.h"
void swap(int*, int*);

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: array of integers to be sorted.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int is_swapped = 0;

	if (array == NULL || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		is_swapped = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				is_swapped = 1;
			}
		}
		if (is_swapped == 0)
			break;
	}
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
