#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = strcpy(*b);
	*b = temp;
}

int	main()
{
	char a[] = "12";
	char b[] = "ab";

	printf("%s %s\n", a ,b);
	swap((char **)&a, (char **)&b);
	
	printf("%s %s\n", a ,b);
	return (0);
}
