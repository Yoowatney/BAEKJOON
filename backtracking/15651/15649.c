#include <stdio.h>
#include <string.h>

void	DFS(int n, int m, int num_arr[], int arr[], int index)
{
	if (m == index)
	{
		for (int i = 0; i < m - 1; i++)
		{
			printf("%d ", arr[i]); 
		}
		printf("%d", arr[m - 1]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (num_arr[i] == 0)
		{
			arr[index] = i + 1;
			num_arr[i] = 1;
			DFS(n, m, num_arr, arr, index + 1);
			num_arr[i] = 0;
			arr[index] = 0;
			memset(arr, 0, sizeof(arr));
			memset(num_arr, 0, sizeof(num_arr));
		}
	}
}

int	main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	
	int num_arr[n];
	int arr[m];
	memset(arr, 0, sizeof(arr));
	memset(num_arr, 0, sizeof(num_arr));

	DFS(n, m, num_arr, arr, 0);
}
