#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int num;
	int sum;
	int i;
	int temp;

	scanf("%d", &num);
	
	i = 0;
	temp = num;
	while (i < num)
	{
		sum = i;
		temp = i;
		while (temp)
		{
			sum += temp % 10;
			temp = temp / 10;
		}
		if (sum == num)
		{
			printf("%d\n",i);
			break ;
		}
		i++;
	}
	if (i == num)
		printf("0\n");
}
