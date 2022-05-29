#include <stdio.h>

int data[100];

int fibo(int x)
{
	if (x <= 2)
		return 1;
	if (data[x] != 0)
		return data[x];
	else
	{
		data[x] = fibo(x-1) + fibo(x-2);
		return data[x];
	}
}

int main()
{
	printf("fibonacci 5 : %d\n", fibo(5));
	printf("fibonacci 10 : %d\n", fibo(10));
}
