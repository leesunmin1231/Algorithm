#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct ListNode {
	int data;
	struct ListNode *next;
} ListNode;

void print_data(ListNode *p);
void free_node(ListNode *p);
void error(char *message);
ListNode* Append(ListNode *list, int value);
void Traverse(ListNode *list, void (*fp)(ListNode *));
ListNode*  Insert(ListNode *list, int index, int value);
ListNode* Remove(ListNode *list, int index);
ListNode *Reverse(ListNode *list);

#endif
