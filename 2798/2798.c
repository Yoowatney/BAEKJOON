#include <stdio.h>

int g_array[6000] = { 0, };

void	print_max(int find)
{
	int i;
	int diff;
	int exit;

	diff = 1;
	exit = 0;
	while (1)
	{
		i = 0;
		while (g_array[i] > 0)
		{
			if (find - g_array[i] == diff)
			{
				exit = 1;
				printf("%d\n",g_array[i]);
				break;
			}
			i++;
		}
		diff++;
		if (exit == 1)
			break;
	}
}


int	main()
{
	int size, find;
	int i, exit;
	int first, second, third;

	first = 0;
	i = 0;
	exit = 0;
//	printf("정수 2개 입력\n");
	scanf("%d %d", &size, &find);

	int arr[size];

//	printf("%d개만큼 정수 입력해야함\n", size);
	while (i < size)
	{
		scanf("%d",&arr[i]);
		i++;
	}
	
	i = 0;
	while (first < size)
	{
		second = first + 1;
		while (second < size)
		{
			third = second + 1;
			while (third < size)
			{
				if (arr[first] + arr[second] + arr[third] == find)
				{
					exit = 1;
					printf("%d\n", find);
					break ;
				}
				else if (arr[first] + arr[second] + arr[third] > find)
					 ;
				else 
				{
					g_array[i] = arr[first] + arr[second] + arr[third];
					i++;
				}
				third++;
			}
			second++;
			if (exit == 1)
				break ;
		}
		first++;
		if (exit == 1)
			break ;
	}
	if (!(exit))
		print_max(find);
}
