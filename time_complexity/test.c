#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long j = 0;
	long long i;

	printf("H");
	for (i = 0; i < 1220000000; i++)
	{
		j += rand();
	}
	for (i = 0; i < 1000; i++)
	{
		j += rand();
	}
	printf("ello World!");
}
