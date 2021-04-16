#include <stdio.h>
#include <string.h>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct __queue 
{
	int x;
	int y;
} _queue;

void	BFS(int n, int m, _queue queue[n * m + 1], int g[][n], int move)
{
	int pop_x;
	int pop_y;
	int front = 0;

	int rear = move;
	int nx;
	int ny;

//	queue[rear].x = 1;
//	queue[rear].y = 1;
//	rear++;
	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		front++;
		for (int i = 0; i < 4; i++)
		{
			nx = pop_x + dx[i];
			ny = pop_y + dy[i];
			if (nx < 0 || ny < 0 || nx > m || ny > n)
				continue ;
			if (g[nx][ny] != 0 )
				continue ;
			if (g[nx][ny] == 0)
			{
				g[nx][ny] = g[pop_x][pop_y] + 1;
				queue[rear].x = nx;
				queue[rear].y = ny;
				rear++;
				printf("\n---- result ----\n");
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						printf("%d ", g[i][j]);
					}
					printf("\n");
				}
			}
//			if (g[nx][ny] == 1)
//			{
//				printf("Hi");
//				g[nx][ny] = g[pop_x][pop_y] + 1;
//				queue[rear].x = nx;
//				queue[rear].y = ny;
//				rear++;
//			}
		}
	}
}

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int g[m][n];
	_queue queue[n * m];

	memset(queue, 0 , sizeof(queue));
	int move = 0;
	for (int i = 0; i < m; i++) // n width, m height
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &g[i][j]);
			if (g[i][j] == 1)
			{
				queue[move].x = i;
				queue[move].y = j;
				move++;
			}
		}
	}
	printf("\n ---------- before ---------- \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < m + 1; j++)
//		{
//			scanf("%1d", &g[i][j]);
//		}
//	}
	BFS(n, m, queue, g, move);
	printf("\n ---------- after ---------- \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
//	printf("%d", g[n][m]);
}
