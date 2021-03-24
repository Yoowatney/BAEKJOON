#include <stdio.h>

void	sort(int array[], int size)
{
	int temp;

	for (int fix = 0; fix < size; fix++)
	{
		for (int move = fix + 1; move < size; move++)
		{
			if (array[fix] > array[move])
			{
				temp = array[fix];
				array[fix] = array[move];
				array[move] = temp;
			}
		}
	}
	return ;
}

int	main()
{
	int size;
	int i;

	i = 0;
	scanf("%d", &size);
	int array[size];

	while (i < size)
	{
		scanf("%d", &array[i]);
		i++;
	}
	sort(array, size);
	i = 0;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}
