#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int	ft_add(char *ptr)
//{
//	int ret;
//	int i;
//
//	i = 0;
//	ret = atoi(ptr);
//	while (ptr[i] != 0)
//	{
//		if (ptr[i] == '+')
//		{	
//			i++;
//			ret += atoi(ptr + i);
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return (ret);
//}

int	ft_add(char *ptr)
{
	int ret;
	char *temp;

	temp = strtok(ptr, "+"); // 뒷 string 꼬이기 시작
	ret = 0;
	while (temp != NULL)
	{
		ret += atoi(temp);
		temp = strtok(NULL, "+");
	}
	return (ret);
}
// strtok : 한번만 사용해야 복잡함을 피할 수 있음
// 여러번 사용시 복잡해짐
int	main()
{
	char s1[30] = "30+40-50+40-50-40+40";
	char *ptr = strtok(s1, "-");
	int result = 0;
	printf("%s\n", ptr);
	ft_add(ptr);
	printf("%s\n", ptr);
//		printf("%s\n", ptr);
//	printf("%s\n", ptr);
//	printf("%d\n", ft_add(ptr));
//	//	printf("%s\n", ptr);
//	ptr = strtok(NULL, "+");
//	printf("%s\n", ptr);
//	printf("1 : %s\n", ptr);
//	printf("%d\n", ft_add(ptr));
//	ptr = strtok(NULL, "-");
//	printf("2 : %s\n", ptr);
//	printf("%d\n", atoi(ptr));
//	ptr = strtok(NULL, "-");
//	printf("3 : %s\n", ptr);
//	while (ptr != NULL)
//	{
//		printf("ptr : %s\n", ptr);
//		result -= ft_add(ptr);
//		//		printf("ft_add(ptr) : %d\n", ft_add(ptr));
//		ptr = strtok(NULL, "-");
//		//		if (ptr != NULL)
//		//			result -= ft_add(ptr);
//	}

//	printf("%d\n", result);
//	printf("ans : %d\n", ft_add(ptr));
//	while (ptr != NULL)
//	{
//		printf("%s\n", ptr);
//		ptr = strtok(NULL, " ");
//	}
//	printf("%d\n", atoi(ptr));
}
