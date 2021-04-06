#include <stdio.h>
#include <string.h>

int N;

void	BFS(int here, int g[][N], int visited[N], int queue[N])
{
	int front = 0;
	int rear = 1;
	int pop, i;

	visited[here] = 1;
	printf("%d ", here + 1);
	queue[front] = here;
	while (front < rear)
	{
		pop = queue[front] + 1;
		front++;
		for (i = 0; i < N; i++)
		{
			if (g[pop - 1][i] != 0 && !visited[i])
			{
				visited[i] = 1;
				printf("%d ", i + 1);
				queue[rear] = i;
				rear++;
			}
		}		
	}
}

void	DFS(int here, int g[][N], int visited[N])
{
	visited[here] = 1;
	printf("%d ", here + 1);

	for (int i = 0; i < N; i++)
	{
		if (g[here][i] != 0 && !visited[i])
			DFS(i, g, visited);
	}
}

int main()
{
	int a, b;
	int M, V;

	scanf("%d %d %d", &N, &M, &V);
	int	g[N][N];
	memset(g, 0, sizeof(g));
	int visited[N];
	memset(visited, 0 ,sizeof(visited));
	int queue[N];
	memset(queue, 0, sizeof(queue));

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		g[a - 1][b - 1] = 1;
		g[b - 1][a - 1] = 1;
	}
	DFS(V - 1, g, visited);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	BFS(V - 1, g, visited, queue);
}
