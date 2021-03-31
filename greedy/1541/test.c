#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_add(char *ptr)
{
	int ret;
	int i;

	i = 0;
	ret = atoi(ptr);
	while (ptr[i] != 0)
	{
		if (ptr[i] == '+')
		{	
			i++;
			ret += atoi(ptr + i);
		}
		else
		{
			i++;
		}
	}
	return (ret);
}

int	main()
{
	char s1[51];

	scanf("%s", s1);
	char *ptr = strtok(s1, "-");
	int result;
	
	if (s1[0] == '-')
		result = 0;
	else
		result = 2 * ft_add(ptr);
	while (ptr != NULL)
	{
		result -= ft_add(ptr);
		ptr = strtok(NULL, "-");
	}
	printf("%d\n", result);
}
