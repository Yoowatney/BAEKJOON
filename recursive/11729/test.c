#include <stdio.h>

void	hanoi1(int from, int to, int n)
{
	int middle;

	middle = 6 - from - to;
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return ;
	}
	if (n == 2)
	{
		hanoi1(from, middle, 1);
		hanoi1(from, to, 1);
		hanoi1(middle, to, 1);
	}

	if (n == 3)
	{
		hanoi1(from, to, 1);
		hanoi1(from, middle, 1);
		hanoi1(to, middle, 1);
		hanoi1(from, to, 1);
		hanoi1(middle, from, 1);
		hanoi1(middle, to, 1);
		hanoi1(from, to, 1);
	}
}

void	hanoi2(int from, int to, int n)
{
	int middle;

	middle = 6 - from - to;
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return ;
	}
	if (n >= 2)
	{
		hanoi2(from, middle, n - 1);
		hanoi2(from, to, 1);
		hanoi2(middle, to, n - 1);
	}
}

int	main()
{
	int num;

	num = 3;
	printf("------------------hanoi1---------------------\n");
	hanoi1(1, 3, num);
	printf("------------------hanoi2---------------------\n");
	hanoi2(1, 3, num);
}
