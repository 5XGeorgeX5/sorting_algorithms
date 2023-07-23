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
 * merge - merges bitonic array
 * @arr: the array
 * @n: the size of the sub array
 * @low: the first index
 * @order: the order
 */
void merge(int *arr, int n, int low, int order)
{
	int i, k;

	if (n > 1)
	{
		k = n / 2;
		for (i = low; i < low + k; i++)
			if (order == (arr[i] > arr[i + k]))
			swap(&arr[i], &arr[i + k]);
		merge(arr, k, low, order);
		merge(arr, k, low + k, order);
	}
}

/**
 * bitonic - sorts an array using the bitonic sort algorithm
 * @arr: the array
 * @n: the size of the sub array
 * @low: the first index
 * @order: the order
 * @size: the size of the array
 */
void bitonic(int *arr, int n, int low, int order, int size)
{
	int k;

	if (n > 1)
	{
		k = n / 2;
		if (order)
			printf("Merging [%d/%d] (UP):\n", n, size);
		else
			printf("Merging [%d/%d] (DOWN):\n", n, size);
		print_array(&arr[low], n);
		bitonic(arr, k, low, 1, size);
		bitonic(arr, k, low + k, 0, size);
		merge(arr, n, low, order);
		if (order)
			printf("Result [%d/%d] (UP):\n", n, size);
		else
			printf("Result [%d/%d] (DOWN):\n", n, size);
		print_array(&arr[low], n);
	}
}

/**
 * bitonic_sort - sorts an array using the bitonic sort algorithm
 * @array: the array
 * @size: the size
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic(array, size, 0, 1, size);
}
