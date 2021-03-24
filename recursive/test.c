#include <stdio.h>

void	rec(int n)
{
	if (n == 0)
		return ;
	printf("*");
	rec(n - 1);
}

void	new_line(int current, int max)
{
	if (current > max)
		return ;
	rec(current);
	printf("\n");
	
	new_line(current + 1, max);
}

int	main()
{
	int n;

	n = 3;
	new_line(1, 3);
}
