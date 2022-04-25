#include "Sort.h"
#include <time.h>
#include <string.h>

#define ARR_SIZE1 1000
#define ARR_SIZE2 5000
#define ARR_SIZE3 10000

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

void random_array(int *arr, int size)
{
	int i,j;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		arr[i] = rand()% size + 1;
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				i--;
	}
}

void reverse_array(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		arr[i] = size - i;
}


void check_time(int *arr, int *origin, int size, void (*fp)(int *, int))
{
	clock_t start, end;
	start = clock();
	fp(arr, size);
	end = clock();
	double runtime = (double)(end - start)/CLOCKS_PER_SEC;
	//print_array(arr, size);
	printf("%d size array execution time : %.5lf \n", size, runtime);
	init_array(arr, origin, size);
}

int main(int argc, char **argv)
{
	int arr1[ARR_SIZE1];
	int arr2[ARR_SIZE2];
	int arr3[ARR_SIZE3];
	int origin1[ARR_SIZE1];
	int origin2[ARR_SIZE2];
	int origin3[ARR_SIZE3];


	if (argc != 1 && strcmp(argv[1], "random") == 0)
	{
		printf("random array\n");
		random_array(arr1, ARR_SIZE1);
		random_array(arr2, ARR_SIZE2);
		random_array(arr3, ARR_SIZE2);
	}
	else
	{
		printf("reverse array\n");
		reverse_array(arr1, ARR_SIZE1);
		reverse_array(arr2, ARR_SIZE2);
		reverse_array(arr3, ARR_SIZE3);
	}
	init_array(origin1, arr1, ARR_SIZE1);
	init_array(origin2, arr2, ARR_SIZE2);
	init_array(origin3, arr3, ARR_SIZE3);
		

	//printf("original arr\n");
	//print_array(arr1, ARR_SIZE1);
	//print_array(arr2, ARR_SIZE2);
	//print_array(arr3, ARR_SIZE3);
	
	puts(" \n * bubble sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, bubble_sort); 
	check_time(arr2, origin2, ARR_SIZE2, bubble_sort); 
	check_time(arr3, origin3, ARR_SIZE3, bubble_sort); 

	puts(" \n * bucket sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, bucket_sort);
	check_time(arr2, origin2, ARR_SIZE2, bucket_sort);
	check_time(arr3, origin3, ARR_SIZE3, bucket_sort);

	puts(" \n * insertion sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, insertion_sort);
	check_time(arr2, origin2, ARR_SIZE2, insertion_sort);
	check_time(arr3, origin3, ARR_SIZE3, insertion_sort);


	puts(" \n * merge sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, merge_sort);
	check_time(arr2, origin2, ARR_SIZE2, merge_sort);
	check_time(arr3, origin3, ARR_SIZE3, merge_sort);
	
	puts(" \n * quick sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, quick_sort);
	check_time(arr2, origin2, ARR_SIZE2, quick_sort);
	check_time(arr3, origin3, ARR_SIZE3, quick_sort);

	puts(" \n * radix sort \n ");
	check_time(arr1, origin1, ARR_SIZE1, radix_sort);
	check_time(arr2, origin2, ARR_SIZE2, radix_sort);
	check_time(arr3, origin3, ARR_SIZE3, radix_sort);
}

