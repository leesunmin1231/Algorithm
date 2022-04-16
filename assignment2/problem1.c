#include <stdio.h>

int main()
{
	int k = 1;
	int num = 2;
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	while (num <= n)
	{
		num *= 2;
		k++;
	}
	if (num > n)
		k--;
	printf("k: %d\n", k);
}
