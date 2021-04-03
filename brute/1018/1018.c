#include <stdio.h>

int		g_col;
int		g_count;
char	g_board1[8][9] = {"WBWBWBWB",
	                   "BWBWBWBW",
					   "WBWBWBWB",
					   "BWBWBWBW",
					   "WBWBWBWB", 
					   "BWBWBWBW",
					   "WBWBWBWB",
					   "BWBWBWBW"};

char g_board2[8][9] = {"BWBWBWBW",
					   "WBWBWBWB",
					   "BWBWBWBW",
					   "WBWBWBWB", 
					   "BWBWBWBW",
					   "WBWBWBWB",
					   "BWBWBWBW",
					   "WBWBWBWB"};

int	count_num(char board[][g_col + 1], int row, int col)
{
	int count1;
	int count2;
	int min1;
	int min2;

	min1 = 64;
	min2 = 64;
	count1 = 0;
	count2 = 0;
	for (int move_bottom = 0; move_bottom <= row - 8; move_bottom++)
	{
		for (int move_right = 0; move_right <= col - 8; move_right++)
		{
			count1 = 0;
			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					if (board[r + move_bottom][c + move_right] 
							!= g_board1[r][c])
					{
						count1++;
					}
				}
			}
			if (count1 < min1)
			{
				min1 = count1;
			}
		}
	}

	for (int move_right = 0; move_right <= col - 8; move_right++)
	{
		for (int move_bottom = 0; move_bottom <= row - 8; move_bottom++)
		{
			count2 = 0;
			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					if (board[r + move_bottom][c + move_right] != g_board2[r][c])
					{
						count2++;
					}
				}
			}
			if (count2 < min2)
			{
				min2 = count2;
			}
		}
	}
	return (min1 > min2 ? min2 : min1);	
}


int	main()
{
	int row;
	int col;
	int temp;

	scanf("%d %d", &row, &col);
	char board[row][col + 1];

	for (int r = 0; r < row; r++)
	{
		scanf("%s", board[r]);
	}
	g_col = col;
	
	temp = count_num(board, row, col);
	printf("%d\n",temp);
}
