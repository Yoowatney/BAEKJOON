#include <stdio.h>
#include <string.h>

int main()
{
	int size;
	scanf("%d", &size);
	int arr[size + 3];
	int dp[size + 3];
	memset(dp, 0, sizeof(dp));
	arr[0] = 0;
	for (int i = 1; i < size + 1; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max;
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	max = arr[1] + arr[3];
	if (max < arr[2] + arr[3])
		max = arr[2] + arr[3];
	dp[3] = dp[2] > max ? dp[2] : max; 
	max = arr[1] + arr[3] + arr[4];
	if (max < arr[1] + arr[2] + arr[4])
		max = arr[1] + arr[2] + arr[4];
	if (max < arr[2] + arr[3])
		max = arr[2] + arr[3];
	dp[4] = max;
	for (int i = 4; i < size + 1; i++)
	{
		max = dp[i - 3] + arr[i - 1] + arr[i];
		if (dp[i - 2] + arr[i] > max)
			max = dp[i - 2] + arr[i];
		dp[i] = max;
		dp[i] = max > dp[i - 1] ? max : dp[i - 1]; 
	}
	printf("%d\n", dp[size]);
//	for (int i = 1; i < size + 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 1; i < size + 1; i++)
//	{
//		printf("%d ", dp[i]);
//	}
}
