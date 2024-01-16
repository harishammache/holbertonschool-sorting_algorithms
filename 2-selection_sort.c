#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - Function that sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t array_index, next_index, min_index;

	if (array == NULL || size < 2)
		return;

	for (array_index = 0; array_index < size - 1; array_index++)
	{
		min_index = array_index;

		for (next_index = array_index + 1; next_index < size; next_index++)
		{
			if (array[next_index] < array[min_index])
				min_index = next_index;
		}

		if (min_index != array_index)
		{
			temp = array[array_index];
			array[array_index] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
