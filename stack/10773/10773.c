#include <stdio.h>

int arr[100000];

int main()
{
	int K;
	int num;
	int move = 0;
	int cnt = 0;

	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d",&num); 
		if (num != 0)
		{
			arr[move - cnt] = num;
			move++;
		}
		else
		{
			cnt++;
			arr[move - cnt] = 0;
		}
	}
	int result = 0;

	for (int i = 0; i < K; i++)
		result += arr[i];
	printf("%d\n", result);
}
