#include "sort.h"

/**
 * heap_sort - sorts an array of ints in ascending order
 * using Heap Sort algorithm
 *
 * @array: the array of ints to sort
 * @size: the size of the array to sort
 *
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	heap_sort_print(array, size, array, size);
}

/**
 * heap_sort_print - heap sort with full array as parameter for printing
 *
 * @array: array to sort
 * @size: size of array to sort
 * @array_p: array to print
 * @size_p: size of array to print
 *
 */
void heap_sort_print(int *array, size_t size, int *array_p, size_t size_p)
{
	int i = 0, temp = 0;

	for (i = (size - 1) / 2; i >= 0; i--)
	{
		heapify(array, size, i, array_p, size_p);
	}
	for (i = (size - 1); i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		array_p[i] = array[i];
		array_p[0] = array[0];
		print_array(array_p, size_p);

		heapify(array, i, 0, array_p, size_p);
	}
}

/**
 * heapify - reorders array like nodes swapping in a heap
 *
 * @array: the array of ints to sort
 * @size: the size of the array to sort
 * @i: current index in array
 * @array_p: array to print
 * @size_p: size of array to print
 *
 */
void heapify(int *array, size_t size, int i, int *array_p, size_t size_p)
{
	int max = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	int temp = 0;

	if (left_child < (int)size && array[left_child] > array[max])
		max = left_child;
	if (right_child < (int)size && array[right_child] > array[max])
		max = right_child;
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		array_p[i] = array[i];
		array_p[max] = array[max];
		print_array(array_p, size_p);

		heapify(array, size, max, array_p, size_p);
	}
}
