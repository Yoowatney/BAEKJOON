#include <stdio.h>

int main()
{
	int num;

	scanf("%d", &num);
	int dp[1000000] = {0,};
	int temp;
	int min = 1000000;

	for (int i = 2; i <= num; i++)
	{
		if (i % 3 == 0)
		{
			temp = (int)i / 3;
			if (min > dp[temp] + 1)
				min = dp[temp] + 1;
		}
		if (i % 2 == 0)
		{
			temp = (int)i / 2;
			if (min > dp[temp] + 1)
				min = dp[temp] + 1;
		}
		if (min > dp[i - 1] + 1)
			min = dp[i - 1] + 1;
		dp[i] = min;
		min = 30000;
	}
	printf("%d\n", dp[num]);
}
