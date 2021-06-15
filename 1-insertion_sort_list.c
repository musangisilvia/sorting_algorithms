#include "sort.h"

/**
  * insertion_sort_list - sorts a doubly linked list of integers
  * @list: double pointer to linked list.
  *
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}

	head = *list;

	while (head)
	{
		prev = head->prev;

		while (prev && prev->n > head->n)
		{
			swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}

		head = head->next;
	}
}

/**
  * swap - swap two nodes of a list.
  * @nodeA: node to be swapped.
  * @nodeB: node to be swapped.
  * @list: double pointer to list.
  *
  */
void swap(listint_t *nodeA, listint_t *nodeB, listint_t **list)
{
	listint_t *temp1, *temp2;

	if (nodeA == NULL || nodeB == NULL)
		return;

	temp1 = nodeA->prev;
	temp2 = nodeB->next;

	if (temp1)
		temp1->next = nodeB;

	if (temp2)
		temp2->prev = nodeA;

	nodeA->next = temp2;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
	nodeB->prev = temp1;

	if (temp1 == NULL)
		*list = nodeB;
}
