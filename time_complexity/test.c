#include <stdio.h>

int A = 1;
int	main()
{
	int A, B;
	long long size;
	int temp;

	size = 9999990000000000;
	for (long long i = 0; i < size; i++)
	{
		for (long long j = 0; j < size; j++)
			temp++;
	}
	scanf("%d %d", &A, &B);
	for (long long i = 0; i < size; i++)
	{
		for (long long j = 0; j < size; j++)
			temp++;
	}
	printf("%d", A + B);
}
