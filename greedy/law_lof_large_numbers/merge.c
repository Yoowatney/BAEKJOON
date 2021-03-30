#include <stdio.h>
#include <string.h> // 배열 초기화 뭐야;

void	merge(int arr[], int low, int mid, int high)
{
	int sort[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;

	memset(sort, 0, sizeof(sort));
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			sort[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			sort[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		sort[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		sort[k] = arr[j];
		k++;
		j++;
	}
	k--;
	while (k >= 0)
	{
		arr[k + low] = sort[k];
		k--;
	}
}

void	mergesort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid;
		
		mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	else
		return ;
}

int	main()
{
	int size;

	scanf("%d", &size);
	int arr[size];
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort(arr, 0, size - 1);
	for (int i = 1; i < size; i++)
	{
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}
	printf("%d\n", result);
}
