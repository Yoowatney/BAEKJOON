#include <stdio.h>
#include <string.h>

char	g_array[3000][3000];

void	set_array(int row, int col, int num)
{
	int r;
	int c;

	r = 0;
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
			if (!(r == 1 && c == 1))
				set_array(row + (r * (num / 3)), col + (c * (num / 3)), num / 3);
			c++;
		}
		r++;
	}
}

int	main()
{
	int row;
	int col;
	int num;

	scanf("%d", &num);
	row = 0;
	memset(g_array, ' ', sizeof(g_array));
	set_array(0, 0, num);
	while (row < num)
	{
		col = 0;
		while (col < num)
		{
			printf("%c",g_array[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	return (0);
}
