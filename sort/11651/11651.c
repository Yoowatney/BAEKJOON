#include <stdio.h>
#include <string.h>

typedef struct
{
	int x;
	int y;
}	coordinates;

coordinates sort[100001];

void	merge(coordinates array[], int low, int middle, int high)
{
	int i, j, k;

	i = low;
	j = middle + 1;
	k = 0;
	while (i <= middle && j <= high)
	{
		if (array[i].y > array[j].y)
		{
			sort[k] = array[j];
			j++;
			k++;
		}
		else if (array[i].y < array[j].y)
		{
			sort[k] = array[i];
			i++;
			k++;
		}
		else
		{
			if (array[i].x < array[j].x)
			{
				sort[k] = array[i];
				i++;				
				k++;
			}
			else
			{
				sort[k] = array[j];
				j++;
				k++;
			}
		}
	}
	while (i <= middle)
	{
		sort[k] = array[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		sort[k] = array[j];
		j++;
		k++;
	}
	k--;
	while (k >= 0)
	{
		array[low + k] = sort[k];
		k--;
	}
}

void	mergesort(coordinates array[], int low, int high)
{
	if (low < high)
	{
		int middle = (low + high) / 2;
		mergesort(array, low, middle);
		mergesort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

int	main()
{
	int size;

	scanf("%d", &size);
	coordinates array[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &array[i].x, &array[i].y);
	}
	mergesort(array, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d %d\n", array[i].x, array[i].y);
	}
}

