#include <stdio.h>

int	g_array[3][24];

int	hanoi(int num)
{
	if (num == 1)
		return (1);
	else
		return (2 * (hanoi(num - 1) + 1) - 1);
}

void	move(int from, int to, int n)
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
		move(from, middle, n - 1);
		move(from, to, 1);
		move(middle, to, n - 1);
	}
}


int	main()
{
	int num;

	num = 6;
//	printf("hanoi %d :%d\n", num, hanoi(num));
	move(1, 3, 3);
}
