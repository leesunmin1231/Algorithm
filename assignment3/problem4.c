#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node * right;
	struct _node * left;
} Node;

Node *Create(int root) {
   	Node *tree = (Node *)malloc(sizeof(Node));
    	tree->data = root;
    	tree->right = NULL;
    	tree->left = NULL;
    	return tree;
}

Node *Insert(Node *tree, int data)
{
	if (tree == NULL)
	{
		tree = Create(data);
		return tree;
	}
	Node *parent = NULL;
	Node *tmp = tree;
	while (tmp)
	{
		parent = tmp;
		if (data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;
	if (newNode->data < parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;
	return tree;
}


void Inorder(Node *tree) {
    	if (tree)
    	{
        	Inorder(tree->left);
        	printf("%d ", tree->data);
        	Inorder(tree->right);
    	}
}

Node *Search(Node *tree, int data)
{
	if (tree == NULL || data == tree->data)
		return tree;
	if (data < tree->data)
		return Search(tree->left, data);
	else
		return Search(tree->right, data);
}

void free_tree(Node *tree)
{

	if (tree)
	{
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
	}
}

int find_ancestor(Node *tree, int num1, int num2)
{
	Node *tmp = tree;
	if (!Search(tree, num1) || !Search(tree, num2))
		exit(1);
	while (1)
	{
		if (num1 == tmp->data || num2 == tmp->data)
			return tmp->data;
		else if (tmp->data < num1 && tmp->data < num2)
			tmp = tmp->right;
		else if (tmp->data > num1 && tmp->data > num2)
			tmp = tmp->left;
		else
			return tmp->data;
	}
}

int main(void)
{
    	Node *tree = NULL;
    	tree = Insert(tree, 6);
    	Insert(tree, 2);
    	Insert(tree, 8);
    	Insert(tree, 1);
    	Insert(tree, 3);
    	Insert(tree, 7);
    	Insert(tree, 9);
	printf("Binary search tree: ");
    	Inorder(tree);
	printf("\n");

	int num1;
	int num2;
	printf("First node number: ");
	scanf("%d",&num1);
	printf("Second node number: ");
	scanf("%d",&num2);
	int ancestor = find_ancestor(tree, num1, num2);
	printf("The lowest common ancestor is %d\n", ancestor);
    	free_tree(tree);
}
