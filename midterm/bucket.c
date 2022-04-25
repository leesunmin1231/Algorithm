#include "Sort.h"

Node *Create()
{
	Node *new_list = (Node *)malloc(sizeof(Node));
	new_list->data = 0;
	new_list->next = NULL;
	return new_list;
}

void Push(Node *list, int num)
{
	Node *tmp;
	if (list->data == 0)
	{
		list->data = num;
		return;
	}
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = NULL;
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int Pop(Node *list)
{
	Node *tmp;
	while (list->next)
	{
		tmp = list;
		list = list->next;
	}
	tmp->next = NULL;
	return list->data;
}

void sort_list(Node *list)
{
	if (list->data == 0)
		return;
	int i,j,size,key;
	size = 0;
	Node *tmp = list;
	int arr[MAX_SIZE];
	while (tmp)
	{
		arr[size] = tmp->data;
		tmp = tmp->next;
		size++;
	}

	for (i = 0; i < size; i++)
	{
		key = arr[i];
		for (j = i-1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j+1] = key;
	}
	size = 0;
	while (list)
	{
		list->data = arr[size++];
		list = list->next;
	}
}

int list_to_arr(Node *list, int *arr, int index)
{
	if (list->data == 0)
		return index;
	while (list)
	{
		arr[index++] = list->data;
		list = list->next;
	}
	return index;
}

void free_all_list(Node *list)
{
	Node *tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void bucket_sort(int *arr, int size)
{
	int max = arr[0];
	int min = arr[0];
	int index = 0;
	int bucket_num = size / 20;
	if (size % 20 != 0)
		bucket_num++;
	Node **bucket_arr = malloc(sizeof(Node *) * bucket_num);
	if (bucket_arr == 0)
		return; 
	int i;
	for (i = 0; i < bucket_num; i++)
		bucket_arr[i] = Create();
	for (i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	int gap = (max - min + 1) / bucket_num + 1;
	for (i = 0; i < size; i++)
		Push(bucket_arr[arr[i] / gap], arr[i]);
	for (i = 0; i < bucket_num; i++)
		sort_list(bucket_arr[i]);
	for (i = 0; i < bucket_num; i++)
		index = list_to_arr(bucket_arr[i], arr, index);
	for (i = 0; i < bucket_num; i++)
		free_all_list(bucket_arr[i]);
	free(bucket_arr);
}
