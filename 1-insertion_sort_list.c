#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked listusing the Insertion sort
 * @list: the array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node, *it;

	if (!list || !(*list))
		return;

	it = (*list)->next;
	while (it)
	{
		node = it->prev;
		tmp = it;
		it = it->next;
		while (node && node->n > tmp->n)
		{
			node->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = node;
			tmp->next = node;
			tmp->prev = node->prev;
			node->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			node = tmp->prev;
			print_list(*list);
		}
	}
}
