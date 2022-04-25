#include <stdio.h>
#include <stdlib.h>

void countingSort(int *arr, int size)
{
	int max = 0;
	int i;
	for(i = 0; i < size; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	int *B = (int *)malloc(sizeof(int) * size);
	if (B == 0)
		return;
	int *tmp = (int *)malloc(sizeof(int) * (max + 1));
	if (tmp == 0)
		return;	
	for (i = 0; i<(max + 1); i++)
		tmp[i] = 0;
	for (i = 0; i<size; i++)
		tmp[arr[i]]++;
	for (i = 1; i<=max; i++)
		tmp[i] = tmp[i-1] + tmp[i];
	for (i = size - 1; i>=0; i--){
		B[tmp[arr[i]]-1] = arr[i];
		tmp[arr[i]]--;
	}
	for (i = 0; i<size; i++)
		arr[i] = B[i];
	free(B);
	free(tmp);
}

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int array[] = { 6,0,2,0,1,3,4,6,1,3,2};
	int n = sizeof(array)/sizeof(array[0]);
	printArray(array,n);
	countingSort(array, n);
	printArray(array,n);
}
