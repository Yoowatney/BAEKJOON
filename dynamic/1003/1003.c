#include <stdio.h>

typedef struct
{
	int zero;
	int one;
} _numset;

_numset numset[40] = {0, };

int	main()
{
	int size;
	int num;

	scanf("%d", &size);
	numset[0].zero = 1;
	numset[0].one = 0;
	numset[1].zero = 0;
	numset[1].one = 1;

	for (int i = 2; i < 41; i++)
	{
		numset[i].zero = numset[i - 1].zero + numset[i - 2].zero;
		numset[i].one = numset[i - 1].one + numset[i - 2].one;
	}
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		printf("%d %d\n", numset[num].zero, numset[num].one);
	}
}
