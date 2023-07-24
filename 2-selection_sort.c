#include "sort.h"
void swap(int*, int*);

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_val_index, min_val, list_value_found = 0;

	if (array == NULL || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		min_val = array[i];
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				min_val_index = j;
				list_value_found = 1;
			}
			if (list_value_found == 1)
			{
				swap(&array[i], &array[min_val_index]);
				print_array(array, size);
			}
		}
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
