#include <stdio.h>
#include <string.h>

typedef struct __score 
{
	int x;
	int y;
} _score;

void	merge(_score score[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	_score sort[high - low + 1];
	
	memset(sort, 0, sizeof(sort));
	while (i <= mid && j <= high)
	{
		if (score[i].x < score[j].x)
		{
			sort[k] = score[i];
			k++;
			i++;
		}
		else
		{
			sort[k] = score[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		sort[k]= score[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		sort[k] = score[j];
		k++;
		j++;
	}
	k--;
	while (k >= 0)
	{
		score[low + k] = sort[k];
		k--;
	}
}

void	mergesort(int num, _score score[num], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		
		mergesort(num, score, low, mid);
		mergesort(num, score, mid + 1, high);
		merge(score, low, mid, high);
	}
	else
		return;
}


int main()
{
	int T;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int num;
		scanf("%d", &num);
		_score score[num];
	
		for (int i = 0; i < num; i++)
			scanf("%d %d", &score[i].x, &score[i].y);
		mergesort(num, score, 0, num - 1);
		int temp = score[0].y;
		int cnt = 1;

		for (int i = 0; i < num; i++)
		{
			if (temp > score[i].y)
			{
				temp = score[i].y;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}

