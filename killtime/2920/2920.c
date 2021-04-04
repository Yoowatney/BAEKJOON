#include <stdio.h>

int	main()
{
	int arr[8];
	int temp = 0;
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		if (temp < arr[i])
		{
			temp = arr[i];
			cnt++;
		}
	}
	if (cnt == 8)
	{
		printf("ascending");
		return (0);
	}
	cnt = 0;
	temp = 9;
	for (int i = 0; i < 8; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
			cnt++;
		}
	}
	if (cnt == 8)
	{
		printf("descending");
		return (0);
	}
	printf("mixed");
}
