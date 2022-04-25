#include "Sort.h"

void counting_sort(int *arr, int size, int *digit_arr)
{
	int max = 0;
	int i;
	for(i = 0; i < size; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	int B[MAX_SIZE];
	int tmp[10];
	for (i = 0; i < 10; i++)
		tmp[i] = 0;
	for (i = 0; i<size; i++)
		tmp[digit_arr[i]]++;
	for (i = 1; i<=max; i++)
		tmp[i] = tmp[i-1] + tmp[i];
	for (i = size - 1; i>=0; i--){
		B[tmp[digit_arr[i]]-1] = arr[i];
		tmp[digit_arr[i]]--;
	}
	for (i = 0; i<size; i++)
		arr[i] = B[i];
}

int is_arr_empty(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] != 0)
			return 0;
	return 1;
}	

void radix_sort(int *arr, int size)
{
	int i;
	int tmp[MAX_SIZE];
	int digit_arr[MAX_SIZE];
	int count = 0;
	for (i = 0; i < size; i++)
		tmp[i] = arr[i];
	while (!is_arr_empty(tmp, size))
	{
		for (i = 0; i < size; i++)
			tmp[i] = arr[i] / pow(10, count);
		for (i = 0; i < size; i++)
			digit_arr[i] = tmp[i] % 10;
		count++;
		counting_sort(arr,size,digit_arr);
	}
}
