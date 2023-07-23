#include "sort.h"

/**
 * countSort - sorts an array using the count sort algorithm
 * @arr: the array
 * @n: the size
 * @digit: the exp.
 */
void countSort(int *arr, int n, int digit)
{
	int i, count[10] = {0};
	int *output = malloc(n * sizeof(int));

	if (!output)
		return;

	for (i = 0; i < n; i++)
		count[(arr[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
		output[--count[(arr[i] / digit) % 10]] = arr[i];

	for (i = 0; i < n; i++)
		arr[i] = output[i];
	print_array(arr, n);
	free(output);
}

/**
 * radix_sort - sorts an array using the Radix sort algorithm
 * @array: the array
 * @size: the size
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, digit;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (digit = 1; max / digit > 0; digit *= 10)
		countSort(array, size, digit);
}
