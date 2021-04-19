#include <stdio.h>
#include <string.h>

int cnt = 0;

int	DFS(int i, int j, int x, int y, int arr[][x]);
int main()
{
	int x, y, k;
	
	scanf("%d %d %d", &y, &x, &k);
	int arr[y + 1][x + 1];
	memset(arr, 0, sizeof(arr));
//	for (int i = 0; i <= y; i++)
//	{
//		for (int j = 0; j <= x; j++)
//		{
//			printf("%d ", arr[y - i][j]);
//		}
//		printf("\n");
//	}
	int a, b;
	int c, d;

	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &b);
		scanf("%d %d", &c, &d);
		for (int y_temp = b; y_temp <= d; y_temp++)
		{
			for (int x_temp = a; x_temp <= c; x_temp++)
			{
				arr[y_temp][x_temp] = 1;
			}
		}
	}
	printf("\n----- before -----\n");
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			printf("%d ", arr[y - i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i <= y - 1; i++)
	{
		for (int j = 0; j <= x - 1; j++)
		{
			if (arr[i][j] != 1 && arr[i][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i + 1][j + 1] != 1)
			{
				cnt++;
				continue ;
			}
			break ;
		}
	}

	printf("\n----- answer -----\n");
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			printf("%d ", arr[y - i][j]);
		}
		printf("\n");
	}
//	int result = 0;
//	int temp[6000] = {0,};
//	int index = 0;
//	
//	for (int i = 0; i <= y; i++)
//	{
//		for (int j = 0; j <= x; j++)
//		{
//			if (DFS(i, j, x, y, arr) == 1)
//			{
//				result++;
//				temp[index] = cnt;
//				cnt = 0;
//				index++;
//			}
//		}
//	}
//	int small;
//	for (int i = 0; i < index - 1; i++)
//	{
//		for (int j = i + 1; j < index; j++)
//		{
//			if (temp[i] > temp[j])
//			{
//				small = temp[j];
//				temp[j] = temp[i];
//				temp[i] = small;
//			}
//		}
//	}
//	printf("cnt : %d\n", result);
//	for (int i = 0; i < index; i++)
//	{
//		printf("%d\n", temp[i]);
//	}
//}
//
//int	DFS(int i, int j, int x, int y, int arr[][x])
//{
//	if (i < 0 || j < 0 || i > y + 1 || j > x + 1)
//		return (0);
//	if (arr[i][j] == 0)
//	{
//		cnt++;
//		arr[i][j] = 1;
//		DFS(i - 1, j, x, y, arr);
//		DFS(i + 1, j, x, y, arr);
//		DFS(i, j + 1, x, y, arr);
//		DFS(i, j - 1, x, y, arr);
//		return (1);
//	}
//	return (0);
//}
