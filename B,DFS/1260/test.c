#include <stdio.h>
#include <string.h>

void	BFS(int n, int m, int arr[][n + 1], int queue[], int v, int visited[]);


void	DFS(int n, int m, int arr[][n + 1], int visited[], int here)
{
	visited[here] = 1;
	printf("%d ", here);
	for (int i = 1; i < n + 1; i++)
	{
		if (arr[here][i] != 0 && !visited[i])
		{
			DFS(n, m, arr, visited, i);
		}
	}
}
int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	int arr[n + 1][n + 1];
	memset(arr, 0 , sizeof(arr));
	int row, col;
	int visited[n + 1];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &row, &col);
		arr[row][col] = 1;
		arr[col][row] = 1;
	}
	int queue[n + 1];
	memset(queue, 0, sizeof(queue));
	DFS(n, m, arr, visited, v);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	BFS(n, m, arr, queue, v, visited);
}

void	BFS(int n, int m, int arr[][n + 1], int queue[], int v, int visited[])
{
	int front = 0;
	int rear = 0;
	int pop;

	queue[rear] = v;
	rear++;
	while (front < rear)
	{
		pop = queue[front];
		printf("%d ", pop);
		visited[pop] = 1;
		front++;
		for (int i = 1; i < n + 1; i++)
		{
			if (arr[pop][i] != 0 && !visited[i])
			{
				queue[rear] = i;
				rear++;
				visited[i] = 1;
			}
		}
	}
}
