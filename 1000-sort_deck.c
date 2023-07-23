#include "deck.h"

/**
 * swap_cards - swaps 2 cards
 * @it1: the first card
 * @it2: the second card
 * @deck: the deck
 */
void swap_cards(deck_node_t *it1, deck_node_t *it2, deck_node_t **deck)
{
	if (it2->next)
		it2->next->prev = it1;
	if (it1->prev)
		it1->prev->next = it2;
	else
		*deck = it2;
	it1->next = it2->next;
	it2->next = it1;
	it2->prev = it1->prev;
	it1->prev = it2;
}

/**
 * valuecmp - compares the value of 2 cards
 * @s1: the first card
 * @s2: the second card
 *
 * Return: the result
 */
int valuecmp(const char *s1, const char *s2)
{
	int v1 = s1[0], v2 = s2[0];

	if (v1 == 'K' || v2 == 'A')
		return (1);
	if (v1 == 'A' || v2 == 'K')
		return (0);
	if (v1 == '1')
		v1 = 60;
	if (v2 == '1')
		v2 = 60;
	return (v1 > v2);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *tmp, *node, *it;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	it = (*deck)->next;
	while (it)
	{
		node = it->prev;
		tmp = it;
		it = it->next;
		while (node && node->card->kind > tmp->card->kind)
		{
			swap_cards(node, tmp, deck);
			node = tmp->prev;
		}
	}
	it = (*deck)->next;
	while (it)
	{
		node = it->prev;
		tmp = it;
		it = it->next;
		while (node && valuecmp(node->card->value, tmp->card->value))
		{
			if (node->card->kind == tmp->card->kind)
			{
				swap_cards(node, tmp, deck);
				node = tmp->prev;
			}
			else
				break;
		}
	}
}
