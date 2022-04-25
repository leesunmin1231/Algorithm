#include <stdio.h>

void insertion_sort(int list[], int n)
{
	int i,j,key;
	for (i = 0; i < n; i++)
	{
		key = list[i];
		for (j = i-1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j+1] = key;
	}
}


int main()
{
	int arr[6] = {4,5,2,8,1,6};
	for (int i = 0; i < 6; i++)
		printf("%d ",arr[i]);
	printf("\n");
	insertion_sort(arr, 6);
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
}
