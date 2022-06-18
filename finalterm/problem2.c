#include <stdio.h>
#include <stdlib.h>

#define	MAX_QUEUE_SIZE 8
#define ARR_SIZE 8
#define True 1
#define False 0

typedef int Bool;
typedef struct{
	struct _node *queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

typedef struct _node{
	char color;
	char name;
	int index;
	int distance;
	struct _node *pi;
} node;

int is_empty(QueueType *q){
	return (q->front == q->rear);
}

int is_full(QueueType *q){
	return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

QueueType *create(void){
	QueueType *new_queue = (QueueType *)malloc(sizeof(QueueType));
	new_queue->front = 0;
	new_queue->rear = 0;
	return new_queue;
}

void enqueue(QueueType *q, node *item)
{
	if (is_full(q)){
		printf("(SYSTEM) ADDQUEUE() FAIL. QueueFull\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

node *dequeue(QueueType *q)
{
	if (is_empty(q)){
		printf("DELETEQUEUE() FAIL. QueueEmpty\n");
		return 0;
	}
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
void BFS(int Graph[ARR_SIZE][ARR_SIZE], int start, char *name_arr){
	int i;
	node *vertex[ARR_SIZE];
	for (i = 0; i < ARR_SIZE; i++){
		vertex[i] = (node *)malloc(sizeof(node));
		vertex[i]->name = name_arr[i];
		vertex[i]->index = i;
		vertex[i]->color = 'w';
		vertex[i]->distance = 2147483647;
		vertex[i]->pi = NULL;
	}
	vertex[start]->color = 'g';
	vertex[start]->distance = 0;
	vertex[start]->pi = NULL;
	QueueType *q = create();
	enqueue(q, vertex[start]);
	node *u, v;
	while (!is_empty(q)){
		u = dequeue(q);
		for (i = 0; i < ARR_SIZE; i++){
			if (Graph[u->index][i] && vertex[i]->color == 'w'){
				vertex[i]->color = 'g';
				vertex[i]->distance = u->distance + 1;
				vertex[i]->pi = u;
				enqueue(q, vertex[i]);
			}
		}
		u->color = 'b';
		char pre;
		if (u->pi == NULL)
			pre = '0';
		else
			pre = u->pi->name;
		printf("vertex: %c, distance: %d, pi: %c\n", u->name, u->distance, pre);
	}
}

int main()
{
	int Graph[ARR_SIZE][ARR_SIZE] = {
		{0,1,0,0,1,0,0,0},
		{1,0,0,0,0,1,0,0},
		{0,0,0,1,0,1,1,0},
		{0,0,1,0,0,0,1,1},
		{1,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,1,0},
		{0,0,1,1,0,1,0,1},
		{0,0,0,1,0,0,1,0}
	};
	char name[ARR_SIZE] = {'r','s','t','u','v','w','x','y'};
	BFS(Graph, 1, name);
}
	
