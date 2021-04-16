#include <stdio.h>
#include <string.h>

char	*rev(char T[], int len_t);

int main()
{
	char S[1000];
	scanf("%s", S);
	char T[1001];
	scanf("%s", T);
	int len_s = strlen(S);
	int len_t = strlen(T);
	
	int len = len_t - len_s;
//	printf("len : %d\n", len);
	for (int i = 0; i < len + 1; i++)
	{
		if (strcmp(S, T) == 0)
		{
			printf("1");
			return (0);
		}
		if (T[len_t - 1] == 'A')
		{
			T[len_t - 1] = '\0';
			len_t--;
//			printf(" 1 : %s\n", T);
		}
		else if (T[len_t - 1] == 'B')
		{
			T[len_t - 1] = '\0';
			len_t--;
//			printf(" 2 : %s\n", T);
			rev(T, len_t);
		}
	}
	printf("0");
}

char	*rev(char T[], int len_t)
{
	char temp;
	int	 end = len_t - 1;
	for (int i = 0; i < len_t / 2; i++)
	{
		temp = T[i];
	//	printf("temp : %c\n", temp);
		T[i] = T[end];
	//	printf("T[end] : %c\n", temp);
		T[end] = temp;
		end--;
	}
//	printf("\n rev -> %s \n", T);
	return (T);
}
