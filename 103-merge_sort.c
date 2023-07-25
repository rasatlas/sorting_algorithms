#include "sort.h"
void merge_subarr(int*, int*, size_t, size_t, size_t);
void merge_sort_recursive(int*, int*, size_t, size_t);
void merge_sort(int*, size_t);

/**
 * merge_sort - A function that sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size == 1)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

/**
 * merge_sort_recursive - Merge sort algorithm using recursion.
 * @sarr: Subarray of an array of integers to sort.
 * @buf: Buffer to store the sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */

void merge_sort_recursive(int *sarr, int *buf, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(sarr, buf, front, mid);
		merge_sort_recursive(sarr, buf, mid, back);
		merge_subarr(sarr, buf, front, mid, back);
	}
}

/**
 * merge_subarr - Sort a subarray of integers.
 * @sarr: Subarray of an array of integers to sort.
 * @buf: Buffer to store the sorted subarray.
 * @front: Front index of the array.
 * @mid: Middle index of the array.
 * @back: Back index of the array.
 */

void merge_subarr(int *sarr, int *buf, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sarr + front, mid - front);

	printf("[right]: ");
	print_array(sarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buf[k] = (sarr[i] < sarr[j]) ? sarr[i++] : sarr[j++];
	for (; i < mid; i++)
		buf[k++] = sarr[i];
	for (; j < back; j++)
		buf[k++] = sarr[j];
	for (i = front, k = 0; i < back; i++)
		sarr[i] = buf[k++];

	printf("[Done]: ");
	print_array(sarr + front, back - front);
}
