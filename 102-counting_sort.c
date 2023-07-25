#include "sort.h"

/**
 * counting_sort - A function that sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: size of the array.
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int *bucket_array, *sorted_array;
	int max_val;

	if (array == NULL || size == 1)
		return;

	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
		{
			max_val = array[i];
		}
	}

	bucket_array = (int *)malloc((max_val + 1) * sizeof(max_val));
	if (!bucket_array)
		return;
	for (i = 0; i < (size_t)(max_val + 1); i++)
		bucket_array[i] = 0;

	for (i = 0; i < size; i++)
		bucket_array[array[i]]++;

	for (i = 1; i < (size_t)(max_val + 1); i++)
		bucket_array[i] += bucket_array[i - 1];
	print_array(bucket_array, (size_t)(max_val + 1));

	sorted_array = (int *)(malloc(size));
	if (!sorted_array)
	{
		free(bucket_array);
		return;
	}
	for (i = 0; i < size; i++)
		sorted_array[(bucket_array[array[i]]) - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(bucket_array);
	free(sorted_array);
}
