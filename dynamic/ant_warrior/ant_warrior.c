#include <stdio.h>

int main()
{
	int size;
	scanf("%d", &size);

	int arr[size];
	int dp[100] = {0,};
	int max;
	int super_max = 0;

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
		if (i == 0 || i == 1)
		{
			dp[i] = arr[i];
			continue ;
		}
		max = 0;
		for (int j = 0; j < i - 1; j++)
		{
			if (max < dp[j] + arr[i])
			{
				max = dp[j] + arr[i];
			}
		}
		dp[i] = max;
		if (max > super_max)
		{
			super_max = max;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", dp[i]);
	}

	printf("\n super_max : %d \n", super_max);
}
