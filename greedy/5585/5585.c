#include <stdio.h>


int	main()
{
	int money;
	int result;

	scanf("%d", &money);
	result = 0;
	money = 1000 - money;
	
//	printf("처음 : %d\n", money);
	result += money / 500;
	money = money % 500;
//	printf("%d\n", result);
	
//	printf("100 들어가기전 : %d\n", money);
	result += money / 100;
	money %= 100;

//	printf("%d\n", result);
//	printf("50 들어가기전 : %d\n", money);
	result += money / 50;
	money %= 50;

//	printf("%d\n", result);
//	printf("10 들어가기전 : %d\n", money);
	result += money / 10;
	money %= 10;

//	printf("5 들어가기전 : %d\n", money);
	result += money / 5;
	money %= 5;

//	printf("1 들어가기전 : %d\n", money);
	result += money / 1;
	money %= 1;
	printf("%d\n", result);
}
