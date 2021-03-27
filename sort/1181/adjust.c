#include <stdio.h>
#include <string.h>

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
			if (strcmp(strset[i].str, strset[j].str) <= 0)
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
	scanf("%d", &size);

	_strset strset[size];
	for (int i = 0 ; i < size; i++)
	{
		scanf("%s", temp);
		strcpy(strset[i].str, temp);
		strset[i].len = str_len(strset[i].str);
	}
	mergesort(strset, 0, size - 1);
	printf("%s\n", strset[0].str);
	for (int i = 1 ; i < size; i++)
	{
		if (strcmp(strset[i - 1].str, strset[i].str) != 0)
			printf("%s\n", strset[i].str);
	}
}
