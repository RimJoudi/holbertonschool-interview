#ifndef SORT_H_
#define SORT_H_

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heap_sort_print(int *array, size_t size, int *array_p, size_t size_p);
void heapify(int *array, size_t size, int i, int *array_p, size_t size_p);

#endif
