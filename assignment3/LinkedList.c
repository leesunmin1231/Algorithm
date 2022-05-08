#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct ListNode {
	int data;
	struct ListNode *next;
} ListNode;

void print_data(ListNode *p)
{
	printf("%d -> ",p->data);
	if (p->next == NULL)
		printf("NULL\n");
}

void free_node(ListNode *p)
{
	if (p == NULL)
		return;
	free(p);
}

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* Append(ListNode *list, int value)
{
	if (list == NULL)
	{
		list = (ListNode *)malloc(sizeof(ListNode));
		list->data = value;
		list->next = NULL;
		return list;
	}
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->next = NULL;
	ListNode *tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = p;
	return list;
}

void Traverse(ListNode *list, void (*fp)(ListNode *))
{
	if (list == NULL)
	{
		printf("List is Empty.\n");
		return ;
	}
	ListNode *tmp = list;
	while (tmp)
	{
		tmp = list->next;
		fp(list);
		list = tmp;
	}
}

ListNode*  Insert(ListNode *list, int index, int value)
{
	if (list == NULL && index == 0)
		return Append(list, value);
	else if (list == NULL)
		error("IndexError\n");
	ListNode *prev = list;
	ListNode *tmp = list->next;
	for (int i = 1; i < index; i++)
	{
		if (tmp == NULL)
		{
			Traverse(list, free_node);
			error("IndexError\n");
		}
		tmp = tmp->next;
		prev = prev->next;
	}
	if (prev == NULL)
	{
		Traverse(list, free_node);
		error("IndexError\n");
	}
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	if (index == 0)
	{
		p->next = list;
		return p;
	}
	p->next = tmp;
	prev->next = p;
	return list;
}

ListNode* Remove(ListNode *list, int index)
{
	if (list == NULL)
		error("list is empty\n");
	if (index == 0)
	{
		ListNode *removed = list;
		list = removed->next;
		free(removed);
		return list;
	}
	if (index == 1 && list->next == NULL)
	{
		free(list);
		list = NULL;
		error("IndexError\n");
	}
	ListNode *prev = list;
	ListNode *removed = list-> next;
	for (int i = 1; i < index; i++)
	{
		if (removed == NULL)
		{
			Traverse(list, free_node);
			error("IndexError\n");
		}
		removed = removed->next;
		prev = prev->next;
	}
	if (removed == NULL)
	{
		Traverse(list, free_node);
		error("IndexError\n");
	}
	prev->next = removed->next;
	free(removed);
	return list;
}

ListNode *Reverse(ListNode *list)
{
	ListNode *rev = NULL;
	while (list)
	{
		rev = Insert(rev, 0, list->data);
		list = list->next;
	}
	return rev;
}
