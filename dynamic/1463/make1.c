#include <stdio.h>

int	min_get(int min1, int min2)
{
	return (min1 > min2 ? min2 : min1);
}

int main()
{
	int num;

	scanf("%d", &num);
	int dp[30000] = {0,};
	int temp;
	int min = 30000;
	int min1, min2, min3, min4;

	for (int i = 2; i <= num; i++)
	{
//		if (i % 5 == 0)
//		{
//			temp = (int)i / 5;
//			if (min > dp[temp] + 1)
//				min = dp[temp] + 1;
//		}
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
//		min = min_get(min_get(min_get(min1, min2), min3), min4);
		dp[i] = min;
		min = 30000;
	}
	printf("answer : %d\n", dp[num]);
//	for (int i = 2; i <= num; i++)
//	{
//		printf("%d : %d\n",i, dp[i]);
//	}
}

