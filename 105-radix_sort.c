#include "sort.h"

/**
* get_max - function that finds the maximum number in an array.
* @array: The array of check.
* @size: Size of the given array.
*
* Return: The maximum element in the array.
*/

int get_max(int *array, size_t size)
{
	int max, i;

	max = array[0];
	for (i = 1 ; i < (int)size ; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
* counting_sort - implements the counting sort algorithm.
* @array: The array to be sorted.
* @size: The size of the given array.
* @place: ... ..
*/

void countingSort(int *array, size_t size, int place)
{
	int *sorted, *count, max, i;

	if (array == NULL || size < 2)
		return;

	max = (array[0] / place) % 10;
	for (i = 1 ; i < (int)size ; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		free(sorted);
	return;

	for (i = 0 ; i < max ; i++)
		count[i] = 0;
	/**calculating count of elements*/
	for (i = 0 ; i < (int)size ; i++)
		count[(array[i] / place) % 10]++;
	/**calculating cumulative count*/
	for (i = 1 ; i < 10 ; i++)
		count[i] = count[i - 1];

	for (i = size - 1 ; i >= 0 ; i--)
	{
		sorted[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0 ; i < (int)size ; i++)
		array[i] = sorted[i];
}

/**
* radix_sort - sorts a given array of integers using radix sort algorithm.
* @array: The array to be sorted.
* @size: The size of the sorted array.
*/

void radix_sort(int *array, size_t size)
{
	int max, place;

	max = get_max(array, size);
	for (place = 1 ; max / place > 0 ; place *= 10)
		countingSort(array, size, place);
	print_array(array, size);
}
