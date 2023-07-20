#include "sort.h"

/**
 * swap_list - swaps 2 nodes
 * @node1: the fist node
 * @node2: the second node
 * @list: the list
 *
 * Return: 1 or 0
 */
int swap_list(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->n <= node2->n)
		return (0);
	node1->next = node2->next;
		if (node2->next)
			node2->next->prev = node1;
		node2->next = node1;
		node2->prev = node1->prev;
		node1->prev = node2;
		if (node2->prev)
			node2->prev->next = node2;
		else
			*list = node2;
	print_list(*list);
	return (1);
}

/**
 * cocktail_sort_list - sorts a linked list Cocktail shaker sort algorithm
 * @list: the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, end = -1, start = 0, i;
	listint_t *node = *list;

	while (node)
	{
		end++;
		node = node->next;
	}
	node = *list;
	while (swapped)
	{
		swapped = 0;
		for (i = start; i < end; i++)
		{
			if (swap_list(node, node->next, list))
				swapped = 1;
			else
				node = node->next;
		}
		if (!swapped--)
			break;
		end--;
		node = node->prev;
		for (i = end; i > start; i--)
		{
			if (swap_list(node->prev, node, list))
				swapped = 1;
			else
				node = node->prev;
		}
		start++;
		node = node->next;
	}
}
