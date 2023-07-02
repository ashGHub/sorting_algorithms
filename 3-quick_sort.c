#include <stdio.h>
#include "sort.h"

/**
 * partition - finds the pivot index that
 *             split the array into two
 * @array: input array
 * @size: size of the array
 * @l: left index
 * @r: right index
 *
 * Description: rearranges the array on pivot
 *              where the left of the pivot are small numbers
 *              and to the right of the pivot are larger numbers
 *              This is called lomuto partition
 * Return: pivot index
 */
int partition(int *array, size_t size, int l, int r)
{
	int tmp, i = (l - 1);

	/* here r is starting pivot index */
	while (l <= r)
	{
		/* only swap when neccessary */
		if (array[l] < array[r] && array[++i] != array[l])
		{
			tmp = array[i];
			array[i] = array[l];
			array[l] = tmp;
			print_array(array, size);
		}
		l++;
	}
	/* position the pivot number */
	/* only swap when neccessary */
	if (array[++i] != array[r])
	{
		tmp = array[i];
		array[i] = array[r];
		array[r] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * qs - quick sort the array using recursion
 * @size: size of the array
 * @array: input array
 * @l: left index
 * @r: right index
 */
void qs(int *array, size_t size, int l, int r)
{
	int p;

	if (l >= r)
	{
		return;
	}
	p = partition(array, size, l, r);
	qs(array, size, l, p - 1);
	qs(array, size, p + 1, r);

}

/**
 * quick_sort - sort integers in ascending order with quick sort
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	qs(array, size, 0, ((int)size) - 1);
}
