#include "sort.h"

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: the array
 * @size: the size
 */
void counting_sort(int *array, size_t size)
{
	int tmp, *index, num;
	size_t i, max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	index = malloc((max + 1) * sizeof(int));
	if (!index)
		return;
	for (i = 0; i <= max; i++)
		index[i] = 0;
	for (i = 0; i < size; i++)
		index[array[i]]++;
	for (i = 0; i < max; i++)
		index[i + 1] += index[i];
	print_array(index, max + 1);
	for (i = 0; i < size; i++)
	{
		num = index[array[i]]--;
		num--;
		tmp = array[i];
		array[i] = array[num];
		array[num] = tmp;
	}
}
