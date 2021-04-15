#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}
int main()
{
	char str1[1002];
	char str2[1002];

	str1[0] = '0';
	str2[0] = '0';
	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);
	int	width = strlen(str1);
	int height = strlen(str2);
	int arr[height][width];

	memset(arr, 0 ,sizeof(arr));
	for (int i = 1; str2[i] != '\0'; i++)
	{
		for (int j = 1; str1[j] != '\0'; j++)
		{
		   	if (str2[i] == str1[j])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j],  arr[i][j - 1]);
			}
		}
	}
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d", arr[height - 1][width - 1]);
}
