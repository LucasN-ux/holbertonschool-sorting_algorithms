#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: number of elements
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t jmin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jmin])
				jmin = j;
		}

		if (jmin != i)
		{
			temp = array[i];
			array[i] = array[jmin];
			array[jmin] = temp;
			print_array(array, size);
		}
	}
}
