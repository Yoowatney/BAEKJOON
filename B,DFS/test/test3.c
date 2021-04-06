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

int visited[7] = {0, };
int queue[7] = {0, };

void	BFS(int v)
{
	int front = 0;
	int rear = 0;
	int i, pop;
	
	queue[0] = v;
	visited[v] = 1;
	printf("%d를 방문\n", v);
	rear++;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (i = 0; i < 7 ; i++)
		{
			if (g[pop][i] == 1 && !visited[i])
			{
				visited[i] = 1;
				printf("%d를 방문\n", i);
				queue[rear] = i;
				rear++;
			}
		}
	}
	return ;
}

int main()
{
	BFS(0);
}
