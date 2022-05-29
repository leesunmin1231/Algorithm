#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int temp = 0;

void MatrixChain( int *p, int (*m)[10], int (*t)[10], int length)
{
	int n = length - 1;
	int i, j, k, q;
	int num = 0;

	for( i=1; i<length; i++ )
	{
		m[i][i] = 0;
	}

	for( i=2; i<=n; i++ )
	{
		for( j=1; j<=n-i+1; j++ )
		{
			k = j+i-1;
			m[j][k] = 0x7fffffff;

			for( q=j; q<=k-1; q++ )
			{
				num = m[j][q] + m[q+1][k] + p[j-1] * p[q] * p[k];

				if( num < m[j][k] )
				{
					m[j][k] = num;
					t[j][k] = q;
				}
			}
		}
	}
 }

void Print( int(*t)[10], int i, int j, FILE *fp )
{
	if( i == j )
	{
		fprintf(fp, "%d", i);

		if( temp != 0 )
		{
			fprintf(fp, " ");
			temp = 0;
			return;
		}
		temp++;
	}
	else
	{
		fprintf(fp, "(");

		Print(t, i, t[i][j], fp);
		Print(t, t[i][j]+1, j, fp);

		fprintf(fp, ")");
		temp = 0;
	}
}

int main()
{
	FILE *fp;
	int i;
	int total;
	char fname[100];
	printf("input file name?\n");
	scanf("%s", fname);

	if( !strstr(fname, ".txt") )
		strcat(fname, ".txt");

	fp = fopen(fname, "r");

	if( fp == NULL )
	{
		fprintf(stderr, "File %s not found\n", fname);
		exit(1);
	}
	fscanf(fp, "%d ", &total);

	int p[10];
	for( i=0; i<total; i++ )
		fscanf(fp, "%d ", &p[i]);

	int m[10][10], t[10][10];
	MatrixChain(p, m, t, 10);
	MatrixChain(p, m, t, 10);

	fclose(fp);
	fp = fopen("output.txt", "w");
	Print(t,1,6, fp);

	fclose(fp);
	system("pause");
	return 0;
}
