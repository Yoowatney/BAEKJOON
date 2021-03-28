#include <stdio.h>
#include <string.h>

void	DFS(int num_arr[], int arr[], int n, int m, int index)
{
	if (index == m)
	{
		for (int i = 0; i < m - 1; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("%d\n", arr[m - 1]);
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (num_arr[i] == 0)
		{
			for (int j = 0; j < i; j++)
				num_arr[j] = 1;
			num_arr[i] = 1;
			arr[index] = i + 1;
			DFS(num_arr, arr, n, m, index + 1);
			for (int j = 0; j < i; j++)
				num_arr[j] = 0;
			num_arr[i] = 0;
			arr[index] = 0;
		}
	}
}

int	main()
{
	int n,m;
	
	scanf("%d %d", &n, &m);
	int arr[m];
	int num_arr[n];
	memset(arr, 0, sizeof(arr));
	memset(num_arr, 0, sizeof(num_arr));
	
	DFS(num_arr, arr, n, m, 0);
}
