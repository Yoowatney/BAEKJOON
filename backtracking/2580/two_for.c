#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	printData(int arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int	ispromising(int row, int col, int num, int arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == num && i != col)
		{
			return (0);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i][col] == num && i != row)
			return (0);
	}

	int rrow = row / 3;
	int ccol = col / 3;
	for (int i = 3 * rrow; i < 3 + 3 * rrow; i++)
	{
		for (int j = 3 * ccol; j < 3 + 3 * ccol; j++)
			if (arr[i][j] == num && i != row && j != col)
				return (0);
	}
	return (1);
}

void	DFS(int arr[][9], int from, int to)
{
	if (from == to)
	{
		printData(arr);
		exit(0);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = 1; k < 10; k++)
					if (ispromising(i, j, k, arr))
					{
						arr[i][j] = k;
						DFS(arr, from + 1, to);
					}
				arr[i][j] = 0;
			}
		}
	}
}

int	main()
{
	int arr[9][9];
	int cnt;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				cnt++;
		}
	}

	DFS(arr, 0, cnt);
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d",cnt);


//	for (int i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("%d", arr[i][j]);
//		printf("\n");
//	}
}
