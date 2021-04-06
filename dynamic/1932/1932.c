#include <stdio.h>

int arr[501][501] = {0, };
int d[501][501] = {0, };

int	max(int a, int b)
{
	return (a > b ? a: b);
}
int dp(int row, int col)
{
	if (row == 1 && col == 1)
		return (d[1][1] = arr[1][1]);
	if (d[row][col] != 0)
		return (d[row][col]);
	if (col == 1)
		return (d[row][col] = dp(row - 1, col) + arr[row][col]);
	else if (col == row)
		return (d[row][col] = dp(row - 1, col - 1) + arr[row][col]);
	return (d[row][col] = arr[row][col] + max(dp(row - 1, col - 1), dp(row - 1, col)));
}

int	main()
{
	int n;
	int max_number;
	
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < i + 1; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i < n + 1; i++)
		dp(n, i);
	max_number = dp(n, 1);
	for (int i = 1; i < n + 1; i++)
		if (max_number < dp(n, i))
			max_number = dp(n, i);
	printf("%d\n", max_number);
}
