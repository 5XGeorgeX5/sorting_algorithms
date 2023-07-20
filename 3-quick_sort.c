#include "sort.h"

/**
 * partition - sorts an array using the Quick sort algorithm
 * @arr: the array
 * @low: the first index
 * @high: the last index
 * @size: the size of the array
 *
 * Return: the intex of mid
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int tmp, j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot &&  arr[j] != arr[++i])
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, size);
		}
	}
	if (arr[high] != arr[++i])
	{
		tmp = arr[i];
		arr[i] = arr[high];
		arr[high] = tmp;
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick - sorts an array using the Quick sort algorithm
 * @arr: the array
 * @low: the first index
 * @high: the last index
 * @size: the size of the array
 */
void quick(int *arr, int low, int high, size_t size)
{
	int mid;

	if (low < high)
	{
		mid = partition(arr, low, high, size);
		quick(arr, low, mid - 1, size);
		quick(arr, mid + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using the Quick sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick(array, 0, size - 1, size);
}
