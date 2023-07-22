#include "sort.h"

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: the array
 * @size: the size
 */
void counting_sort(int *array, size_t size)
{
	int *index, *copy, num;
	size_t i, max = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	index = malloc((max + 1) * sizeof(int));
	if (!index)
		return;
	copy = malloc(size * sizeof(int));
	if (!copy)
		return;
	for (i = 0; i <= max; i++)
		index[i] = 0;
	for (i = 0; i < size; i++)
	{
		index[array[i]]++;
		copy[i] = array[i];
	}
	for (i = 0; i < max; i++)
		index[i + 1] += index[i];
	print_array(index, max + 1);
	for (i = 0; i < size; i++)
	{
		num = index[copy[i]]--;
		num--;
		array[num] = copy[i];
	}
	free(index);
	free(copy);
}
