#include <stdio.h>
#include <stdlib.h>

int **make_array(int n)
{
    	int i;
    	int **arr = (int**)malloc(0);
    	for (i = 0; i < n; i++)
        	arr[i] = (int*)malloc(sizeof(int)*n);
    	return arr;
}

void print_order(int i, int j, int *order[])
{
    	int k;
    	if(i == j)
	{
        	printf("A%d", i);
	}
    	else {
        	k = order[i][j];
        	printf("(");
        	print_order(i,k,order);
        	print_order(k+1, j,order);
        	printf(")");
    	}
}

int min_mult(int n, int p[], int *order[])
{
	int i, j, k, diag, min_k = 0;
	int **M, temp = 0;
	M = make_array(n+1);
	for(i = 1; i <= n; i++)
       		M[i][i] = 0;
    	for(diag = 1; diag <= n-1; diag++)
	{
		for(i = 1; i <= n - diag;i++) {
            		j = i + diag;
            		for(k = i; k <= j-1; k++) {
                		M[i][j] = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
                		if(i == k) {
                    			temp = M[i][j];
                    			min_k = k;
                		}
				else if(M[i][j] > temp) {
                    			M[i][j] = temp;
                		}
				else
                    			min_k = k;
            		}
            		order[i][j] = min_k;
        	}
	}
    	return M[1][n];
}

int main()
{
    	int **order;
	int p[4] = {5,3,7,10};
    	int number = 3;
	int result;
	int a[100][100];
	int b[100][100];
	int c[100][100];
	int tmp[100][100];
	int final[100][100];

	int i,j,k;
    	printf("Number of array: %d\n", number);

    	for (i = 0; i < 4; i++)
		printf("p%d: %d\n", i, p[i]);
    	order = make_array(number);

    	result = min_mult(number, p, order);
    	printf("\nOptimal chain Order: ");
    	print_order(1, number, order);
    	printf("\nMinimum number of computations: %d\n", result);
	printf("\nfirst array\n");
	for (i = 0; i < p[0]; i++)
	{
		for (j = 0; j < p[1]; j++)
		{
			a[i][j] = rand()%10;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nsecond array\n");
	for (i = 0; i < p[1]; i++)
	{
		for (j = 0; j < p[2]; j++)
		{
			b[i][j] = rand()%10;
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\nthird array\n");
	for (i = 0; i < p[2]; i++)
	{
		for (j = 0; j < p[3]; j++)
		{	
			c[i][j] = rand()%10;
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < p[1]; i++)
	{
		for(j = 0; j < p[3]; j++){
			tmp[i][j] = 0;
			for(k = 0; k < p[2]; k++)
				tmp[i][j] += b[i][k] * c[k][j];
		}
	}
	for(i = 0; i < p[0]; i++)
	{
		for(j = 0; j < p[3]; j++){
			final[i][j] = 0;
			for(k = 0; k < p[1]; k++)
				final[i][j] += a[i][k] * tmp[k][j];
		}
	}
	printf("\nResult array\n");	
	for(i = 0; i < p[0]; i++){
		for(j = 0; j < p[3]; j++)
			printf("%d ", final[i][j]);
		printf("\n");
	}
    	return 0;
}
