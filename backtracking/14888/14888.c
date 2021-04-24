#include <stdio.h>
#include <string.h>

int max = -1000000001;
int min = 1000000001;

void	back(int n, int arr[n], int index, char operator[n], int plus, int minus, int multi, int div);
void	calculate(int n, int arr[], char operator[]);

int main()
{
	int n;

	scanf("%d", &n);
	int arr[n];
	memset(arr, 0, sizeof(arr));
	char operator[n];
	int calc[4];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int plus, minus, multi, div;
	scanf("%d", &plus);
	scanf("%d", &minus);
	scanf("%d", &multi);
	scanf("%d", &div);
	back(n, arr, 0, operator, plus, minus, multi, div);
	printf("%d\n%d", max, min);
}

void	back(int n, int arr[n], int index, char operator[n], int plus, int minus, int multi, int div)
{
	if (index == n - 1)
	{
		calculate(n, arr, operator);
		return ;
	}
	char calc[5] = "+-*%";
	for (int j = 0; j < 4; j++)
	{
		if (plus > 0 && j == 0)
		{
			operator[index] = calc[j];
			back(n, arr, index + 1, operator, plus - 1, minus, multi, div);
		}
		if (minus > 0 && j == 1)
		{
			operator[index] = calc[j];
			back(n, arr, index + 1, operator, plus, minus - 1, multi, div);
		}
		if (multi > 0 && j == 2)
		{
			operator[index] = calc[j];
			back(n, arr, index + 1, operator, plus, minus, multi - 1, div);
		}
		if (div > 0 && j == 3)
		{
			operator[index] = calc[j];
			back(n, arr, index + 1, operator, plus, minus, multi, div - 1);
		}
	}
}

void	calculate(int n, int arr[n], char operator[n])
{
	int ret = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (operator[i - 1] == '+')
			ret += arr[i];
		else if (operator[i - 1] == '-')
			ret -= arr[i];
		else if (operator[i - 1] == '*')
			ret *= arr[i];
		else
			ret = ret / arr[i];
	}
	if (ret > 1000000000)
		return ;
	if (ret < -1000000000)
		return ;
	max = max < ret ? ret : max; 
	min = min > ret ? ret : min;
	return ;
}
