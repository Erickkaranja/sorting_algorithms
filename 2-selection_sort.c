#include "sort.h"

/**
* swap_element - function that swaps two elements.
* @element_1: Pointer to the first element.
* @element_2: Pointer to the second elenent.
*/

void swap_element(int *element_1, int *element_2)
{
	int temp;

	temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}

/**
* selection_sort - implements the selection sort algorithm.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		min_idx = array + i;
		for (j = i + 1 ; j < size ; j++)
		{
		min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
		}
		if ((array + i) != min_idx)
		{
			swap_element((array + i), min_idx);
			print_array(array, size);
		}
	}
}
