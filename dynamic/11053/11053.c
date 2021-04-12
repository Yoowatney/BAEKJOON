#include <stdio.h>

int main()
{
	int size;

	scanf("%d", &size);
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (size == 1)
	{
		printf("%d\n", arr[0]);
		return (0);
	}
	int min;
	int cnt;
	int max = 0;

	for (int i = 0; i < size - 1; i++)
	{
		min = arr[i];
		cnt = 1;
		for (int j = i + 1; j < size; j++)
		{
			if (j == size - 1)
			{
				if (min < arr[j])
				{
					cnt++;
					break ;
				}
			}
			if (min < arr[j])
			{
			   for (int k = j + 1; k < size; k++)
			   {
				   if (arr[j] < arr[k])
				   {
					   cnt++;
					   min = arr[j];
					   break ;
				   }
				   if (arr[j] > arr[k] && arr[k] > min) // 10 20 15
				   {
					   min = arr[k];
					   cnt++;
					   j = k;
					   break ;
				   }
//				   if (min > arr[k])
//				   {
//					   cnt++;
//				   }
				   if (arr[k] < min)
				   {
					   cnt++;
				   }
			   }
			}
		}
		if (max < cnt)	
			max = cnt;
	}
	printf("%d\n", max);
}
