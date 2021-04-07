#include <stdio.h>

int main()
{
	int j = 0;
	int i;

	printf("H");
	for (i = 0; i < 1000000000; i++)
	{
		j++;
	}
	if (i == 1000000000)
		printf("ello World!");
}
