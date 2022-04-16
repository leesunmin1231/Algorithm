#include <stdio.h>

void print_matrix(int mat[5][5], int row, int col)
{
	int tmp;
	int count;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			tmp = mat[i][j];
			count = 0;
			while (tmp > 0)
			{
				count++;
				tmp /= 10;
			}
			for (int k = 0; k<(3 - count); k++)
			       printf(" ");	
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}	
}

void rotate_matrix(int mat[5][5], int row, int col)
{
	int i;
	int j;
	int tmp[5][5];
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
			tmp[i][j] = mat[4 - j][i];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			mat[i][j] = tmp[i][j];
	}
}

int main()
{
	int matrix[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}
		,{16,17,18,19,20},{21,22,23,24,25}};
	printf("original array\n");
	print_matrix(matrix, 5, 5);
	
	rotate_matrix(matrix, 5, 5);
	printf("\nrotate array\n");
	print_matrix(matrix, 5, 5);
	
	rotate_matrix(matrix, 5, 5);
	printf("\nsecond rotate array\n");
	print_matrix(matrix, 5, 5);
}

