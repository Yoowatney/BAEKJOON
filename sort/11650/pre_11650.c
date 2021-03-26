#include <stdio.h>

void	sort_array_y(int array[][2], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i][0] == array[j][0])
			{
				if (array[i][1] > array[j][1])
				{
					temp = array[i][0];
					array[i][0] = array[j][0];
					array[j][0] = temp;
					temp = array[i][1];
					array[i][1] = array[j][1];
					array[j][1] = temp;
				}	
			}
		}
	}

}

void	sort_array_x(int array[][2], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i][0] > array[j][0])
			{
				temp = array[i][0];
				array[i][0] = array[j][0];
				array[j][0] = temp;
				temp = array[i][1];
				array[i][1] = array[j][1];
				array[j][1] = temp;
			}	
		}
	}
	printf("======= 중간 과정 ========\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d %d\n", array[i][0], array[i][1]);
	}
	
}
int	main()
{
	int size;

	scanf("%d", &size);
	int array[size][2];

	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &array[i][0], &array[i][1]);
	}
	sort_array_x(array, size);
	sort_array_y(array, size);
	printf("\n ======= 결과값 ======= \n");
	for (int i = 0; i < size; i++)
	{
		printf("%d %d\n", array[i][0], array[i][1]);
	}
}
