#include "sort.h"

/**
 * bubble_sort - sorts an array using the Bubble sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 1; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
