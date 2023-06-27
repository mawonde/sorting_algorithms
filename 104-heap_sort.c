#include "sort.h"
#include <stdio.h>
/**
 * swap_nums - Swaps numbers
 *
 * @arr: The input array
 * @a: The first index
 * @b: The second index
 * Return: No return
 */
void swap_nums(int *arr, int a, int b)
{
	arr[a] = arr[a] + arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] = arr[a] - arr[b];
}

/**
 * recursion_heap - The  recursion that builds the max heap tree
 *
 * @arr: The input array
 * @i: The index number
 * @size: The size of the array
 * @limit: The limit of the array
 * Return: No return value
 */
void recursion_heap(int *arr, int i, size_t size, int limit)
{
	int bigger;
	int i2;

	i2 = i * 2;

	if (i2 + 2 < limit)
	{
		recursion_heap(arr, i2 + 1, size, limit);
		recursion_heap(arr, i2 + 2, size, limit);
	}

	if (i2 + 1 >= limit)
		return;

	if (i2 + 2 < limit)
		bigger = (arr[i2 + 1] > arr[i2 + 2]) ? (i2 + 1) : (i2 + 2);
	else
		bigger = i2 + 1;

	if (arr[i] < arr[bigger])
	{
		swap_nums(arr, i, bigger);
		print_array(arr, size);
		recursion_heap(arr, bigger, size, limit);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: The input array
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t limit;

	if (!array || size == 0)
		return;

	i = 0;
	limit = size;

	while (limit > 1)
	{
		recursion_heap(array, i, size, limit);
		if (array[i] >= array[limit - 1])
		{
			swap_nums(array, i, limit - 1);
			print_array(array, size);
		}
		limit--;
	}
}
