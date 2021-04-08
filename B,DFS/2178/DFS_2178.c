#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		g[101][101];

void	DFS(int x, int y, int n, int m, int num)
{
	if (x <= 0 || x >= n + 1 || y <= 0 || y >= m + 1)
		return ;
//	if (x == n && y == m)
//	{
//		if (g[x][y] > k)
//			g[x][y] = k;
//		return ;
//	}
	if (g[x][y] == 0)
		return ;
	if (g[x][y] > num)
		g[x][y] = num;
	else
		return ;
	//if (g[x][y] == 1)
	//{
	//	g[x][y] = k;
	DFS(x - 1, y, n, m, num + 1);
	DFS(x + 1, y, n, m, num + 1);
	DFS(x, y - 1, n, m, num + 1);
	DFS(x, y + 1, n, m, num + 1);
	//}
}
int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	memset(g, 0, sizeof(g));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			scanf("%1d", &g[i][j]);
			if (g[i][j] == 1)
				g[i][j] = n * m + 1;
		}
	}
	DFS(1, 1, n, m, 1);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
	printf("%d", g[n][m]);
}
