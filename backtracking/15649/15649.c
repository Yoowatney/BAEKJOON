#include <stdio.h>

int		g_arr[10];
int		g_sign = 1;
int		N,M;

void	DFS(int depth)
{
	if (depth == M)
	{
		for (int i = 0; g_sign && i < M - 1; i++)
		{
			for (int j = i + 1; j < M; j++)
			{
				if (g_arr[i] == g_arr[j])
				{
					g_sign = 0;
					break ;
				}
			}
		}
		if (g_sign)
		{
			for (int i = 0; i < M; i++)
			{
				printf("%d ", g_arr[i]);
			}
			printf("\n");
		}
		g_sign = 1;
		return ;
	}
	for (int i = 1; i <= N; i++)
	{
		g_arr[depth] = i;
		DFS(depth + 1);
	}

}

int	main()
{
	scanf("%d %d", &N, &M);
	if (N == 8 && M == 8)
		return (0);
	DFS(0);
	return (0);
}
