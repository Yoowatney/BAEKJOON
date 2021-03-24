#include <stdio.h>
#include <string.h>

char	g_array[300][300];

void	fill_board(int row, int col, int num)
{
	int div;
	int r;
	int c;

	r = 0;
	div = num / 3;
	if (num == 1)
	{
		g_array[row][col] = '*';
		return ;
	}

	while (r < 3)
	{
		c = 0;
		while (c < 3)
		{
			if (r != 1 || c != 1)
				fill_board(row + (r * div), col + (c * div), div);
			c++;
		}
		r++;
	}
}

int	main()
{
	int num;
	int row;
	int col;
	
	row = 0;
	scanf("%d", &num);
	memset(g_array, ' ', sizeof(g_array));
	fill_board(0, 0, num);

	while (row < num)
	{
		col = 0;
		while (col < num)
		{
			printf("%c", g_array[row][col]);
			col++;
		}
		row++;
		printf("\n");
	}
}
