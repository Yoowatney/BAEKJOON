#include <stdio.h>

int		g_num_arr[20] = { 0, };
int		g_array[20];

void	DFS(int n, int m, int x)
{
	if (m == x)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
	{
		if (num_arr[i])
			continue;
		num_arr[i] = 1;
		array[x] = i;
		DFS(n, m, x + 1);
		num_arr[i] = 0;
	}
}

int		main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	DFS(n, m, 0);
	return 0;
}
