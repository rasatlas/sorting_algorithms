#include "sort.h"
void swap(int*, int*);

/**
 * shell_sort - A function that sorts an array of integers in ascending
 * order using the shell sort algorithm, using the knuth sequence.
 *
 * @array: The array to be sorted.
 * @size: size of the array.
 */

void shell_sort(int *array, size_t size)
{
	/* Done based on internet reference. */
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
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
