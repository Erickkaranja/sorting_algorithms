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
