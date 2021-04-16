#include <stdio.h>

int main()
{
	int d, k;
	scanf("%d %d", &d, &k);
	int arr_one[31] = {0, };
	int arr_two[31] = {0, };
	arr_one[1] = 1;
	arr_two[2] = 1;
	for (int i = 3; i < 31; i++)
	{
		arr_one[i] = arr_one[i - 1] + arr_one[i - 2];
		arr_two[i] = arr_two[i - 1] + arr_two[i - 2];
	}
	
//	for (int i = 3; i < 30; i++)
//	{
//		printf("%d %d\n", arr_one[i], arr_two[i]);
//	}
	// k = arr_one[d] * x + arr_two[d] * y 를 만족하는 최소해
	for (int i = 1; k - arr_one[d] * i > 0; i++)
	{
		if ((k - arr_one[d] * i) % arr_two[d] == 0)
		{
			printf("%d\n%d",i, (k- arr_one[d] * i) / arr_two[d]);
			return (0);
		}
	}

}
