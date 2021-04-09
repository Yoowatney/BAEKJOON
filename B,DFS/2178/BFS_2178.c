#include <stdio.h>
#include <string.h>

int g[101][101] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


typedef struct __queue 
{
	int x;
	int y;
} _queue;
void	BFS(int n, int m, _queue queue[n * m + 1])
{
	int pop_x;
	int pop_y;
	int front = 0;

	int rear = 0;
	int nx;
	int ny;

	queue[rear].x = 1;
	queue[rear].y = 1;
	rear++;
	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		front++;
		for (int k = 0; k < 4; k++)
		{
			nx = pop_x + dx[k];
			ny = pop_y + dy[k];
			if (nx <= 0 || ny <= 0 || nx >= n + 1 || ny >= m + 1)
				continue ;
			if (g[nx][ny] == 0)
				continue ;
			if (g[nx][ny] == 1)
			{
				g[nx][ny] = g[pop_x][pop_y] + 1;
				queue[rear].x = nx;
				queue[rear].y = ny;
				rear++;
			}
		}
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	_queue queue[n * m + 1];

	memset(queue, 0 , sizeof(queue));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			scanf("%1d", &g[i][j]);
		}
	}
	BFS(n, m, queue);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}

}
