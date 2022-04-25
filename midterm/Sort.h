#ifndef SORT_H
# define SORT_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define MAX_SIZE 10000
#define swap(x,y,t) ( (t) = (y), (y) = (x), (x) = (t))

typedef struct node{
    struct node *next;
    int data;
} Node;

void bubble_sort(int *arr, int size);
void bucket_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void merge_sort(int *arr, int size);
void quick_sort(int *arr, int size);
void radix_sort(int *arr, int size);


# endif
