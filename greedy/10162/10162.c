#include <stdio.h>

int	main()
{
	int A;
	int B;
	int C;
	int T;
	int arr[3];

	A = 300;
	B = 60;
	C = 10;
	scanf("%d", &T);
	arr[0] = T / 300;
	T = T % 300;
	arr[1] = T / 60;
	T = T % 60;
	arr[2] = T / 10;
	T = T % 10;
	if (T)
		printf("-1");
	else
	{
		for (int i = 0; i < 2; i++)
			printf("%d ", arr[i]);
		printf("%d", arr[2]);
	}
}
