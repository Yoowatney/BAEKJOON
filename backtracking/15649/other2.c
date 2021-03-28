#include <stdio.h>

int num_arr[20] = { 0, };
int array[20];

void track(int n, int m, int x)
{
	if (m == x)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
	{
		if (num_arr[i])
			continue;
		num_arr[i] = 1;
		array[x] = i;
		track(n, m, x + 1);
		num_arr[i] = 0;
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	track(n, m, 0);
	return 0;
}
