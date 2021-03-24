#include <stdio.h>

int	main()
{
	int num;
	int temp;
	int condition = 0;
	int i = 666;

	scanf("%d", &num);
	while (i < 6665000)
	{
		temp = i;
		while (temp)
		{
			if (temp % 10 == 6)
			{
				temp = temp / 10;
				if (temp % 10 == 6)
				{
					temp = temp / 10;
					if (temp % 10 == 6)
					{
						temp = temp / 10;
						condition++;
						if (num == condition)
						{
							printf("%d\n", i);
							return (0);
						}
						else
							break ;
					}
					else
						temp = temp / 10;
				}
				else
					temp = temp / 10;
			}
			else
				temp = temp / 10;
		}
		i++;
	}	
	return (0);
}
