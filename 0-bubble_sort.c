#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sort integers in ascending order with bubble sort
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 1; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
