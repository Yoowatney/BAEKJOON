#include <stdio.h>
#include <string.h>
# define max 200000

typedef struct priorityQueue 
{
	int heap[max];
	int idx;
} priorityQueue;

typedef struct __score
{
	int x;
	int y;
} _score;

void	push(priorityQueue *pq, int data);
int		pop(priorityQueue *pq);
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
	int n, data;

	scanf("%d", &n);
	priorityQueue pq;
	_score score[n];
	memset(pq.heap, 0, sizeof(pq));
	pq.idx = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &score[i].x, &score[i].y);
	}
	mergesort(n, score, 0, n - 1);
	data = score[0].y;
	push(&pq, data);
	int cnt = 1;

	for (int i = 1; i < n; i++)
	{
		if (pq.heap[0] <= score[i].x)
		{
			data = score[i].y;
			push(&pq, data);
			pop(&pq);
		}
		else
		{
			cnt++;
			data = score[i].y;
			push(&pq, data);
		}
	}
	printf("%d", cnt);
}

void	swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	push(priorityQueue *pq, int data) // heapify
{
	pq->heap[pq->idx] = data;
	int now = pq->idx;
	int parent = (now - 1) / 2;
	while (1)
	{
		if (now > 0 && pq->heap[now] < pq->heap[parent]) // 최대 힙
			swap(&pq->heap[now], &pq->heap[parent]);
		else
			break ;
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->idx++;
}

int	pop(priorityQueue *pq)
{
	int res;
	int now = 0, left = 1, right = 2;
	pq->idx--;
	res = pq->heap[0];
	pq->heap[0] = pq->heap[pq->idx];
	pq->heap[pq->idx] = 0;
	int target = now;

	while (1)
	{
		if (pq->heap[target] > pq->heap[left] && left < pq->idx)
			target = left;
		if (pq->heap[target] > pq->heap[right] && right < pq->idx)
			target = right;
		if (target == now)
			break ;
		else
		{
			swap(&pq->heap[target], &pq->heap[now]);
			left = target * 2 + 1;
			right = left + 1;
			now = target;
		}
	}
	return (res);
}

