#include <stdio.h>

int	main()
{
	long long arr[101] = {0, };
	int T;
	int num;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i < 101; i++)
	{
		arr[i] = arr[i - 5] + arr[i - 1];
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &num);
		printf("%lld\n", arr[num]);
	}
}
