#include "sort.h"

/**
 * swap_list - swaps 2 its
 * @it1: the fist it
 * @it2: the second it
 * @list: the list
 *
 * Return: 1 or 0
 */
int swap_list(listint_t *it1, listint_t *it2, listint_t **list)
{
	if (it1->n <= it2->n)
		return (0);
	if (it2->next)
		it2->next->prev = it1;
	if (it1->prev)
		it1->prev->next = it2;
	else
		*list = it2;
	it1->next = it2->next;
	it2->next = it1;
	it2->prev = it1->prev;
	it1->prev = it2;
	print_list(*list);
	return (1);
}

/**
 * cocktail_sort_list - sorts a linked list Cocktail shaker sort algorithm
 * @list: the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tail, *it;

	if (!list || !*list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		for (it = (*list)->next; it; it = it->next)
		{
			if (swap_list(it->prev, it, list))
				swapped = 1;
			tail = it;
		}
		if (!swapped)
			break;
		swapped = 0;
		for (it = tail->prev; it; it = it->prev)
		{
			if (swap_list(it, it->next, list))
				swapped = 1;
		}
	}
}
