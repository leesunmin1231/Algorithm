#include <stdio.h>

int binary_search(int *arr, int find, int start, int end)
{
	int mid = (end + start)/2;
	if (end == start)
		return -1;
	if (find == arr[mid])
		return (mid);
	else if (find > arr[mid])
		return binary_search(arr, find, mid + 1, end);
	else if (find < arr[mid])
		return binary_search(arr, find, start, mid - 1);
	return (-1);
}

int main()
{
	int index;
	int arr[9] = {12, 34, 37, 45, 57, 82, 99, 120, 134};
	int to_find = 120;
	index = binary_search(arr, to_find, 0, 8);
	if (index != -1)
		printf("%d is located in Array index %d.\n", to_find, index);
	else
		printf("Number is not in array.\n");
}
