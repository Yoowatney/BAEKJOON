#include <stdio.h>

typedef struct __arr 
{
	int day;
	int money;
} _arr;

int main()
{
	int	n;
	scanf("%d", &n);
	_arr	arr[1600001];// = {0, };
	long	dp[1600001] = {0,};
	printf("%d %d", arr[0].day, arr[2].money);
	return (0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].day, &arr[i].money);
	}
	for (int i = 0; i <= n; i++)
	{
		if (i != 0 && dp[i] < dp[i - 1])
			dp[i] = dp[i - 1];
		if (dp[arr[i].day + i] < arr[i].money + dp[i])
			dp[arr[i].day + i] = arr[i].money + dp[i];
	}
	for (int i = 0; i <= n; i++)
	{
		printf("%ld ", dp[i]);
	}
	printf("\n ans : %ld", dp[n]);
	return (0);
}
