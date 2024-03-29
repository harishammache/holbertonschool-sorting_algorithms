#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 * @list: pointer to a pointer of the listint_t structure. It's a double
 * pointer
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			temp->prev = current;
			current->next = temp;

			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}

