#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int arr[m][n];
	for (int i = 0; i < m; i++) // n width, m height
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
//	for (int i = 0; i < m; i++) // n width, m height
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
	
	
}
