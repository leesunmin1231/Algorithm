#include <stdio.h>

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

void quicksort(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	int pivot_idx;

	pivot_idx = get_pivot(arr, start, end);
	quicksort(arr, start, pivot_idx - 1);
	quicksort(arr, pivot_idx + 1, end);
}

int main()
{
	int arr[7] = {10, 80, 30, 90, 40, 50, 70};
	for (int i = 0; i < 7; i++)
		printf("%d ",arr[i]);
	quicksort(arr, 0, 6);
	printf("\n");
	for (int i = 0; i < 7; i++)
		printf("%d ",arr[i]);
}
	
