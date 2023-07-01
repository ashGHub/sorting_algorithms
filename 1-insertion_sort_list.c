#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sort integers in ascending order with insertion sort
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n, *p_n, *n_n, *tmp;

	if (list == NULL)
		return;

	n = *list;

	while (n)
	{
		p_n = n->prev;
		n_n = n->next;
		while (p_n && p_n->n > n->n)
		{
			tmp = n->next;
			if (p_n->prev)
			{
				p_n->prev->next = n;
				n->prev = p_n->prev;
			}
			else
			{
				n->prev = NULL;
				*list = n;
			}
			n->next = p_n;
			p_n->prev = n;
			p_n->next = tmp;
			if (tmp != NULL)
			{
				tmp->prev = p_n;
			}
			p_n = n->prev;
			print_list((const listint_t *)*list);
		}
		n = n_n;
	}
}
