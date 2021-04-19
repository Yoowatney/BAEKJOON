#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);

	int div, mod;
	int temp;
	int mod_temp;
	int cnt = 1;

	div = num / 10;
	mod = num % 10;
	mod_temp = (div + mod) % 10;
	temp = mod * 10 + mod_temp;
	while (num != temp)
	{
		div = temp / 10;
		mod = temp % 10;
		mod_temp = (div + mod) % 10;
		temp = mod * 10 + mod_temp;
		cnt++;
	}
	printf("ans : %d\n", cnt);
}
