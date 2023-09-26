#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);


/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to be swapped.
 *
 * @b: The second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * hoare_partition - An integer array's subset should be arranged using the
 *             Hoare partition algorithm.
 * @array: The integers array.
 *
 * @size: The size of the array .
 * @left: The subset's initial beginning index to order.
 *
 * @right: The subset's final index to order.
 * Return: The final partition index.
 *
 * Description: Pivots on the final component of the partition.
 * After every two element swap, prints the array.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}


/**
 * hoare_sort -Employ recursion to implement the quicksort algorithm.
 * @array: An array of integers to be sorted.
 *
 * @size: The size of the array.
 * @left: The array partition order's initial index.
 *
 * @right: The array partition's final index in sequence.
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}


/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: The integers' array.
 *
 * @size: The size of the array .
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
