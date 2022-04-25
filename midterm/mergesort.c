#include <stdio.h>

#define MAX_ARR_SIZE 10000

void merge(int *arr, int left, int mid, int right)
{
	int i = left;
	int j = mid+1;
	int k = left;
	int tmp[MAX_ARR_SIZE];

	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	for (int a = left; a <= right; a++)
		arr[a] = tmp[a];
}

void merge_sort(int *arr, int left, int right)
{
	int mid = left;
	if (left < right)
	{
		mid = (left+right)/2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
	}
	merge(arr, left, mid, right);
}
