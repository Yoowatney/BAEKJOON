#include <stdio.h>

int		arr[10000];
int		move;
int		cnt;
int		removed[10000];


void	push(int num)
{
	arr[move] = num;
	move++;
	cnt++;
}

int		top()
{
	for (int i = move - 1; i >= 0; i--)
	{
		if (arr[i] != 0 && !removed[i])
		{
			return (arr[i]);
		}
	}
	return (-1);
}

int		pop()
{
	for (int i = move - 1; i >= 0; i--)
	{
		if (arr[i] != 0 && !removed[i])
		{
			removed[i] = 1;
			cnt--;
			return (arr[i]);
		}
	}
	return (-1);
}

int		size()
{
	return (cnt);
}

int		empty()
{
	for (int i = move - 1; i >= 0; i--)
	{
		if (!removed[i])
			return (0);
	}
	return (1);
}

int main()
{
	int N;
	int num;
	
	scanf("%d", &N);
	char s[10];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		if (s[0] == 'p' && s[1] == 'u')
		{
			scanf("%d", &num);
			push(num);
		}
		else if (s[0] == 'p' && s[1] == 'o')
		{
			printf("%d\n", pop());
		}
		else if (s[0] == 's')
		{
			printf("%d\n", size());
		}
		else if (s[0] == 'e')
		{
			printf("%d\n", empty());
		}
		else
		{
			printf("%d\n", top());
		}
	}
}
