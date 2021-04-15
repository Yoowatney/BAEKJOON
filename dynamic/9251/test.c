#include <stdio.h>

int main()
{
	char str[50];

	str[0] = 'h';
	scanf("%s", str + 1);
	printf("%s", str);
}
