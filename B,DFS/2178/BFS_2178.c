#include <stdio.h>
#include <string.h>

int g[101][101] = {0, };

typedef struct __queue 
{
	int x;
	int y;
} _queue;
void	BFS(int n, int m, _queue queue[n * m + 1])
{
	int pop_x;
	int pop_y;
	int index = 0;

	queue[index].x = 1;
	queue[index].y = 1;
	index++;
	while (queue)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

		}
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	_queue queue[n * m + 1];

	memset(queue, 0 , sizeof(queue));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &g[i][j]);
		}
	}
	BFS(n, m, queue);
}
