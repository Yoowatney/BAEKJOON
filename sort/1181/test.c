#include <stdio.h>
#include <string.h>

typedef struct
{
	char str[51];
	int len;
} _strset;
//
//int	main()
//{
//	int size;
//
//	scanf("%d", &size);
//	char str[size][51];
//
//	for (int i = 0 ; i < size; i++)
//	{
//		scanf("%s", str[i]);
//	}
//	sort_str(str, size);
//	printf("%s\n", str[0]);
//}

int	main()
{
	int size;

	size = 6;
	_strset strset[size];
	strcpy(strset[0].str,"but");
	strset[0].len = 3;
	strcpy(strset[1].str, "i");
	strset[1].len = 1;
	strcpy(strset[2].str, "wont");
	strset[2].len = 4;
	strcpy(strset[3].str, "hesitate");
	strset[3].len = 8;
	strcpy(strset[4].str, "no");
	strset[4].len = 2;
	strcpy(strset[5].str, "more");
	strset[5].len = 4;
	int i = 2;
	for (int x = 0; x < strset[i].len; x++)
	{
		if (strset[i].str[x] < strset[5].str[x])
		{
			printf("5가 더큼");
			break ;
		}
		else
		{
			printf("2가더큼");
			break ;
		}
	}
//	printf("%s\n", strset[i].str);
//	printf("%d\n", strset[i].len);
}

