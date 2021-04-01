#include <stdio.h>

int	main()
{
	int size;

	scanf("%d", &size);
	int A[size];
	int B[size];
	int BB[size];
	int temp;
	
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &BB[i]);
	}
	for (int i = 0; i < size; i++)
	{
		B[i] = BB[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (B[i] < B[j])
			{
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
	int res = 0;

	for (int i = 0; i < size; i++)
	{
		res += A[i] * B[i];
	}
	printf("%d\n", res);
}
