#include "sort.h"
#include <stdio.h>
/**
 * print_bitonic - Prints the array modified by
 * bitonic algorithm
 *
 * @arr: The input array
 * @i: The first index
 * @limit: The last index
 * Return: No return
 */
void print_bitonic(int *arr, int i, int limit)
{
	char *sep;

	for (sep = ""; i < limit; i++)
	{
		printf("%s%d", sep, arr[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * sort_up - Sorts the array in UP mode
 *
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * Return: No return
 */
void sort_up(int *arr, int low, int high)
{
	int i, j, max;

	for (i = low; i < high; i++)
	{
		max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[max] > arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * sort_down - Sorts the array in DOWN mode
 *
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * Return: No return
 */
void sort_down(int *arr, int low, int high)
{
	int i, j, max;

	for (i = low; i < high; i++)
	{
		max = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[max] < arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * recursion - Executes the bitonic sort
 * algorithm
 *
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * @bool: UP or DOWN
 * @size: size of the array
 * Return: No return
 */
void recursion(int *arr, int low, int high, int bool, size_t size)
{
	char *option;

	if (high - low < 2)
		return;

	option = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", high - low, size, option);
	print_bitonic(arr, low, high);

	if (high - low == 2)
		return;

	recursion(arr, low, (high + low) / 2, 0, size);
	sort_up(arr, low, (high + low) / 2);
	printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
	print_bitonic(arr, low, (high + low) / 2);

	recursion(arr, (high + low) / 2, high, 1, size);
	sort_down(arr, (high + low) / 2, high);
	printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
	print_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - Executes the bitonic_sort
 * algorithm
 *
 * @array: The input array
 * @size: The size of the array
 * Return: No return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size, 0, size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_bitonic(array, 0, size);
}
