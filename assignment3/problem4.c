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


void Preorder(Node *tree) {
    	if (tree)
    	{
        	printf("%d ", tree->data);
        	Preorder(tree->left);
        	Preorder(tree->right);
    	}
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
    Preorder(tree);
    free_tree(tree);

}
