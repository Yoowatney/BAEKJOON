#include <stdio.h>

void	merge(int array[], int low, int middle, int high)
{
	int left_move = low;
	int right_move = middle + 1;
	int move = 0;
	int temp[500000] = {0, };

	while (left_move <= middle && right_move <= high)
	{
		if (array[left_move] > array[right_move])
		{
			temp[move] = array[right_move];
			right_move++;
			move++;
		}
		else
		{
			temp[move] = array[left_move];
			left_move++;
			move++;
		}
	}
	while (left_move <= middle)
	{
		temp[move] = array[left_move];
		left_move++;
		move++;
	}
	while (right_move <= high)
	{
		temp[move] = array[right_move];
		right_move++;
		move++;
	}
	move--;
	while (move >= 0)
	{
		array[low + move] = temp[move];
		move--;
	}
}

void	mergesort(int array[], int low, int high)
{
	if (low < high)
	{
		int middle = (low + high) / 2;
		mergesort(array, low, middle);
		mergesort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
	else
		return ;
}

int	main()
{
	int array[] = {5, 2, 3, 4, 1};

	mergesort(array, 0, 5 - 1);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ",array[i]);
	}
}
