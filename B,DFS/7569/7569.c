#include <stdio.h>
#include <string.h>

int dz[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};

typedef struct __queue 
{
	int x;
	int y;
	int z;
} _queue;

void	BFS(int n, int m, int h, _queue queue[n * m + 1], int g[h][n][m], int move)
{
	int pop_x;
	int pop_y;
	int pop_z;
	int front = 0;

	int rear = move;
	int nx;
	int ny;
	int nz;

	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		pop_z = queue[front].z;
		front++;
		for (int i = 0; i < 6; i++)
		{
			nx = pop_x + dx[i];
			ny = pop_y + dy[i];
			nz = pop_z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 ||
				   	nx >= m || ny >= n || nz >= h)
				continue ;
			if (g[nz][ny][nx] != 0 )
				continue ;
			if (g[nz][ny][nx] == 0)
			{
				g[nz][ny][nx] = g[pop_z][pop_y][pop_x] + 1;
				queue[rear].x = nx;
				queue[rear].y = ny;
				queue[rear].z = nz;
				rear++;
//				printf("\n");
//				for (int k = 0; k < h; k++)
//				{
//					for (int i = 0; i < n; i++) 
//					{
//						for (int j = 0; j < m; j++)
//						{
//							printf("%d ", g[k][i][j]);
//						}
//						printf("\n");
//					}
//					printf("\n----- 층 -----\n");
			}
		}
	}
}

int main()
{
	int n, m, h;
	scanf("%d %d %d", &m, &n, &h); //가로 세로 높이 순
	int g[h][n][m];
	_queue queue[n * m * h];

	memset(queue, 0 , sizeof(queue));
	int move = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &g[k][i][j]);
				if (g[k][i][j] == 1)
				{
					queue[move].x = j;
					queue[move].y = i;
					queue[move].z = k;
					move++;
				}
			}
		}
	};
//	printf("---- start ----\n");
//	for (int k = 0; k < h; k++)
//	{
//		for (int i = 0; i < n; i++) 
//		{
//			for (int j = 0; j < m; j++)
//			{
//				printf("%d ", g[k][i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n----- 층 -----\n");
//	}

	BFS(n, m, h, queue, g, move);
//	for (int k = 0; k < h; k++)
//	{
//		for (int i = 0; i < n; i++) 
//		{
//			for (int j = 0; j < m; j++)
//			{
//				printf("%d ", g[k][i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n----- 층 -----\n");
//	}

	int max = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++)
			{
				if (g[k][i][j] == 0)
				{
					printf("-1");
					return (0);
				}
				if (g[k][i][j] > max)
				{
					max = g[k][i][j];
				}
			}
		}
	}
	printf("%d", max - 1);
}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (g[i][j] == 0)
//			{
//				printf("-1");
//				return (0);
//			}
//			if (g[i][j] > max)
//			{
//				max = g[i][j];
//			}
//		}
//	}
//	printf("%d", max - 1);
