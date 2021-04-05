#include <stdio.h>

int d[1001][3] = {0, };
int array[1001][3] = {0, };

int	min(int num1, int num2)
{
	return (num1 > num2 ? num2 : num1);
}

int	dp(int n, int color)
{
	if (n == 1)
		if (color == 0)
			return (array[1][0]);
		else if (color == 1)
			return (array[1][1]);
		else
			return (array[1][2]);
	if (d[n][color] != 0)
		return (d[n][color]);
	if (color == 0)
		return (d[n][0] = min(dp(n - 1, 1), dp(n - 1, 2)) + array[n][0]);
	if (color == 1)
		return (d[n][1] = min(dp(n - 1, 0), dp(n - 1, 2)) + array[n][1]);
	if (color == 2)
		return (d[n][2] = min(dp(n - 1, 0), dp(n - 1, 1)) + array[n][2]);
}


int	main()
{
	int size;

	scanf("%d", &size);
	for (int i = 1; i < size + 1; i++)
		scanf("%d %d %d", &array[i][0], &array[i][1], &array[i][2]);
	printf("%d\n", min(min(dp(size, 0), dp(size, 1)), dp(size, 2)));
}
