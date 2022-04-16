#include <stdio.h>

int *ordinary_mul(int first[][50], int second[][50], int first_row, int first_col, int sec_row, int sec_col)
{
	static int ans[50][50];
	int tmp;
	
	int i, j, h;
	for (i = 0; i < first_row; i++)
	{
		for (h = 0; h < sec_col; h++)
		{
			tmp = 0;
			for (j = 0; j < first_col; j++)
			{
				tmp += first[i][j] * second[j][h];
			}
			ans[i][h] = tmp;
		}
	}
	return (int *)ans;
}

int *arr_plus(int first[][50], int second[][50], int row, int col)
{
	static int ans[50][50];
	int tmp;
	
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			ans[i][j] = first[i][j] + second[i][j];
		}
	}
	return (int *)ans;
}

int *arr_minus(int first[][50], int second[][50], int row, int col)
{
	static int ans[50][50];
	int tmp;
	
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			ans[i][j] = first[i][j] - second[i][j];
		}
	}
	return (int *)ans;
}

int *strassen_mul(int first[][50], int second[][50], int first_row, int first_col, int sec_col)
{
	static int ans[50][50];
	int i, j;
	// first_row = 30, first_col = second_row = 10, sec_col = 50
	int first11[50][50];
	int first12[50][50];
	int first21[50][50];
	int first22[50][50];
	int second11[50][50];
	int second12[50][50];
	int second21[50][50];
	int second22[50][50];
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 5; j++)
		{
			first11[i][j] = first[i][j];
			first12[i][j] = first[i][j+5];
			first21[i][j] = first[i+15][j];
			first22[i][j] = first[i+15][j + 5];
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 25; j++)
		{
			second11[i][j] = second[i][j];
			second12[i][j] = second[i][j+25];
			second21[i][j] = second[i+5][j];
			second22[i][j] = second[i+5][j+25];
		}
	}


	int (*P1)[50] = (void *)ordinary_mul(first11, (void *)arr_minus(second12, second22,5,25),15,5,5,25);
	int (*P2)[50] = (void *)ordinary_mul((void *)arr_plus(first11, first12, 15,5), second22,15,5,5,25);
	int (*P3)[50] = (void *)ordinary_mul((void *)arr_plus(first21, first22,15,5), second11,15,5,5,25);
	int (*P4)[50] = (void *)ordinary_mul(first22, (void *)arr_minus(second21, second11,5,25),15,5,5,25);
	int (*P5)[50] = (void *)ordinary_mul((void *)arr_plus(first11, first22,15,5), (void *)arr_plus(second11, second22,5,25),15,5,5,25);
	int (*P6)[50] = (void *)ordinary_mul((void *)arr_minus(first12,first22,15,5), (void *)arr_plus(second21, second22,5,25),15,5,5,25);
	int (*P7)[50] = (void *)ordinary_mul((void *)arr_minus(first11,first21,15,5), (void *)arr_plus(second11, second12,5,25),15,5,5,25);
	int (*R)[50] = (void *)arr_minus((void *)arr_plus((void *)arr_plus(P5,P4,15,25),P6,15,25),P2, 15,25);
	int (*S)[50] = (void *)arr_plus(P1, P2, 15,25);
	int (*T)[50] = (void *)arr_plus(P3, P4, 15,25);
	int (*U)[50] = (void *)arr_minus((void *)arr_minus((void *)arr_plus(P5,P1,15,25),P3,15,25),P7, 15,25);


	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 25; j++)
		{
			ans[i][j] = R[i][j];
			ans[i][j+25] = S[i][j];
			ans[i+15][j] = T[i][j];
			ans[i+15][j+25] = U[i][j];
		}
	}
	return (int *)ans;
}

int main()
{
	int first_arr[50][50] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	int second_arr[50][50] = {
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};
	printf("ordinary multiplication\n");
	int (*arr)[50] = (void *)ordinary_mul(first_arr, second_arr,30,10,10,50);
	for (int i = 0; i<30; i++)
	{
		for (int j = 0; j< 50; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	
	int (*please)[50] = (void *)strassen_mul(first_arr, second_arr, 30,10,50);
	printf("\n\nstrassen multiplication\n");
	for (int i = 0; i<30; i++)
	{
		for (int j = 0; j< 50; j++)
			printf("%d ",please[i][j]);
		printf("\n");
	}
	//strassen_mul(first_arr, second_arr,30,10,50);
}
