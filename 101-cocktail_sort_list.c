#include "sort.h"

/**
 * swap_list - Function that swaps the elements of the list
 *
 * @ptr1: The  first pointer
 * @ptr2: The second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 * Return: No return value
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr1;
	tmp = *ptr2;

	aux->next = tmp->next;
	tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = aux;
}

/**
 * increase_sort - Movesthe bigger numbers to the end
 *
 * @ptr: The pointer to the bigger number
 * @limit: The limit of the list
 * @list: The list of integers
 * Return: No return value
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * decrease_sort - Function that moves the smaller numbers to the start
 *
 * @ptr: The pointer to the smaller number
 * @limit: The limit of the list
 * @list: The list of integers
 * Return: No return
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 *
 * @list: The head of the linked list
 * Return: No return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
