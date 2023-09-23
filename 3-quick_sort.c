#include "sort.h"


void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * swap_ints - Switch two integers in an array.
 * @a: The first integer to be switched.
 * @b: The second integer to be switched.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - Order a subset of an array of integers in ensuing
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The symbol array.
 * @size: The  size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort -The quicksort method is carried out through recursion.
 * @array: An array of symbol to sort.
 * @size: The size of the array.
 * @left: The array partition order's initial index.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - an array of integers sorted in ascending
 *              pattern using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The array size.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */


void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
