#include <stdio.h>
#include <string.h>

void	print_board(int M, int board[])
{
		for (int i = 0; i < M - 1; i++)
					printf("%d ", board[i]);
			printf("%d\n", board[M - 1]);
}

void	find(int N, int M, int num_arr[], int board[], int location)
{
	if (location == M)
	{
		print_board(M, board);
		return ;
	}

	for (int fill = 1; fill <= N; fill++)
		if (num_arr[fill - 1] == 0)
		{
			num_arr[fill - 1] = 1;
			board[location] = fill;
			find(N, M, num_arr, board, location + 1);
			board[location] = 0;
			num_arr[fill - 1] = 0;
		}
}

int		main()
{
	int N, M;

	scanf("%d %d", &N, &M);
	int num_arr[N];
	int board[M];

	memset(num_arr, 0, sizeof(num_arr));
	memset(board, 0, sizeof(board));
	find(N, M, num_arr, board, 0);
}
