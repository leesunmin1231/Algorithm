#include "Sort.h"
#include <time.h>

#define ARR_SIZE 10

void init_array(int *arr, int *origin, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
		arr[i] = origin[i];
}

void print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[ARR_SIZE] = {11,9,21,8,17,19,13,1,24,12};
	int origin[ARR_SIZE] = {11,9,21,8,17,19,13,1,24,12};
	clock_t bubble_s, bubble_e, bucket_s, bucket_e, insertion_s, insertion_e, merge_s, merge_e, quick_s, quick_e, radix_s, radix_e;
	float bubble, bucket, insertion, merge, quick, radix;
	int i;
	printf("original arr\n");
	print_array(arr, ARR_SIZE);
	
	puts(" \n * bubble sort \n ");
	bubble_s = clock();
	bubble_sort(arr, ARR_SIZE);
	bubble_e = clock();
	bubble = (float)(bubble_e - bubble_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", bubble);
	
	init_array(arr, origin, ARR_SIZE);
	puts(" \n * bucket sort \n ");
	bucket_s = clock();
	bucket_sort(arr, ARR_SIZE);
	bucket_e = clock();
	bucket = (float)(bucket_e - bucket_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", bucket);

	init_array(arr, origin, ARR_SIZE);
	puts(" \n * insertion sort \n ");
	insertion_s = clock();
	insertion_sort(arr, ARR_SIZE);
	insertion_e = clock();
	insertion = (float)(insertion_e - insertion_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", insertion);

	init_array(arr, origin, ARR_SIZE);
	puts(" \n * merge sort \n ");
	merge_s = clock();
	merge_sort(arr, ARR_SIZE);
	merge_e = clock();
	merge = (float)(merge_e - merge_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", merge);

	init_array(arr, origin, ARR_SIZE);
	puts(" \n * quick sort \n ");
	quick_s = clock();
	quick_sort(arr, ARR_SIZE);
	quick_e = clock();
	quick = (float)(quick_e - quick_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", quick);

	init_array(arr, origin, ARR_SIZE);
	puts(" \n * radix sort \n ");
	radix_s = clock();
	radix_sort(arr, ARR_SIZE);
	radix_e = clock();
	radix = (float)(radix_e - radix_s)/CLOCKS_PER_SEC;
	print_array(arr, ARR_SIZE);
	printf("time : %.3f \n", radix);
}

