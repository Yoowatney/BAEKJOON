#include <stdio.h>
#include <string.h>

int cnt;
void	DFS(int N, int arr[][N], int visited[][N], int under, int right, int dp[][N]);
int main()
{
	int N;
	scanf("%d", &N);
	int arr[N][N];
	int visited[N][N];
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	DFS(N, arr, visited, 0, 0, dp);
	printf("%d", dp[N - 1][N - 1]);
	printf("-- ans --\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("cnt : %d", cnt);
}


void	DFS(int N, int arr[][N], int visited[][N], int under, int right, int dp[][N])
{
	if (right >= N || under >= N)// || under + arr[under][right] >= N || right + arr[under][right] >= N)
		return ;
	if (right == N - 1 && under == N - 1)
	{
		cnt++;
		return ;
	}
	if (under + arr[under][right] < N)
	{
		dp[under + arr[under][right]][right]++;
	}
	if (right + arr[under][right] < N)
	{
		dp[under][right + arr[under][right]]++;
	}
//	printf("-- dp --\n");
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
//	printf("under : %d, right : %d\n",under, right);
//	if (!visited[under][right])
//		visited[under][right] = 1;
	DFS(N, arr, visited, under + arr[under][right], right, dp);
	DFS(N, arr, visited, under, right + arr[under][right], dp);
	return ;
}
