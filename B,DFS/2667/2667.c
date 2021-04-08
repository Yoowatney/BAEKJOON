#include <stdio.h>
#include <string.h>

int cnt = 0;

int	DFS(int x, int y, int size, int g[][size + 1])
{
	if (x <= 0 || x >= size + 1 || y <= 0 || y >= size + 1)
		return (0);
	if (g[x][y] == 1)
	{
		cnt++;
		g[x][y] = 0;
		DFS(x - 1, y, size, g);
		DFS(x, y - 1, size, g);
		DFS(x + 1, y, size, g);
		DFS(x, y + 1, size, g);
		return (1);
	}
	return (0);
}
int main()
{
	int size;

	scanf("%d", &size);
	int		g[size + 1][size + 1];
//	char	input[size + 2][size + 2];

	memset(g, 0, sizeof(g));
//	for (int i = 1; i < size + 1; i++)
//		scanf("%s", input[i]);
//	for (int i = 1; i < size + 1; i++)
//		for (int j = 1; j < size + 1; j++)
//			g[i][j] = input[i][j - 1] - 48; // scanf("%1d", &variable);

	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			scanf("%1d", &g[i][j]);
		}
	}
	int		result = 0;
	int		arr[625] = {0, };
	int		index = 0;
	int		temp;

	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			if (DFS(i, j, size, g) == 1)
			{
				result++;
				arr[index] = cnt;
				cnt = 0;
				index++;
			}
		}
	}
	printf("%d\n", result);
	for (int i = 0; i < index - 1; i++)
	{
		for (int j = i + 1; j < index; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < index; i++)
		printf("%d\n", arr[i]);
}
