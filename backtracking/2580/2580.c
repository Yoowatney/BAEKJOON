#include <stdio.h>
#include <string.h>

int		num_arr[10] = {0, };
int		zero_arr[9] = {0, };
int		g_sign = 1;
int		cnt;

int	count_zero(int arr[][9])
{
	int cnt;
	int i;
	int j;

	cnt = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	return (cnt);
}

void	promising_row(int arr[][9])
{
	int j;

	for (int i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			num_arr[arr[i][j]] = 1;
		}
		for (j = 1; j < 10; j++)
		{
			if (num_arr[j] == 0)
				return ;
		}
	}


//	printf("\n\n-----^ input output v-----\n\n");
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("%d", arr[i][j]);
//		printf("\n");
//	}

	memset(num_arr, 0, sizeof(num_arr));
	for (int i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			num_arr[arr[j][i]] = 1;
		}
		for (j = 1; j < 10; j++)
		{
			if (num_arr[j] == 0)
				return ;
		}
		memset(num_arr, 0, sizeof(num_arr));
	}

	printf("\n\n-----^ input output v-----\n\n");

	for (int i = 0; i < 9; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("%d", arr[i][j]);
		printf("\n");
	}
	g_sign = 0;
}

void	DFS(int arr[][9], int from, int to)
{
	int i;
	int j;
	int k;
	int array[10] = {0, };

//	if (from == to)
//	{
		promising_row(arr);
//		return ;
//	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			array[arr[i][j]] = 1;
		}
		for (j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
			{
				for (k = 1; k < 10; k++)
				{
					if (array[k] == 0)
					{
						arr[i][j] = k;
						array[k] = 1;
//						printf("%d%d : %d\n",i, j, k);
						if (g_sign)
							DFS(arr, from + 1, to);
					}
					array[k] = 0;
				}
				arr[i][j] = 0;
			}
		}
		memset(array, 0, sizeof(array));
	}
}

int	main()
{
	int arr[9][9];
//	int j;
	int total;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				cnt++;
		}
	}
	total = count_zero(arr);
	DFS(arr, 0, total);


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
