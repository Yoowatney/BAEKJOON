#include <stdio.h>
#include <string.h>

void	BFS(int here, int N, int g[][N + 1], int visited[N + 1], int queue[N])
{
	int front = 0;
	int rear = 1;
	int pop;
	
	visited[here] = 1;
	queue[front] = here;
	printf("%d ", here);
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (int i = 1; i < N + 1; i++)
		{
			if (g[pop][i] != 0 && !visited[i])
			{
				queue[rear] = i;
				visited[i] = 1;
				printf("%d ", i);
				rear++;
			}
		}
	}
}
void	DFS(int here, int N, int g[][N + 1], int visited[N + 1])
{
	if (!visited[here])
	{
		visited[here] = 1;
		printf("%d ", here);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (g[here][i] != 0 && !visited[i])
		{
			DFS(i, N, g, visited);
		}
	}
}

int main()
{
	int N,M,V;
	int a,b;

	scanf("%d %d %d", &N, &M, &V);
	int g[N + 1][N + 1];
	int	visited[N + 1];
	int	queue[N];

	memset(g, 0, sizeof(g));
	memset(visited, 0, sizeof(visited));
	memset(queue, 0 , sizeof(queue));

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	DFS(V, N, g, visited);
	memset(visited, 0 , sizeof(visited));
	printf("\n");
	BFS(V, N, g, visited, queue);
}
