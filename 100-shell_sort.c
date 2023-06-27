#include "sort.h"
/**
 * shell_sort - Sorts an array
 * of integers in ascending order using the
 * Shell sort algorithm
 *
 * @array: The input arrray
 * @size: The size of the array
 * Return: No  return value
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}
/**
 * _ssort - An auxiliar function for
 * shell_sort function
 * @a: The input arrray
 * @size: The size of the array
 * @n: intervale
 * Return: No return value
 */
void _ssort(int *a, int size, int n)
{
	int tmp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
