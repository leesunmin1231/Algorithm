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


double check_time(int *arr, int *origin, int size, void (*fp)(int *, int))
{
	clock_t start, end;
	start = clock();
	fp(arr, size);
	end = clock();
	double runtime = (double)(end - start);
	//print_array(arr, size);
	printf("%d size array execution time : %.0lf ms \n", size, runtime);
	init_array(arr, origin, size);
	return runtime;
}

int number_of_digits(int n)
{
   	if(n == 0){
		return 0;
    	}
    	while(n != 0)
    	{
        	return 1 + number_of_digits(n/10);
    	}
    	return 0;
}

void print_result(double bubble, double bucket, double insertion, double merge, double quick, double radix)
{
	printf(" %.0lf ms", bubble);
	for (int i = 0; i < (strlen("bubble sort") - 2 - number_of_digits((int)bubble)); i++)
		printf(" ");
	printf("|");
	printf(" %.0lf ms", bucket);
	for (int i = 0; i < (strlen("bucket sort") - 2 - number_of_digits((int)bucket)); i++)
		printf(" ");
	printf("|");
	printf(" %.0lf ms", insertion);
	for (int i = 0; i < (strlen("insertion sort") - 2 - number_of_digits((int)insertion)); i++)
		printf(" ");
	printf("|");
	printf(" %.0lf ms", merge);
	for (int i = 0; i < (strlen("merge sort") - 2 - number_of_digits((int)merge)); i++)
		printf(" ");
	printf("|");
	printf(" %.0lf ms", quick);
	for (int i = 0; i < (strlen("quick sort") - 2 - number_of_digits((int)quick)); i++)
		printf(" ");
	printf("|");
	printf(" %.0lf ms", radix);
	for (int i = 0; i < (strlen("radix sort") - 2 - number_of_digits((int)radix)); i++)
		printf(" ");
	printf("|\n");
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
	double bubble1 = check_time(arr1, origin1, ARR_SIZE1, bubble_sort); 
	double bubble2 = check_time(arr2, origin2, ARR_SIZE2, bubble_sort); 
	double bubble3 = check_time(arr3, origin3, ARR_SIZE3, bubble_sort); 

	puts(" \n * bucket sort \n ");
	double bucket1 = check_time(arr1, origin1, ARR_SIZE1, bucket_sort);
	double bucket2 = check_time(arr2, origin2, ARR_SIZE2, bucket_sort);
	double bucket3 = check_time(arr3, origin3, ARR_SIZE3, bucket_sort);

	puts(" \n * insertion sort \n ");
	double insertion1 = check_time(arr1, origin1, ARR_SIZE1, insertion_sort);
	double insertion2 = check_time(arr2, origin2, ARR_SIZE2, insertion_sort);
	double insertion3 = check_time(arr3, origin3, ARR_SIZE3, insertion_sort);


	puts(" \n * merge sort \n ");
	double merge1 = check_time(arr1, origin1, ARR_SIZE1, merge_sort);
	double merge2 = check_time(arr2, origin2, ARR_SIZE2, merge_sort);
	double merge3 = check_time(arr3, origin3, ARR_SIZE3, merge_sort);
	
	puts(" \n * quick sort \n ");
	double quick1 = check_time(arr1, origin1, ARR_SIZE1, quick_sort);
	double quick2 = check_time(arr2, origin2, ARR_SIZE2, quick_sort);
	double quick3 = check_time(arr3, origin3, ARR_SIZE3, quick_sort);

	puts(" \n * radix sort \n ");
	double radix1 = check_time(arr1, origin1, ARR_SIZE1, radix_sort);
	double radix2 = check_time(arr2, origin2, ARR_SIZE2, radix_sort);
	double radix3 = check_time(arr3, origin3, ARR_SIZE3, radix_sort);


	char str[10] = "reverse";
	if (argc > 1 && !strcmp(argv[1], "random"))
		strcpy(str, "random");
	printf("\nResult Table (when %s array)\n", str);
	printf("+-----+-------------+-------------+----------------+------------+------------+------------+\n");
	printf("|     | bubble sort | bucket sort | insertion sort | merge sort | quick sort | radix sort |\n");
	printf("+-----+-------------+-------------+----------------+------------+------------+------------+\n");
	printf("|1000 |");
	print_result(bubble1, bucket1, insertion1, merge1, quick1, radix1);
	printf("+-----+-------------+-------------+----------------+------------+------------+------------+\n");
	printf("|5000 |");
	print_result(bubble2, bucket2, insertion2, merge2, quick2, radix2);
	printf("+-----+-------------+-------------+----------------+------------+------------+------------+\n");
	printf("|10000|");
	print_result(bubble3, bucket3, insertion3, merge3, quick3, radix3);
	printf("+-----+-------------+-------------+----------------+------------+------------+------------+\n");
	
}

