#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str1[1001];
	char str2[1001];
	int dp[1001] = {0,};

	scanf("%s", str1);
	scanf("%s", str2);

//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	exit(1);
	int move = 0;
	int cnt = 0;
	for (long i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[move] && str2[move] != '\0')
		{
			printf("ㅎㅇ i : %ld\n\n", i);
			move++;
			i--;
			continue ;
		}
		move++;
		cnt++;
		for (int j = i + 1; str1[j] != '\0'; j++)
		{
			if (str1[j] == str2[move] && str1[j] != '\0')
			{
				
//				printf("str1[i] : %c, cnt++, str1 : %c\n", str1[i], str1[j]);
//				printf("size 비교 :str1[j] : %c, str2[move] : %c\n",str1[j], str2[move]);
				move++;
				cnt++;
				continue ;
			}
			if (move == strlen(str1))
			{
				
			}
			{
				printf("move : %d\n", move);
				j--;
				move++;
				continue ;
			}
		}
		dp[i] = cnt;
		printf("%d ", cnt);
		cnt = 0;
		move = 0;
	}
}
