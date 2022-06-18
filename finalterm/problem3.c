#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5
#define INF 1000

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0, 3, 5, INF, INF},
	{ INF, 0, 2, 6, INF},
	{ INF, 1, 0, INF, 6},
	{ INF, INF, INF, 0, 2},
	{ 3, INF, INF, 7, 0}};
int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int path[MAX_VERTICES][MAX_VERTICES];
int check[MAX_VERTICES];

void path_init(int path[][MAX_VERTICES]){
	int i,j;
	for(i=0;i<MAX_VERTICES;i++)
		for(j=0;j<MAX_VERTICES;j++)
			path[i][j] = INF;
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && ! found[i]){
			min = distance[i];
			minpos=i;
		}
	}
	return minpos;
}

void shortest_path(int start, int n)
{
	int i, j, u, w;
	for (i = 0; i < n; i++)
	{
		distance[i] = weight[start][i];
		found[i] = FALSE;
		check[i] = 1;
		path[i][0] = start;
	}
	found[start] = TRUE;
	distance[start] = 0;
	for (i = 0; i<n-2; i++)
	{
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
		{
			if(!found[w])
			{
				if (distance[u]+weight[u][w] < distance[w])
				{
					if (i==0)
					{
						path[w][check[w]] = u;
						check[w]++;
					}
					else{
						for(j = 0; j<(check[u]+1); j++)
						{
							path[w][j] = path[u][j];
							path[w][j+1] = u;
							check[w]++;
						}
					}
					distance[w] = distance[u] + weight[u][w];
				}
			}
		}
	}
}

int main()
{
	int i, j;
	char start, end;
	char vertax[MAX_VERTICES] = {'s','t','y','x','z'};
	path_init(path);
	printf("Start: ");
	scanf("%c", &start);
	getchar();
	printf("End: ");
	scanf("%c", &end);
	i = 0;
	while (vertax[i] != start)
		i++;
	shortest_path(i, MAX_VERTICES);
	i = 0;
	while (vertax[i] != end)
		i++;
	printf("Path: ");
	for (j = 0; j < MAX_VERTICES; j++){
		if(path[i][j]!=INF){
			printf("%c-",vertax[path[i][j]]);
		}
	}
	printf("%c\n",vertax[i]);
	printf("Distance: %d\n",distance[i]);
}
