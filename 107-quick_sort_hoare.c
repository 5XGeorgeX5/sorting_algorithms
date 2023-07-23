#include "sort.h"

/**
 * swap - swaps 2 numbers
 * @a: the first number
 * @b: the second number
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - sorts an array using the Quick sort algorithm
 * @arr: the array
 * @low: the first index
 * @high: the last index
 * @size: the size of the array
 *
 * Return: the intex of mid
 */
int partition(int *arr, int low, int high, int size)
{
	int pivot = arr[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return (j);

		swap(&arr[i], &arr[j]);
		print_array(arr, size);
	}
}

/**
 * quick - sorts an array using the Quick sort algorithm
 * @arr: the array
 * @low: the first index
 * @high: the last index
 * @size: the size of the array
 */
void quick(int *arr, int low, int high, int size)
{
	int mid;

	if (low < high)
	{
		mid = partition(arr, low, high, size);
		if (mid == high)
			mid--;
		quick(arr, low, mid, size);
		quick(arr, mid + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array using the Quick sort
 * @array: the array
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick(array, 0, size - 1, size);
}
