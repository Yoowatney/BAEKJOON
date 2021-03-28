#include <stdio.h>
#include <string.h>

void	DFS(int num_arr[], int array[], int N, int M, int index)
{
	if (index == M)
	{
		for (int i = 0; i < M - 1; i++)
		{
			printf("%d ", array[i]);
		}
		printf("%d\n", array[M - 1]);
		return ;
	}

	for (int fill = 0; fill < N; fill++)
	{
		if (num_arr[fill] == 0)
		{
			num_arr[fill] = 1;
			array[index] = fill + 1;
			DFS(num_arr, array, N, M, index + 1);
			num_arr[fill] = 0;
			array[index] = 0;
		}
	}
}


int	main()
{
	int N,M;
	
	scanf("%d %d", &N, &M);
	int num_arr[N];
	int array[M];
	memset(num_arr, 0, sizeof(num_arr));
	memset(array, 0, sizeof(array));
	DFS(num_arr, array, N, M, 0);
}
