#include <stdio.h>
#include <string.h>

int arr[51][51];

int DFS(int x, int y, int n, int m);

int main()
{
	int T;
	int n,m,k;
	int row, col;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d %d", &col, &row);
			arr[row + 1][col + 1] = 1;
		}
		int cnt = 0;
//		for (int row = 1; row < n + 1; row++)
//		{
//			for (int col = 1; col < m + 1; col++)
//			{
//				printf("%d ", arr[row][col]);
//			}
//			printf("\n");
//		}
		for (int row = 1; row < n + 1; row++)
		{
			for (int col = 1; col < m + 1; col++)
			{
				if (DFS(row, col, n, m) == 1)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}

int	DFS(int x, int y, int n, int m)
{
	if (x <= 0 || y <= 0 || x >= n +1 || y >= m + 1)
		return (0);
	if (arr[x][y] == 1)
	{
		arr[x][y] = 0;
		DFS(x - 1, y, n, m);
		DFS(x + 1, y, n, m);
		DFS(x, y + 1, n, m);
		DFS(x, y - 1, n, m);
		return (1);
	}
	return (0);
}
