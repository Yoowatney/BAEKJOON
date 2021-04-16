#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	char str[51];
	int sign = 1;
	for (int i = 0; i < T; i++)
	{
		scanf("%s", str);
		int cnt1 = 0;
		int cnt2 = 0;
		
		sign = 1;
		for (int j = 0;	str[j] != '\0'; j++)
		{
			if (str[j] == '(')
				cnt1++;
			else
				cnt2++;
			if (cnt1 < cnt2)
			{
				printf("NO\n");
				sign = 0;
				break ;
			}
		}
		if (sign)
		{
			if (cnt1 == cnt2)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}
