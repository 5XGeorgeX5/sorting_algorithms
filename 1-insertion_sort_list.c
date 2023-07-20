#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked listusing the Insertion sort algorithm
 * @list: the array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node, *it = (*list)->next;

	while (it)
	{
		node = it->prev;
		if(node->n > it->n)
		{
			tmp = it;
			node = node->prev;
			while (node && node->n > tmp->n)
				node = node->prev;
			it = it->prev;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			if (node)
			{
				tmp->next = node->next;
				node->next = tmp;
			}
			else
			{
				tmp->next = *list;
				*list = tmp;
			}
			tmp->prev = node;
			print_list(*list);
		}
		it = it->next;
	}
}
