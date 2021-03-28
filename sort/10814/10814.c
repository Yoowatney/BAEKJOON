#include <stdio.h>
#include <string.h>

typedef struct
{
	int age;
	char name[101];
} _list;

_list sort[100000];

void	merge(_list list[], int low, int middle, int high)
{
	int i = low;
	int j = middle + 1;
	int k = 0;

	while (i <= middle && j <= high)
	{
		if (list[i].age < list[j].age)
		{
			sort[k] = list[i];
			k++;
			i++;
		}
		else if (list[i].age > list[j].age)
		{
			sort[k] = list[j];
			k++;
			j++;
		}
		else
		{
			sort[k] = list[i];
			k++;
			i++;
		}
	}

	while (i <= middle)
	{
		sort[k] = list[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		sort[k] = list[j];
		k++;
		j++;
	}
	k--;

	while (k >= 0)
	{
		list[low + k] = sort[k];
		k--;
	}
}

void	mergesort(_list list[], int low, int high)
{
	if (low < high)
	{
		int middle = (low + high) / 2;
		mergesort(list, low, middle);
		mergesort(list, middle + 1, high);
		merge(list, low, middle, high);
	}
}

int	main()
{
	int size;

	scanf("%d", &size);
	_list list[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d %s", &list[i].age, list[i].name);
	}
//	size = 3;
//	list[0].age = 21;
//	list[1].age = 21;
//	list[2].age = 20;
//	strcpy(list[0].name, "Junkyu");
//	strcpy(list[1].name, "Dohyun");
//	strcpy(list[2].name, "Sunyoung");
	mergesort(list, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d %s\n", list[i].age, list[i].name);
	}
}
