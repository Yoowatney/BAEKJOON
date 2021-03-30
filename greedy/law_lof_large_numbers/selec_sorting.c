#include <stdio.h>

int	main()
{
	int size;

	scanf("%d", &size);
	int arr[size];
	int result = 0;
	int temp;

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
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
