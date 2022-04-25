#include "Sort.h"

int get_pivot(int *arr, int start, int end)
{
	int pivot = arr[end];
	int tmp;
	int i = -1;
	int j = 0;
	while (j < end)
	{
		if (arr[j] < pivot){
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
		j++;
	}
	arr[end] = arr[++i];
	arr[i] = pivot;
	return (i);
}	

void quick_recur(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	int pivot_idx;

	pivot_idx = get_pivot(arr, start, end);
	quick_recur(arr, start, pivot_idx - 1);
	quick_recur(arr, pivot_idx + 1, end);
}

void quick_sort(int *arr, int size)
{
	quick_recur(arr, 0, size-1);
}
