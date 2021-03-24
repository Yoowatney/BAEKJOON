#include <stdio.h>

int	main()
{
	char array[2][9] = {"WBWBWBWB","BWBWBWBW"};

	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			printf("%c",array[r][c]);
		}
		printf("\n");
	}
}
