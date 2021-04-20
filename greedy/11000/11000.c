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
	int n;
	
	scanf("%d", &n);
	_score score[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &score[i].x, &score[i].y);
	}
	mergesort(n, score, 0, n - 1);

	int temp = score[0].y;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (temp <= score[i].x)
		{
			temp = score[i].y;
			cnt++;
		}
	}
	int ans = n - cnt + 1;
	printf("ans %d\n", ans);

	printf("--- answer ---\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", score[i].x, score[i].y);
	}
}
