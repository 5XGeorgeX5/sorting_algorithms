#include "sort.h"

/**
 * node_swapper - swaps 2 nodes of a doubly linked list
 * @node1: first node in order, about to become second
 * @node2: second node inorder, about to become first
 * @list: list where the nodes exist in
 */
void node_swapper(listint_t *node1, listint_t *node2, listint_t **list)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    int sorted = 0;
    listint_t *node, *tail;

    if (!list || !*list || !(*list)->next)
        return;
    while (!sorted)
    {
        sorted = 1;
        for (node = (*list)->next; node; node = node->next)
        {
            if (node->n < node->prev->n)
            {
                node_swapper(node->prev, node, list);
                print_list(*list);
                sorted = 0;
            }
            tail = node;
        }
        if (sorted)
            break;
        for (node = tail->prev; node; node = node->prev)
        {
            if (node->n > node->next->n)
            {
                node_swapper(node, node->next, list);
                print_list(*list);
                sorted = 0;
            }

        }
    }
}
