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
