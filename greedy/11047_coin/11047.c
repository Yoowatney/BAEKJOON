#include <stdio.h>

int	main()
{
	int size, money;
	int result = 0;
	
	scanf("%d %d", &size, &money);
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = size - 1; i >= 0 && money; i--)
	{
		result += money / arr[i];
		money %= arr[i];
//		if (money / arr[i] != 0)
//		{
//			result += money / arr[i];
//			money = money % (arr[i] * (money / arr[i]));
//		//	printf("money : %d\n", money);
//		}
	}
	printf("%d\n", result);
}
