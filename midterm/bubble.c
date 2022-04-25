#include "Sort.h"

void bubble_sort(int *arr, int size)
{
	int i, j, tmp;

	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1], tmp);
		}
	}
}
