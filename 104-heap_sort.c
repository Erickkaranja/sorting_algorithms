#include "sort.h"

/**
* swap_element - function that swaps two elements.
* @element_1: Pointer to the first element.
* @element_2: Pointer to the second element.
*/

void swap_element(int *element_1, int *element_2)
{
	int temp;

	temp = *element_1;
	*element_1 = *element_2;
	*element_2 = temp;
}

/**
* heapify - to heapify a subtree rooted with node i which is an index in array.
* @array: Subtree to be heapified
* @size: This the size of the heap array.
* @i :root of any subtree.
*/

void heapify(int *array, int i, size_t size)
{
	int largest, left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;

	/*swap and continue heapifying if root is not largest*/
	if (largest != i)
	{
		swap_element(array + i, array + largest);
		/*Recursively heapify remaining subtree.*/
		heapify(array, largest, size);
	}
}

/**
* heap_sort - sorts an array of integers using heap sort.
* @array: The array of integers to be sorted.
* @size: The size of the array.
*/

void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1 ; (i = 0) ; i--)
		heapify(array, i, size);

	for (i = size - 1 ; (i = 0) ; i--)
	{
		swap_element(array + 0, array + i);
		heapify(array, i, 0);
		print_array(array, size);
	}
}
