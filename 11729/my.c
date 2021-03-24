#include <stdio.h>

void	hanoi2(int n, int from, int to)
{
	int middle;

	middle = 6 - from - to;
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return ;
	}
	hanoi2(n - 1, from, middle);
	hanoi2(1, from, to);
	hanoi2(n - 1, middle, to);
}

int		hanoi1(int n)
{
	if (n == 1)
		return (1);
	return (2 * hanoi1(n - 1) + 1);
}

int	main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", hanoi1(n));
	hanoi2(n, 1, 3);
	return (0);
}
