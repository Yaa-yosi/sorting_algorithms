#include "sort.h"
/**
 * swap_node - Swaps two nodes
 *
 * @node: node
 * @list: list to perform swap on
 *
 * Return: pointer to the swapped node
 */
listint_t *swap_node(listint_t **list, listint_t *node)
{
	listint_t *current_node = node;
	listint_t *previous_node = node->prev;

	previous_node->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = previous_node;
	current_node->next = previous_node;
	current_node->prev = previous_node->prev;
	previous_node->prev = current_node;
	if (current_node->prev != NULL)
		current_node->prev->next = current_node;
	else
		*list = current_node;

	return (current_node);
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *tmp;
	bool swapped;

	node = *list;
	swapped = true;
	if (!list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = false;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(list, node->next);
				print_list(*list);
				swapped = true;
			}
			node = node->next;
		}
		if (!swapped)
			break;
		swapped = false;
		tmp = node->prev;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				tmp = swap_node(list, tmp);
				print_list(*list);
				swapped = true;
			}
			else
				tmp = tmp->prev;
		}
		node = tmp->next;
	}
}
