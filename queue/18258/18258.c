#include <stdio.h>

int		arr[2000000];
int		move;
int		cnt;
int		start;

void	push(int num)
{
	arr[move] = num;
	move++;
	cnt++;
}

int		front()
{
	if (start <= move - 1)
	{
		return (arr[start]);
	}
	return (-1);
}

int		back()
{
	if (start <= move - 1)
	{
		return (arr[move - 1]);
	}
	return (-1);
}


int		pop()
{
	if (start <= move - 1)
	{
		cnt--;
		return (arr[start++]);
	}
	return (-1);
}

int		size()
{
	return (cnt);
}

int		empty()
{
	if (cnt)
		return (0);
	else
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
		else if (s[0] == 'f')
		{
			printf("%d\n", front());
		}
		else
		{
			printf("%d\n", back());
		}
	}
}
