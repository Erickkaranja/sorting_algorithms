#include "sort.h"

/**
* shell_sort - implements shell sort.
* @array: The array to be sorted.
* @size: The size of the array to be sorted.
*/

void shell_sort(int *array, size_t size)
{
	int i, j, tmp, increment;

	for (increment = size / 2 ; increment > 0 ; increment /= 2)
	{
	for (i = increment ; i < (int)size ; i++)
	{
		tmp = array[i];
		for (j = i ; j >= increment ; j -= increment)
		{
			if (tmp < array[j - increment])
			{
				array[j] = array[j - increment];
			}
			else
			{
				break;
			}
		}
		array[j] = tmp;
	}
	print_array(array, size);
	}
}
