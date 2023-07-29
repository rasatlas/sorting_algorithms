#include "sort.h"
void swap(listint_t**, listint_t**, listint_t*);

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 *
 * @list: the doubly linked list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap - swaps two nodes.
 * @head: pointer to head of the doubly linked list.
 * @node1: pointer to first node to be swapped.
 * @node2: pointer to second node to be swapped.
 */

void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
