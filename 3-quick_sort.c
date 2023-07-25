#include "sort.h"
void swap(int*, int*);
int lomuto_partition(int*, size_t, int, int);
void lomuto_sort(int*, size_t, int, int);

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
	lomuto_sort(array, size, 0, size - 1);
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

/**
 * lomuto_partition - Order a subset of an array of integers according to the
 * lomuto partition strategy - last element is pivot.
 *
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset.
 * @right: Ending index of the subset.
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Quicksort algorithm through recursion.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
