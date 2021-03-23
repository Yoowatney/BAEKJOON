#include <stdio.h>


void	arr_ele_cmp(int arr[][2], int row, int array[])
{
	int i;
	int order;
	int move;

	i = 0;
	order = 1;
	while (i < row)
	{
		move = 0;
		order = 1;
		while (move < row)
		{
			if (move == i)
			{
				move++;
				continue ;
			}
			if (arr[i][0] < arr[move][0] && arr[i][1] < arr[move][1])
			{
				order++;
			}
			move++;
		}
		array[i] = order;
		i++;
	}
	printf("%d ",array[0]);
	printf("%d ",array[1]);
	printf("%d ",array[2]);
	printf("%d ",array[3]);
	printf("%d",array[4]);
	printf("\n");
}


int	main()
{
	int num;

	scanf("%d", &num);
	
	int array[num][2];
	int print_array[num];

	for (int row = 0; row < num; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			scanf("%d",&array[row][col]);
		}
	}
	
	int row;

	row = sizeof(array) / sizeof(array[0]);

//	printf("col : %d,  row : %d \n", col, row);

	arr_ele_cmp(array, row, print_array);
//
//	for (int r = 0; r < num; r++)
//	{
//		for (int c = 0; c < 2; c++)
//		{
//			printf("%d ",array[r][c]);
//		}
//		printf("\n");
//	}
//
}
