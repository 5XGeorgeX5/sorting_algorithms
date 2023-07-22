#include "sort.h"

/**
 * merge - the merge algorithm
 * @arr: the array
 * @l: start
 * @m: mid
 * @r: end
 */
void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = malloc(n1 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];

	printf("Merging...\n[left]: ");
	print_array(L, n1);
	printf("[right]: ");
	print_array(&arr[m + 1], n2);
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] > arr[m + 1 + j])
			arr[k] = arr[m + 1 + j++];
		else
			arr[k] = L[i++];
		k++;
	}

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = arr[m + 1 + j++];

	printf("[Done]: ");
	print_array(&arr[l], n1 + n2);
	free(L);
}

/**
 * sorting - the Merge sort algorithm
 * @arr: the array
 * @l: start
 * @r: end
 */
void sorting(int *arr, int l, int r)
{
	int m;

	if (l < r)
	{
		m = (l + r - 1) / 2;
		sorting(arr, l, m);
		sorting(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/**
 * merge_sort - sorts an array using the Merge sort algorithm
 * @array: the array
 * @size: the size
 */
void merge_sort(int *array, size_t size)
{
	sorting(array, 0, size - 1);
}
