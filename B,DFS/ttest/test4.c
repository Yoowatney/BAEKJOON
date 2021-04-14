#include<stdio.h>
#define SIZE 8
int map[SIZE + 1][SIZE + 1] =
{
	{0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,1,0,1,1,0,0,0,0},
	{0,0,1,0,0,0,0,1,0},
	{0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,0,1,0,0},
	{0,0,0,0,0,1,0,1,1},
	{0,0,0,1,0,0,1,0,1},
	{0,0,0,0,0,0,1,1,0}
};
int visited[SIZE + 1];
void DFS(int v)
{
	visited[v] = 1;
	for (int j = 1; j < SIZE + 1; j++)
	{
		if (map[v][j] == 1 && !visited[j])
		{
			printf("%d->%d로 이동\n", v, j);
			DFS(j);
		}
	}
}
int main()
	{

	for (int v = 1; v <= SIZE; v++)
	{
		printf("\nSTART VERTEX %d =======\n",v);
		for (int j = 1; j <= SIZE; j++) 
		{
			visited[j] = 0;
		}
		DFS(v);
	}
	printf("\n");
	return 0;
}
