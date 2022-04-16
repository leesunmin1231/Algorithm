#include <stdio.h>

int is_palindrome(char *str)
{
	int str_len = 0;
	while(str[str_len])
		str_len++;
	for (int i = 0; i < (str_len/2); i++)
	{
		if (str[i] != str[str_len - 1 - i])
			return (0);
	}
	return (1);
}

int main()
{
	char str1[10] = "hello";
	char str2[10] = "radar";

	if (is_palindrome(str1))
		printf("%s is palindrome\n", str1);
	else
		printf("%s is not palindrome\n", str1);
	if (is_palindrome(str2))
		printf("%s is palindrome\n", str2);
	else
		printf("%s is not palindrome\n", str2);
}
