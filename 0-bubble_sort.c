#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: It is a pointer to an array of integers
 * @size: is an unsigned data type that represents the size of an object in byt
*/
void bubble_sort(int *array, size_t size)
{
	size_t temp = 0;
	size_t index;
	size_t index2;

	if (size < 2 || array == NULL)
	{
		return;
	}
	for (index = 0; index < size; index++)
	{
		for (index2 = 0; index2 < size; index2++)
		{
			if (array[index2] > array[index2 + 1] && array[index2 + 1] != '\0')
			{
				temp =  array[index2];
				array[index2] =  array[index2 + 1];
				array[index2 + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
