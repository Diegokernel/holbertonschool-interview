#include "sort.h"


/**
 * heap_sort - Heap Sort
 * @array: array of numbers
 * @size: Size of the array
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{
	size_t lon = size, rt, tp;
	ssize_t i_ult, dad;
	int tempA;

	if (size < 2)
		return;
	while (lon > 1)
	{
		i_ult = size - 1;
		dad = (i_ult - 1) / 2;
		while (dad >= 0)
		{
			dad--;
			rt = dad;
			while ((2 * rt + 1) < lon)
			{
				tp = rt;
				if (array[(2 * rt + 1)] > array[rt])
					tp = (2 * rt + 1);
				if (2 * rt + 2 < lon && array[2 * rt + 2] > array[tp])
					tp = 2 * rt + 2;
				if (tp == rt)
					break;
				tempA = array[rt];
				array[rt] = array[tp];
				array[tp] = tempA;
				print_array(array, size);
				rt = tp;
			}
		}
		tempA = array[0];
		array[0] = array[lon - 1];
		array[lon - 1] = tempA;
		print_array(array, size);
		lon--;
	}
}
