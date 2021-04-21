#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct priorityQueue
{
	int heap[1000];
	int count;
} priorityQueue;

void push(priorityQueue *pq, int data )
{
	if (pq->count >= 1000)
		return ;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now] > pq->heap[parent])
	{
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1)/ 2;
	}
	pq->count++;
}

int pop(priorityQueue *pq)
{
	if (pq->count <= 0)
		return (-1);
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now;
	while (leftchild < pq->count)
	{
		if (pq->heap[target] < pq->heap[leftchild])
			target = leftchild;
		if (pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count)
			target = rightchild;
		if (target == now)
			break ;
		else
		{
			swap(&pq)
		}
	}
}
int main()
{
	int n, data;
	scanf("%d", &n);
	priorityQueue pq;
}

