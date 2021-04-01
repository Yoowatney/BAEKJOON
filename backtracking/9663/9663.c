#include <stdio.h>
#include <string.h>

int		g_count = 0;

void	DFS(int depth, int n, int arr[])
{
	for (int i = 0; i < depth - 1; i++)
	{
		if (arr[i] == arr[depth - 1] ||
			depth - 1 - i == arr[depth - 1] - arr[i] ||
			depth - 1 - i == arr[i] - arr[depth - 1])
			return ;
	}
	if (depth == n)
	{
		g_count++;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		arr[depth] = i;
		DFS(depth + 1, n, arr);
	}
}

int	main()
{
	int n;

	scanf("%d", &n);
	int arr[n];

	memset(arr, 0, sizeof(arr));
	DFS(0, n, arr);
	printf("%d\n", g_count);
}
