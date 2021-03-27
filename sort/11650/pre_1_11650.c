#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}	coordinate;

coordinate[100001]; 
void	merge(coordinate *array, int low, int middle, int high)
{
	int temp[high - low + 1];
	int	i_left = low;
	int i_right = middle + 1;
	int move = 0;
	
	while (i_left <= middle && i_right <= high)
	{
		if (array[i_left] > array[i_right])
		{
			temp[move] = array[i_right];
			move++;
			i_right;
		}
		else
		{
			temp[move] = array[i_left];
			move++;
			i_left;
		}
	}
	
	while (i_left <= middle)
	{
		temp[move] = array[i_left];
		move++;
		i_left;
	}

	while (i_right <= middle)
	{
		temp[move] = array[i_right];
		move++;
		i_right;
	}
	move--;
	while (move >= 0)
	{
		array[low + move] = temp[move];
		move--;
	}
}

void	mergesort(coordinate *array[], int low, int high)
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
	int size;

	scanf("%d", &size);

	coordinate *arr = (coordinate *)malloc(sizeof(coordinate) * size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	mergesort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d %d\n",arr[i].x, arr[i].y);
	}
	free[arr];
}
