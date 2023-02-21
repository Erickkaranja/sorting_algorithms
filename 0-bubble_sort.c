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
* bubble_sort - implements bubble sort algorithm.
*
* @array: The array of integers to be sorted.
* @size: Size of array to be declared.
*
* Description: Prints the array after each swap.
*/

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_element((array + j), (array + j + 1));
				print_array(array, size);
			}
		}
	}
}
