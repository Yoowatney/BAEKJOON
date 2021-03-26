#include <stdio.h>

int	main()
{
	int size;
	int num;
	int array[10000] = {0, };

	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			printf("Error");
			return (0);
		}
		array[num - 1]++;
	}
	for (int i = 0; i < 10000; i++)
	{
		while (array[i])
		{
			printf("%d\n", i + 1);
			array[i]--;
		}
	}
}
