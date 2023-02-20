#include "sort.h"

/**
* max_element - finds the maximum array element.
* @array: The array of search.
* @size: size ofthe given array.
* Return: The maximum element in the array.
*/
int max_element(int *array, size_t size)
{
	int max, i;

	for (max = array[0], i = 1 ; i < (int)size ; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* counting_sort - function that implements the counting sort algorithm.
* @array: The array to be sorted.
*
* @size: The size of the given array.
*/

void counting_sort(int *array, size_t size)
{
	int max, *count, *sorted, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = max_element(array, size);


	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0 ; i < (max +1) ; i++)
		count[i] = 0;

	for (i = 0 ; i < (int)size ; i++)
		count[array[i]] += 1;

	for (i = 0 ; i < (max + 1) ; i++)
	count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0 ; i < (int)size ; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0 ; i < (int)size ; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
