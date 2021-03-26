#include <stdio.h>

void	insert(int array[], int size)
{
	int move, back;
	int temp;

	for (move = 1; move < size; move++)
	{
		temp = array[move];
		for (back = move - 1; back >= 0; back--)
		{
			if (array[back] > temp)
				array[back + 1] = array[back];
			else
				break ; 
		}
		array[back + 1] = temp;
	}
}


int	main()
{
	int size;

	scanf("%d", &size);
	int array[size];
	int i;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}

	insert(array, size);
	for (i = 0; i < size; i++)
	{
		printf("%d\n", array[i]);
	}
	return (0);
}
