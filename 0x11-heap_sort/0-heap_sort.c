#include "sort.h"
/**
 * swap - swaps two integers
 * @x: int
 * @y: int
 *
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * max_h - turns an array into a max heap
 * @array: array of integers
 * @index: current given index within array
 * @size: size of the array
 * @len: size to use as boundaries
 *
 */
void max_h(int *array, int index, int size, int len)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int max = index;

	if (left > 0 && left < len && array[left] > array[max])
		max = left;
	if (right > 0 && right < len && array[right] > array[max])
		max = right;
	if (max != index)
	{
		swap(array + max, array + index);
		print_array(array, size);
		max_h(array, max, size, len);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 *             order using the Heap sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	int i = (size / 2) - 1;
	int end = size - 1;

	while (i >= 0)
	{
		max_h(array, i, size, size);
		i--;
	}

	while (end > 0)
	{
		swap(array + end, array);
		print_array(array, size);
		max_h(array, 0, size, end);
		end--;
	}
}
