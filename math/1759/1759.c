#include <stdio.h>

void	back_trac(char str[], char arr[], int l, int move, int c);

int main()
{
	int l,c;
	scanf("%d %d", &l, &c);
	char str[16];
	char arr[l + 1];
	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &str[i]);
	}
	char temp;

	for (int i = 0; i < c - 1; i++)
	{
		for (int j = i; j < c; j++)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	back_trac(str, arr, l, 0, c);
}

void	back_trac(char str[], char arr[], int l, int move, int c)
{
	if (move == l)
	{
		int cnt = 0;
		for (int i = 0; i < l; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				cnt++;
		}
		if (cnt == 0 || l - cnt < 2)
			return ;
		for (int i = 0; i < l; i++)
		{
			printf("%c", arr[i]);
		}
		printf("\n");
		return ;
	}

	for (int i = 0; i < c; i++)
	{
		arr[move] = str[i];
		if (move != 0)
		{
			if (arr[move - 1] < arr[move])
				back_trac(str, arr, l, move + 1, c);
		}
		else
			back_trac(str, arr, l, move + 1, c);
	}

}
