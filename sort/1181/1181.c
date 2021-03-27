#include <stdio.h>
#include <string.h>

int g_size = 0;

typedef struct
{
	char str[52];
	int len;
} _strset;

int		str_len(char str[])
{
	int i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

_strset sort[20000];

void	merge(_strset strset[], int low, int middle, int high)
{
	int i, j, k;

	i = low;
	j = middle + 1;
	k = 0;
	while (i <= middle && j <= high)
	{
		if (strset[i].len > strset[j].len)
		{
			sort[k] = strset[j];
			j++;
			k++;
		}
		else if (strset[i].len < strset[j].len)
		{
			sort[k] = strset[i];
			i++;
			k++;
		}
		else
		{
			if (strcmp(strset[i].str, strset[j].str) < 0)
			{
				sort[k] = strset[i];
				k++;
				i++;
			}
			else
			{
				sort[k] = strset[j];
				k++;
				j++;
			}
//			int x;
//			int sign = 1;
//			for (x = 0; x < strset[i].len; x++)
//			{
//				if (strset[i].str[x] < strset[j].str[x])
//				{
//					sort[k] = strset[i];
//					i++;				
//					k++;
//					sign = 0;
//					break ;
//				}
//				else if (strset[i].str[x] > strset[j].str[x])
//				{
//					sort[k] = strset[j];
//					j++;
//					k++;
//					sign = 0;
//					break ;
//				}
//			}
//			if (sign)
//			{
//				sort[k] = strset[i];
////				strcpy(strset[i].str, "1");
////				strcpy(strset[j].str, "1");
//				k++;
//				i++;
//				j++;
//				g_size++;
//			}
		}
	}
	while (i <= middle)
	{
		sort[k] = strset[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		sort[k] = strset[j];
		j++;
		k++;
	}
	k--;
	while (k >= 0)
	{
		strset[low + k] = sort[k];
		k--;
	}
}

void	mergesort(_strset strset[], int low, int high)
{
	if (low < high)
	{
		int middle = (low + high) / 2;
		mergesort(strset, low, middle);
		mergesort(strset, middle + 1, high);
		merge(strset, low, middle, high);
	}
	else
		return ;
}

int	main()
{
	int size;
	char temp[51];

//	size = 9;
//	_strset strset[size];
//	strcpy(strset[0].str,"but");
//	strset[0].len = 3;
//	strcpy(strset[1].str, "i");
//	strset[1].len = 1;
//	strcpy(strset[2].str, "wont");
//	strset[2].len = 4;
//	strcpy(strset[3].str, "hesitate");
//	strset[3].len = 8;
//	strcpy(strset[4].str, "no");
//	strset[4].len = 2;
//	strcpy(strset[5].str, "more");
//	strset[5].len = 4;
//	strcpy(strset[6].str, "no");
//	strset[6].len = 2;
//	strcpy(strset[7].str, "more");
//	strset[7].len = 4;
//	strcpy(strset[8].str, "it");
//	strset[8].len = 2;
//
	scanf("%d", &size);

	_strset strset[size];
	for (int i = 0 ; i < size; i++)
	{
//		memset(strset[i].str, 0, 51);
		scanf("%s", temp);
		strcpy(strset[i].str, temp);
		strset[i].len = str_len(strset[i].str);
	}
	mergesort(strset, 0, size - 1);
//	while (g_size > 0)
//	{
//		strcpy(strset[size - g_size + 1].str, "1");
//		g_size--;
//	}
	for (int i = 1 ; i < size; i++)
	{
		if (strcmp(strset[i - 1].str, strset[i].str) != 0)
			printf("%s\n", sort[i].str);
	}
}
