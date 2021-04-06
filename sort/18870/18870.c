#include <stdio.h>

void	merge(int array[], int low, int middle, int high)
{
	int temp[100000];
	int left = low;
	int right = middle + 1;
	int move = 0;

	while (left <= middle && right <= high)
	{
		if (array[left] < array[right])
		{
			temp[move] = array[left];
			move++;
			left++;
		}
		else
		{
			temp[move] = array[right];
			move++;
			right++;
		}

	}
	while (left <= middle)
	{
		temp[move] = array[left];
		move++;
		left++;
	}
	while (right <= high)
	{
		temp[move] = array[right];
		move++;
		right++;
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
		return;
}

int main()
{
	int size;
	int i;
	int max = 0;

	scanf("%d", &size);
	int arr[size];

	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	mergesort(arr, 0 , size - 1);

	for (i = 0; i < size; i++)
	{
		if (max < arr[i] * (size - i))
			max = arr[i] * (size - i);
	}
	printf("%d\n",max);
	return 0;
}
