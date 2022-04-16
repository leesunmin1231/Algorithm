#include <stdio.h>

int main()
{
	int x = 3, y = 2, z = 5;
	printf("%d\n", ((x > y) ? x : y) > z ? ((y > x) ? x : y) : z);
}
