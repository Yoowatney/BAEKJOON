#include <stdio.h>

void	print_star(int row, int col,int num)
{
	if ((row / num) % 3 == 1 && (col / num) % 3 == 1)
		printf(" ");
	else
	{
		if (num / 3 == 0)
			printf("*");
		else
			print_star(row, col, num / 3);
	}
}

int	main()
{
	int num;
	int row;
	int col;

	row = 0;
	col = 0;
	scanf("%d", &num);
	while (row < num)
	{
		col = 0;
		while (col < num)
		{
			print_star(row, col, num);
			col++;
		}
		printf("\n");
		row++;
	}
	return (0);
}
