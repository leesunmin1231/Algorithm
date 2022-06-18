#include<stdio.h>
#include<stdlib.h>

int g_arr[11][11];

void GetCuts(int arr[11], int count){
	int i = 0;
	int j = 0;
	while (j < 11){
		if (arr[i] == 0){
			g_arr[count][j++] = 0;
			i++;
		}
		else if (arr[i] != count && arr[i] != 0){
			int k = 0;
			while (g_arr[arr[i]][k] != 0)
				g_arr[count][j++] = g_arr[arr[i]][k++];
			i++;
		}
		else if (arr[i] == count)
			g_arr[count][j++] = arr[i++];
	}
}

int CutRodAux(int *price, int count, int *r){
	int q;
	int arr[11];
	if (r[count] >= 0)
		return r[count];
	if (count == 0){
		r[count] = 0;
		return 0;
	}
	else{
		q = -2147483648;
		for (int i = 0; i < 11; i++)
			arr[i] = 0;
		for (int i = 1; i <= count; i++){
			int cut = CutRodAux(price,count-i, r);
			if (q > price[i] + cut)
				q = q;
			else{
				arr[0] = i;
				arr[1] = count - i;
				q = price[i] + cut;
			}
		}
	}
	r[count] = q;
	GetCuts(arr, count);
	return q;
}

int *CutRod(int *price, int count){
	int *r = (int *)malloc(sizeof(int) * count+1);
	for (int i = 0; i <= count; i++)
		r[i] = -2147483648;
	CutRodAux(price, count, r);
	return r;
}

int main(){
	int price[11] = {0,1,4,5,7,9,11,13,13,15,16};
	int *r;
	r = CutRod(price, 10);
	for (int i = 1; i < 11; i++){
		printf("Length %d: Price %d, Cuts ", i, r[i]);
		int j = 0;
		while (g_arr[i][j] != 0){
			printf("%d ",g_arr[i][j++]);
		}
		printf("\n");
	}
	free(r);
}
