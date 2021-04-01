#include <stdio.h>

void	DFS(int n, int m, int arr[], int index)
{
	int j;

	if (m == index)
	{
		for (j = 0; j < m - 1; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("%d", arr[j]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		arr[index] = i + 1;
		DFS(n, m, arr, index + 1);
	}
}

int	main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	int arr[m];
	DFS(n, m, arr, 0);
	
}
