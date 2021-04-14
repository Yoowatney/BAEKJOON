#include <stdio.h>

int g[7][7] = 
{
	{0,1,0,0,0,1,1},
	{1,0,1,1,0,0,0},
	{0,1,0,0,1,0,0}, 
	{0,1,0,0,0,0,0},
	{0,0,1,0,0,0,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0}
};
int queue[7] = {0, };
int visited[7] = {0, };

void	DFS(int here)
{
	int i;

	if (visited[here])
		return ;
	printf("%d를 방문\n", here);
	visited[here] = 1;
	
	for (i = 0; i < 7; i++)
	{
		if (g[here][i] == 1 && !visited[i])
			DFS(i);
	}
}

void	BFS(int v, int N)
{
	int front = 0;
	int rear = 0;
	int pop, i;

	printf("%d을 방문\n", v);
	queue[0] = v;
	rear++;
	visited[v] = 1;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (i = 0; i <= N; i++)
		{
			if (g[pop][i] == 1 && !visited[i])
			{
				printf("%d를 방문\n ", i);
				queue[rear] = i;
				rear++;
				visited[i] = 1;
			}
		}
	}
	return ;
}

int main()
{
//	DFS(0);
	BFS(0, 6);
}
