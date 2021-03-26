#include <stdio.h>

void	sort_array(int array[], int size)
{
	int temp;

	for (int fix = 0; fix < size; fix++)
	{
		for (int move = fix + 1; move < size; move++)
		{
			if (array[move] > array[fix])
			{
				temp = array[fix];
				array[fix] = array[move];
				array[move] = temp;
			}
		}
	}
}

void	fill_array(int array[], int size, long long num)
{
	int i;

	i = 0;
	while (num)
	{
		array[i] = num % 10;
		i++;
		num = num / 10;
	}
}

int len_int(long long num)
{
	int i;

	i = 0;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	main()
{
	long long	num;
	int			size;

	scanf("%lld", &num);
	size = len_int(num);
	int			array[size];
	
	fill_array(array, size, num);
	sort_array(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
}
