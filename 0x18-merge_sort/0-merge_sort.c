#include "sort.h"

/**
 * merge - merges left and right arrays
 * @array: pointer to array
 * @size: size of the array
 * @left: pointer to left array
 * @right: pointer to right array
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
		array[k++] = left[i++];

	while (j < size_right)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array with merge sort
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i, j;
	int left[10000];
	int right[10000];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = size / 2;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (j = mid; j < size; j++)
		right[j - mid] = array[j];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
