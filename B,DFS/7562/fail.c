#include <stdio.h>
#include <string.h>

typedef struct point2D 
{
	int x;
	int y;
} point2D;

int min = 2147483647;

void	dfs(int now_x, int now_y, point2D want, int l, int val, int visited[][l]);

int main()
{
	int t;
	scanf("%d", &t);
	int l;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &l);
		int visited[l][l];
		memset(visited, 0, sizeof(visited));
		int now_x, now_y;
		point2D want;
		scanf("%d %d", &now_x, &now_y);
		scanf("%d %d", &want.x, &want.y);
		dfs(now_x, now_y, want, l, 0, visited);
	}
}

void	dfs(int now_x, int now_y, point2D want, int l, int val, int visited[][l])
{
	if (now_x >= l || now_y >= l || now_x < 0 || now_y < 0 || val >= min)
		return ;
	if (visited[now_y][now_x])
		return ;
	if (now_x == want.x && now_y == want.y)
	{
		// min 비교
		printf("------- new --------\n");
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				printf("%d ", visited[i][j]);
			}
			printf("\n");
		}
		min = min > val ? val : min;
		printf("min : %d\n", min);
		memset(visited, 0, sizeof(*visited));
		return ;
	}
	visited[now_y][now_x] = 1;

//	if (now_x <= want.x || now_y <= want.y)
//	{
		dfs(now_x + 2, now_y + 1, want, l, val + 1, visited);
		dfs(now_x + 1, now_y + 2, want, l, val + 1, visited);
//	}
//	if (now_x <= want.x || now_y >= want.y)
//	{
		dfs(now_x + 2, now_y - 1, want, l, val + 1, visited);
		dfs(now_x + 1, now_y - 2, want, l, val + 1, visited);
//	}
//	if (now_x >= want.x || now_y >= want.y)
//	{
		dfs(now_x - 2, now_y - 1, want, l, val + 1, visited);
		dfs(now_x - 1, now_y - 2, want, l, val + 1, visited);
//	}
//	if (now_x >= want.x || now_y <= want.y)
//	{
		dfs(now_x - 2, now_y + 1, want, l ,val + 1, visited);
		dfs(now_x - 1, now_y + 2, want, l ,val + 1, visited);
//	}
}
