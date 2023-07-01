#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sort integers in ascending order with selection sort
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_i;
	int min;

	for (i = 0; i < size; i++)
	{
		j = i;
		min = array[i];
		while (j < size)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_i = j;
			}
			j++;
		}
		if (array[i] != min)
		{
			array[min_i] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
