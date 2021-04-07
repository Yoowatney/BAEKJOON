#include <stdio.h>
#include <string.h>

int		cnt = -1;

void	DFS(int here, int N, int g[][N + 1], int visited[N + 1])
{
	if (!(visited[here]))
	{
		visited[here] = 1;
		cnt++;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (g[here][i] != 0 && !visited[i])
			DFS(i, N, g, visited);
	}
}
int main()
{
	int N, M;
	int a, b;

	scanf("%d %d", &N, &M);
	int g[N + 1][N + 1];
	int visited[N + 1];

	memset(g, 0, sizeof(g));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	DFS(1, N, g, visited);
	printf("%d\n", cnt);
}
