#include <stdio.h>
#include <string.h>

typedef struct
{
	int x;
	int y;
} _point;


void	merge(_point point2D[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	_point sort[high - low + 1];
	
	memset(sort, 0, sizeof(sort));
	while (i <= mid && j <= high)
	{
		if (point2D[i].y < point2D[j].y)
		{
			sort[k] = point2D[i];
			k++;
			i++;
		}
		else if (point2D[i].y > point2D[j].y)
		{
			sort[k] = point2D[j];
			k++;
			j++;
		}
		else
		{
			if (point2D[i].x < point2D[j].x)
			{
				sort[k] = point2D[i];
				k++;
				i++;
			}
			else
			{
				sort[k] = point2D[j];
				k++;
				j++;
			}
		}
	}
	while (i <= mid)
	{
		sort[k]= point2D[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		sort[k] = point2D[j];
		k++;
		j++;
	}
	k--;
	while (k >= 0)
	{
		point2D[low + k] = sort[k];
		k--;
	}
}

void	mergesort_y(_point point2D[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		
		mergesort_y(point2D, low, mid);
		mergesort_y(point2D, mid + 1, high);
		merge(point2D, low, mid, high);
	}
	else
		return;
}
	

int	main()
{
	int size;
	int cnt;
	int temp;

	scanf("%d", &size);
	_point point2D[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &point2D[i].x, &point2D[i].y);
	}
	mergesort_y(point2D, 0, size - 1);
	cnt = 1;
	temp = point2D[0].y;
	for (int i = 1; i < size; i++)
	{
		if (temp <= point2D[i].x)
		{
			temp = point2D[i].y;
			cnt++;
		}
	}
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d %d\n", point2D[i].x, point2D[i].y);
//	}
	printf("%d\n", cnt);


}
