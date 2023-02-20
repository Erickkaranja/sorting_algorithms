#include "sort.h"

/**
* swap_nodes - swaps two nodes in a listint_t doubly-linked list.
* @h: Pointer to the ead of the doubly-linked list.
* @n1: The first node of swap.
* @n2: The second node of swap.
*/

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
* insertion_sort_list - sorts a doubly linked list of integers in ascending.
* @list: Pointer to the linkedlist to be sorted.
*
* Description: Prints the list after every swap.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iter = (*list)->next ; iter != NULL ; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
