#include <stdio.h>

void	DFS(int n, int m, int num_arr[], int arr[], int index)
{
	if (m == index)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num_arr[i] == 0)
		{
			arr[index] = i + 1;
			num_arr[i] = 1;
		}
	}
}

int	main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	
	int num_arr[n];
	int arr[m];

	DFS(n, m, num_arr, arr, 0);
}
