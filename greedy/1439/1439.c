#include <stdio.h>
#include <string.h>

int	min(int a, int b)
{
	return (a > b ? b : a);
}

int main()
{
	char str[1000000];
	
	scanf("%s", str);
	int one = 0;
	int zero = 0;
	long size = strlen(str);
	for (long i = 0; i < size - 1; i++)
	{
		if (str[i] == '0' && str[i + 1] == '1')
			zero++;
		else if (str[i] == '1' && str[i + 1] == '0')
			one++;
	}
	if (str[size - 1] == '0')
		zero++;
	else
		one++;
	printf("%d", min(zero, one));
}
