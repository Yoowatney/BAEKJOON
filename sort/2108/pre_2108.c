#include <stdio.h>
#include <math.h>

void	range(int array[], int size)
{
	printf("range : %d\n", array[size - 1] - array[0]);
}


void	median(int array[], int size)
{
	printf("median : %d\n",array[(size - 1) / 2]);
}

void    merge(int array[], int low, int middle, int high)
{
	int left_move = low;
	int right_move = middle + 1;
	int move = 0;
	int temp[high - low + 1];

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

void    mergesort(int array[], int low, int high)
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

void	count(int array[], int size)
{
	int count[8001] = {0, };
	int sign = 0;
	int max = 1;
	
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= 0)
		{
			count[4000 + array[i]]++;
		}
		else
		{
			count[(array[i] + 4000)]++;
		}
	}
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
		}
	}

	for (int i = 0; i < 8001; i++)
	{
		if (sign == 1 && max == count[i])
		{
			if (i >= 4000)
			{
				printf("fre : %d\n", i - 4000);
				return ;
			}
			else
			{
				printf("fre : %d\n", -4000 + i);
				return ;
			}
		}
		if (max == count[i])
		{
			sign = 1;
		}
	}
	printf("======= Array has no duplicated elements =======\n");

	for (int i = 0; i < 8001; i++)
	{
		if (max == count[i])
		{
			if (i >= 4000)
			{
				printf("fre : %d\n", i - 4000);
				return ;
			}
			else
			{
				printf("fre : %d\n", -4000 + i);
				return ;
			}
		}
	}
}

void	ari_mean(int array[], int size)
{
	double sum;
	
	sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	sum = round(sum / size);
	printf("arith : %d\n", (int)sum);
}

int	main()
{
	int size;

	scanf("%d", &size);
	int array[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("\n");
	mergesort(array, 0, size - 1);
	ari_mean(array, size);
	median(array, size);
	count(array, size);
	range(array, size);
}
