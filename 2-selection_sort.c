#include "sort.h"

/**
 * swap_ints - Two integers in an array should be switched.
 * @a: The first integer to switched.
 * @b: The second integer to switched.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Utilizing the selection sort algorithm, sort an array of
 *                  numbers orderly.
 * @array: An array of integers.
 * @size: The array size.
 * Description: Prints the array after each switched.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
