#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (*list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(list, node);
			print_list(*list);
		}
		node = node->next;
	}
}

