#include <stdio.h>

int arr[1000001] = {0, };

int dp(int n)
{
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (arr[n] != 0)
		return (arr[n]);
	return (arr[n] = (dp(n - 1) + dp(n - 2)) % 15746);
}

int	main()
{
	int num;

	scanf("%d", &num);
	printf("%d\n", dp(num));
}
