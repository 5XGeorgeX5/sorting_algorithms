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
 * heapify - makes the max binary tree
 * @arr: the array
 * @size: the size of the array
 * @n: the size of the tree
 * @i: the index
 */
void heapify(int *arr, size_t size, int n, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, size);
		heapify(arr, size, n, max);
	}
}


/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: the array
 * @size: the size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
