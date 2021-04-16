#include <stdio.h>
#include <stdlib.h>

int arr[100001];
int queue[100001]; // 100000개 일땐 오답, 100001일 땐 정답..?
int dx[2] = {-1, 1};

//int compare(const void *a, const void *b)
//{
//	int num1 = *(int *)a;    
//	int num2 = *(int *)b;       
//	if (num1 < num2)
//		return -1;     
//
//	if (num1 > num2)   
//		return 1;       
//
//	return 0;
//}

void	BFS(int n, int m);

int main()
{
	int n, m;

	scanf("%d %d", &n ,&m);
	if (m < n)
	{
		printf("%d", n - m);
		return (0);
	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("arr[%d] : %d\n",i, arr[i]);
//	}
//	printf("-after-\n");
	BFS(n, m);
//	qsort(queue, 100001, sizeof(int), compare);
//	for (int i = 0; i < 100001; i++)
//	{
//		if (queue[i] != i)
//			printf("queue[%d] == %d",i, queue[i]);
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("arr[%d] : %d\n",i, arr[i]);
//	}
	printf("%d", arr[m] - 1);
}

void	BFS(int n, int m)
{
	int front = 0;
	int rear = 0;
	int pop;
	int nx;

	queue[rear] = n;
	arr[n] = 1;
	rear++;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				nx = pop * 2;
				if (nx > 100000 || nx < 0)
					continue ;
//				if (arr[nx] > arr[pop] + 1 || arr[nx] == 0)
//				if (arr[nx] > arr[pop] + 1)
//				{
//					arr[nx] = arr[pop] + 1;
//					queue[rear] = nx;
//					rear++;
//					printf("hi");
//				}
				if (arr[nx] == 0)
				{
					arr[nx] = arr[pop] + 1;
					queue[rear] = nx;
					rear++;
				}
				continue ;
			}
			nx = pop + dx[i];
			if (nx < 0 || nx > 100000)
				continue ;
//			if (arr[nx] != 0 && arr[pop] + 1 < arr[nx])
//			{ 
//				printf("hi");
//				arr[nx] = arr[pop] + 1;
//				queue[rear] = nx;
//				rear++;
//			}
			if (arr[nx] == 0)
			{
				arr[nx] = arr[pop] + 1;
				queue[rear] = nx;
				rear++;
			}
		}
	}
}
