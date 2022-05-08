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

void free_tree(Node *tree)
{

	if (tree)
	{
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
	}
}

int isBST(Node *node)
{
	if (node == NULL)
		return 1;
	else if (node->left != NULL && node->left->data > node->data)
		return 0;
	else if (node->right != NULL && node->right->data < node->data)
		return 0;
	else if (!isBST(node->left) || !isBST(node->right))
		return 0;
	return 1;
}

int main(void)
{
    	Node *n1 = Create(8);
    	Node *n2 = Create(3);
    	Node *n3 = Create(9);
    	Node *n4 = NULL;
    	Node *n5 = NULL;
    	Node *n6 = Create(4);
    	Node *n7 = Create(7);
    	n1->left = n2;
    	n1->right = n3;
    	n2->left = n4;
    	n2->right = n5;
    	n3->left = n6;
    	n3->right = n7;
	if (isBST(n1))
		printf("It is BST\n");
	else
		printf("It is not BST\n");
    	free_tree(n1);
}
