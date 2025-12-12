#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition_lomuto - Partitions array using Lomuto scheme
 * @array: Array to partition
 * @low: Starting index of partition
 * @high: Ending index of partition (pivot is array[high])
 * @size: Size of the whole array (for printing)
 *
 * Return: Final pivot index
 */
static int partition_lomuto(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high && array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_rec - Recursively sorts array using Quick sort (Lomuto)
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the whole array (for printing)
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition_lomuto(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * (Lomuto partition scheme)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
