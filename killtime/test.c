#include <stdio.h>
#include <math.h>

int main()
{
	int arr[3];
	int temp;
	int i;

	while (1)
	{
		for (i = 0; i < 3; i++)
			scanf("%d", &arr[i]);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			return (0);
		for (i = 0; i < 2; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		if (pow(arr[2], 2) == pow(arr[1], 2) + pow(arr[0], 2))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
