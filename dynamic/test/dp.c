#include <stdio.h>
#include <string.h>

int	main()
{
	int arr[20];
	int anw[20];
	int n;
	int sum;
	int max_sum;
	int clue;
	int temp;
	int index;

	index = 0;
	temp = 0;
	memset(anw, 0, sizeof(anw));
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	for (int i = 0; i < 20 && n; i++)
	{
		arr[i] = n;
		scanf("%d", &n);
	}
	max_sum = arr[0];
	for (int i = 0; i < 20 && arr[i]; i++)
	{
		sum = 0;
		for (int j = i; j < 20 && arr[i]; j++)
		{
			sum += arr[j];
			if (sum > max_sum)
			{
				max_sum = sum;
				clue = j;
			}
		}
	}
	while (temp != max_sum)
	{
		anw[index] = arr[clue];
		temp += arr[clue];
		index++;
		clue--;
	}
	index--;
	while (index > 0)
	{
		printf("%d ", anw[index]);
		index--;
	}
	printf("%d", anw[index]);
}
