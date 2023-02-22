#include "sort.h"

/**
* swap_element - function that swaps two elements in an array.
* @element_1: First element.
* @element_2: The second element.
*/

void swap_element(int *element_1, int *element_2)
{
	int temp;

	temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}

/**
* shell_sort - implements shell sort.
* @array: The array to be sorted.
* @size: The size of the array to be sorted.
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1 ; gap < (size / 3) ;)
		gap = gap * 3 + 1;
	for (; gap >= 1 ; gap /= 3)
	{
		for (i = gap ; i < size ; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_element(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
