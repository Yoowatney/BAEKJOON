#include <stdio.h>
#include <stdlib.h>

void Path_Fining(int**map, int x, int y, int m, int n,int num)
{

	if (x < 0 || y < 0 || x >= m || y >= n)
		return;
	if (map[x][y] == 0)
		return;
	if (map[x][y] > num)
	{
		map[x][y] = num;
	}
	else
		return;
	Path_Fining(map, x - 1, y, m, n, num + 1);
	Path_Fining(map, x + 1, y, m, n, num + 1);
	Path_Fining(map, x, y - 1, m, n, num + 1);
	Path_Fining(map, x, y + 1, m, n, num + 1);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int** map = (int**)malloc(sizeof(int*) * m);
	for (int i = 0;i < m;i++)
	{
		map[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1)
				map[i][j] = m * n + 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return (0);
	Path_Fining(map, 0, 0, m, n, 1);
	printf("%d\n", map[m - 1][n - 1]);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++)
		free(map[i]);
	free(map);
}
