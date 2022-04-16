#include <stdio.h>

void pairSum(int *arr, int sum, int arr_size)
{
	int i;
	int j;
	int output_size = 0;
	int k = 0;

	for (i = 0; i<arr_size; i++)
		for (j = i + 1; j <arr_size; j++)
			if (arr[i] + arr[j] == sum)
				output_size++;
	printf("[");
	for (i = 0; i<arr_size; i++)
	{
		for (j = i+1; j < arr_size; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				printf("'%d+%d'",arr[i],arr[j]);
				k++;
				if (k != output_size)
					printf(",");
			}
		}
	}
	printf("]\n");
}

int main()
{
	int arr[10] = {2, 4, 3, 5, 6, -2, 4, 7, 8, 9};
	pairSum(arr, 7, 10);
}
