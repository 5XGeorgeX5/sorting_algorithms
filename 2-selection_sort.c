#include "sort.h"

/**
 * selection_sort - sorts an array using the Selection sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, mini;

	for (i = 0; i < size; i++)
	{
		mini = i;
		for (j = i + 1; j < size; j++)
			if (array[mini] > array[j])
				mini = j;
		if (mini != i)
		{
			tmp = array[i];
			array[i] = array[mini];
			array[mini] = tmp;
			print_array(array, size);
		}
	}
}
