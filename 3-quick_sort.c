#include "sort.h"

/**
  * quick_sort - sorts an array of integers in ascending order.
  * @array: array to be sorted.
  * @size: size of the array.
  *
  *
  */
void quick_sort(int *array, size_t size)
{

	lomuto_qsort(array, 0, size - 1, size);
}

/**
  * lomuto_qsort - sort an array of integers
  * @array: array to be sorted.
  * @lo: first element in array.
  * @hi: last element in array.
  * @size: size of the array.
  *
  */
void lomuto_qsort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		lomuto_qsort(array, lo, p - 1, size);
		lomuto_qsort(array, p + 1, hi, size);
	}
}

/**
  * partition - divide the array into into.
  * @array: array to be partition.
  * @lo: first element of the array.
  * @hi: last element in the array.
  * @size: size of the array.
  *
  * Return: the index of the array from where the check should begin.
  */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1, j, tmp;

	for (j = lo; j <= hi; j++)
	{
		if (array[j]  <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	return (i);
}
