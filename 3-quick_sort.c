#include  "sort.h"
/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto - Lomuto scheme for Quick Sort
 * @array: Array to be partitioned
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partitioning
 */
int lomuto(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * quick_sort_recursive - Recursive function to implement Quick Sort
 * @array: Array to be sorted
 * @left: Starting index of the array
 * @right: Ending index of the array
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto(array, size, left, right);

		quick_sort_recursive(array, size, left, part - 1);
		quick_sort_recursive(array, size, part + 1, right);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

