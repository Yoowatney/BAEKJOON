#include <stdio.h>

int arr[9][9] = {0, };
int zeroArr[100][2] = {0, };
int		myindex = 0;
int		isSolve = 0;


void printData()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return ;
}

int	ispromising(int row, int col, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == num)
			return (0);
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][col] == num)
			return (0);
	}
	for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
	{
		for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++)
		{
			if (arr[i][j] == num) 
				return (0);
		}
	}
	return (1);
}

void	DFS(int i)
{
	if (i == myindex)
	{
		printData();
		isSolve = 1;
		return ;
	}
	for (int n = 1; n < 10; n++)
	{
		if (ispromising(zeroArr[i][0], zeroArr[i][1], n))
		{
			arr[zeroArr[i][0]][zeroArr[i][1]] = n;
			if (!isSolve)
				DFS(i + 1);
			arr[zeroArr[i][0]][zeroArr[i][1]] = 0;
		}
	}
}

int	main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				zeroArr[myindex][0] = i;
				zeroArr[myindex][1] = j;
				myindex++;
			}
		}
	}
	DFS(0);
}
